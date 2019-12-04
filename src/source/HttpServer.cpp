#include "Speaker.h"
#include "HttpServer.h"
#include "wordencoding.h"
#include "jsoncpp/json.h"
#include "MainServer.h"
#include <objbase.h>	//guid

HttpServer::HttpServer(const int port, const int maxWorker) {
	std::vector<std::string> cpp_options;
	cpp_options.push_back("document_root");
	cpp_options.push_back(".");
	cpp_options.push_back("listening_ports");
	cpp_options.push_back(to_string(port));
	cpp_options.push_back("num_threads");
	cpp_options.push_back(to_string(maxWorker));
	m_ServerHandle_ = new CivetServer(cpp_options);
}

HttpServer::~HttpServer() {
	if (NULL != m_ServerHandle_) {
		delete m_ServerHandle_;
	}
}


void HttpServer::RouteHandle(const string& path, CivetHandler* handle) {
	m_ServerHandle_->addHandler(path.c_str(), handle);
}

void HttpServer::StopService() {
	if (m_ServerHandle_) {
		m_ServerHandle_->close();
	}
}


bool CommonHandler::handlePost(CivetServer* ServerHandle, struct mg_connection *ClientHandle) {
	//std::cout << "Thread:" << std::this_thread::get_id() << endl;
	static string filepath = CMainServer::GetMainServer()->m_strFilePath;
	static string fileNamePrefix = CMainServer::GetMainServer()->m_strFileNamePrefix;
	static string fileServerUrl = CMainServer::GetMainServer()->m_strFileServerUrl;
	const struct mg_request_info *req_info = mg_get_request_info(ClientHandle);
	long long content_len = req_info->content_length;
	char* body = new char[content_len + 1];
	memset(body, 0, content_len + 1);
	Json::Value reqMsg, respMsg;
	Json::Reader jsonParse;

	try {

		if (content_len >= MAX_CONTENT_LENGTH) {
			PROCESS_ARGS_LOG(MODULE_LOG_TAG, LINFO, "request body is too loooooooooooooong. content-len=%d", content_len);
			throw Json::Exception(",body is too loooooooong.");
		}
		long long nlen = 0;
		long long rlen;
		while (nlen < content_len) {
			rlen = mg_read(ClientHandle, body, (size_t)rlen);
			if (rlen <= 0) {
				break;
			}
			nlen += rlen;
		}

		if (!jsonParse.parse(body, reqMsg)) {
			throw Json::Exception(",format nonstandard");
		}
		if (!reqMsg.isMember("text")) {
			throw Json::Exception("field text is required");
		}

		delete[]body;
		body = NULL;
		string speaktext = reqMsg["text"].asString();

		static Speaker speaker;
		//speaker.CheckInitStaus();
		static bool ret = speaker.VoicePrepare();

		string baseFileName = speaker.SetOutput(filepath, fileNamePrefix);
		if (baseFileName.empty()) {
			throw Json::Exception("file created failed");
		}
		wchar_t *buffer = new wchar_t[content_len + 1];
		UTF82GBK_w(speaktext.c_str(), buffer, content_len);


		string fullFileName = filepath + "/" + baseFileName;

		if (!speaker.Speak(buffer, SpeechVoiceSpeakFlags(SPF_IS_NOT_XML | SPF_ASYNC | SPF_PURGEBEFORESPEAK))) {
			PROCESS_LOG(MODULE_LOG_TAG, LINFO, "Speak failed.");
			delete[]buffer;
			buffer = NULL;
			throw std::exception("convert to voice failed");
		}
		delete[]buffer;
		buffer = NULL;

		if (audio2aac((fullFileName + ".wav").c_str(), (fullFileName + ".mp4").c_str()) == 0) {
			std::remove((fullFileName + ".wav").c_str());
		}
		respMsg["code"] = "200";
		respMsg["Message"] = "sucess";
		respMsg["fileurl"] = fileServerUrl + "?filename=" + baseFileName + ".mp4";
	}
	catch (Json::Exception& err) {
		delete[]body;
		body = NULL;
		respMsg["code"] = ERROR_CODE_BUSINESS_COMMON_ERROR_PARAMETER;
		string exceptionStr = err.what();
		respMsg["message"] = ErrorHelper::GetErrorMessage(ERROR_CODE_BUSINESS_COMMON_ERROR_PARAMETER) + string(" ") + exceptionStr;
	}
	catch (std::exception& err) {
		respMsg["code"] = -500;
		respMsg["message"] = err.what();
	}
	string reStr = respMsg.toStyledString();

	mg_printf(ClientHandle, "HTTP/1.1 200 OK\r\nContent-Type: "
		"text/html\r\nConnection: close\r\n\r\n");
	return mg_write(ClientHandle, reStr.c_str(), reStr.length()) >0;
}