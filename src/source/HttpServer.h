#ifndef _HTTP_SERVER_H_
#define _HTTP_SERVER_H_
#include <atomic>
#include "PapereaderGlobalDef.h"
#include "VoiceConvert.h"
#include "CivetServer.h"


#define MAX_CONTENT_LENGTH 32768	/*4096*8*/

class CommonHandler:public CivetHandler
{
public:
	/*暂时仅提供POST支持,转线程。。。 */
	bool handlePost(CivetServer *m_ServerHandle_, struct mg_connection *m_ClientHandle_);
};


class HttpServer {
public:
	HttpServer(const int port, const int maxWorker);
	~HttpServer();
public:
	void RouteHandle(const string& path, CivetHandler* handle);
	void StopService();
private:
	CivetServer* m_ServerHandle_;
	std::vector<CommonHandler*> m_AllWorkerhandle_;
	int m_port_;
};


#endif