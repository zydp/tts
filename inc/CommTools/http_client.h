#ifndef __HTTP_CLIENT_H_
#define __HTTP_CLIENT_H_
#include <curl/curl.h>
#include <iostream>
#include "CommToolsExportDef.h"
typedef enum {
	HTTP_GET,
	HTTP_PUT,
	HTTP_POST,
	HTTP_DEL
}METHODS;

class COMM_TOOLS_API http_client
{
public:
	http_client(void);
	~http_client(void);
public:
	int Request(METHODS methods, const std::string url, std::string& resp, const std::string& body = "", const int timeout = 3);
	const char* GetErrInfo(int errcode);
	const double GetExpendTime();	/* unit: s */
private:
	void PerfectReqOpt(const std::string& url, const int timeout);
	int DialServer(METHODS methods, std::string& resp, const std::string& body);
private:
	 CURL* m_pCurl;
};

#endif