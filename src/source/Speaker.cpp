#include "Speaker.h"
#include "PapereaderGlobalDef.h"



Speaker::Speaker() {
	isInit_ = false;
	oldStream_ = NULL;
	initContent();
}

Speaker::~Speaker() {
	deInitContent();
}

void Speaker::CheckInitStaus() {
	if (!isInit_) {
		initContent();
	}
}

bool Speaker::VoicePrepare() {
	HRESULT hr = m_tts_.CoCreateInstance(CLSID_SpVoice);
	if (FAILED(hr))
	{
		PROCESS_LOG(MODULE_LOG_TAG, LINFO, "Text-to-speech creation failed.\n");
		return false;
	}
	hr = SpGetDefaultTokenFromCategoryId(SPCAT_VOICES, &m_voiceToken_, FALSE);
	if (FAILED(hr))
	{
		PROCESS_LOG(MODULE_LOG_TAG, LINFO, "Can't get default voice token.\n");
		return false;
	}
	hr = m_tts_->SetVoice(m_voiceToken_);
	if (FAILED(hr))
	{
		PROCESS_LOG(MODULE_LOG_TAG, LINFO, "Can't set default voice.\n");
		return false;
	}
	return true;
}

string Speaker::SetOutput(const string& filepath, const string& fileNamePrefix) {
	
	CComPtr<ISpStream> cpISpStream;
	CComPtr<ISpStreamFormat> oldStream;
	CComPtr<ISpStreamFormat> cpISpStreamFormat;
	CSpStreamFormat spStreamFormat;
	m_tts_->GetOutputStream(&cpISpStreamFormat);
	
	spStreamFormat.AssignFormat(cpISpStreamFormat);
	const WAVEFORMATEX* format = spStreamFormat.WaveFormatExPtr();
	//time_t now = time(NULL);
	//char strtime[48] = {0};
	//struct tm s_tm;
	//localtime_s(&s_tm, &now);
	//sprintf_s(strtime, "%04d-%02d-%02d_%02d-%02d-%02d.wav",
	//	s_tm.tm_year + 1900, s_tm.tm_mon + 1, s_tm.tm_mday,
	//	s_tm.tm_hour, s_tm.tm_min, s_tm.tm_sec
	//);

	char strguid[64] = { 0 };
	GUID guid;
	CoCreateGuid(&guid);//for windows
	sprintf_s(strguid, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x", guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1],
		guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]
	);
	HRESULT hResult = SPBindToFile(
		(filepath + "/" + fileNamePrefix + strguid + ".wav").c_str(),
		SPFM_CREATE_ALWAYS,
		&cpISpStream,
		&spStreamFormat.FormatId(),
		spStreamFormat.WaveFormatExPtr()
	);
	hResult = m_tts_->GetOutputStream(&oldStream);
	oldStream_ = oldStream;
	if (SUCCEEDED(hResult)) {
		m_tts_->SetOutput(cpISpStream, TRUE);
	}
	else {
		PROCESS_LOG(MODULE_LOG_TAG, LINFO, "can't set output, because the GetOutputStream failed");
		return "";
	}
	return fileNamePrefix + strguid;
}


bool Speaker::Speak(WCHAR* text, SpeechVoiceSpeakFlags Flags, unsigned long *StreamNumber) {
	HRESULT ret = m_tts_->Speak(text, Flags, StreamNumber);
	m_tts_->WaitUntilDone(INFINITE);
	m_tts_->SetOutput(oldStream_, TRUE);
	return ret == S_OK;
}


bool Speaker::initContent() {
	HRESULT hr = ::CoInitialize(NULL);
	if (FAILED(hr))
	{
		PROCESS_ARGS_LOG(MODULE_LOG_TAG, LERROR, "CoInitialize() failed in SpeakerContentInit constructor %d.\n", hr);
		return false;
	}
	isInit_ = true;
	return true;
}



void Speaker::deInitContent() {
	::CoUninitialize();
	isInit_ = false;
}

