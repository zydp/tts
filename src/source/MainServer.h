#ifndef _MAIN_SERVER_H_
#define _MAIN_SERVER_H_
#include "PapereaderGlobalDef.h"
#include "HttpServer.h"

class CMainServer :public CMainServerBase
{
public:
	CMainServer(void);
	~CMainServer(void);
public:
	virtual BOOL InitServer();
	virtual BOOL StartService();
	virtual BOOL StopService();
	virtual void FInitServer();
	virtual void DisplayServerInfo();
	virtual void WaitForAllThreadExit();

public:
	static CMainServer*	GetMainServer();
	string GetVersionInfo();
private:
	static CMainServer * m_pMainServer;			//全局句柄
	HttpServer* m_pHttpServerHandle_;
private:
	BOOL LoadConfigFromFile(std::string strConfigFile);

public:
	std::string		m_strFilePath;			//文件保存路径
	std::string		m_strFileNamePrefix;	//文件名前缀
	std::string		m_strFileServerUrl;		//文件服务器地址

private:
	//读取配置文件
	CIniFile m_IniFile;						//配置文件句柄

	//配置信息
	std::string		m_strDomain;
	std::string		m_strLimitVerion;		//协议的最低版本
	std::string		m_strListenIp;			//本地监听IP
	unsigned short	m_nListenPort;			//本地TCP监听端口
	std::string		m_strAPIPath;			//api path
	unsigned short	m_nMaxTcpConn;			//max tcp conn
	int				m_workThreadCount;      //工作线程数

};
#endif
