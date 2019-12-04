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
	static CMainServer * m_pMainServer;			//ȫ�־��
	HttpServer* m_pHttpServerHandle_;
private:
	BOOL LoadConfigFromFile(std::string strConfigFile);

public:
	std::string		m_strFilePath;			//�ļ�����·��
	std::string		m_strFileNamePrefix;	//�ļ���ǰ׺
	std::string		m_strFileServerUrl;		//�ļ���������ַ

private:
	//��ȡ�����ļ�
	CIniFile m_IniFile;						//�����ļ����

	//������Ϣ
	std::string		m_strDomain;
	std::string		m_strLimitVerion;		//Э�����Ͱ汾
	std::string		m_strListenIp;			//���ؼ���IP
	unsigned short	m_nListenPort;			//����TCP�����˿�
	std::string		m_strAPIPath;			//api path
	unsigned short	m_nMaxTcpConn;			//max tcp conn
	int				m_workThreadCount;      //�����߳���

};
#endif
