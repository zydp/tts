#ifndef G3P2P_SERVER_COMM_H
#define G3P2P_SERVER_COMM_H
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>
#include "macrodefine.h"
#include "win32_types.h"
#ifdef _MSC_VER
#pragma warning(disable:4251)
#pragma warning(disable:4996)
#endif
//namespace
#define G3P2P_SERVERCOMM_BEGIN namespace G3P2P_BY_LONGYU_SERVERCOMM {
#define G3P2P_SERVERCOMM_END   }

G3P2P_BEGIN
	G3P2P_SERVERCOMM_BEGIN


//���������
#define MESSAGE_LENGTH 256 


class G3P2P_API CMainServerBase
{
public:
	CMainServerBase();	
	~CMainServerBase();

	void CommandProcess();	
	void PrintfConMessage(const char *pFormat,...);
	//��Linux��Demoģʽ���У��ȴ�Kill����
#ifndef WIN32
	void waitForTerminationRequest();
#endif

private:
	void PrintfMessage(char * szmsg);
public:
	virtual BOOL StartService()	 = 0;
	virtual BOOL StopService()	=0;
	virtual BOOL InitServer() = 0;
	virtual void FInitServer() = 0;
	virtual void DisplayServerInfo() = 0;
	virtual void WaitForAllThreadExit() = 0;
	virtual void OnServiceStartReturn(BOOL bSuccess);
	//��������
public:
	std::string m_strServerName; //����������
	std::string m_strCopyRight; //��Ȩ��Ϣ
	std::string m_strServerVerion;//�������汾��
	std::string m_strServerFunction; //�������Ĺ���
	std::string m_strServerFunctionDecript;//����������
	//��־��Ϣ
	std::string m_strLogFilePath; //��־�Ļ���·��
	int m_nWriteErrorLogRank;     //������־����
	int m_nCommonLogRank;         //������־����
	int m_nOutputLogRank;         //��Ļ��ӡ��־����
	//��־��������Ϣ
	std::string m_RomoteLogServerIP; //�첽��־��������ַ
	unsigned short m_RomoteLogServerPort;//�첽��־�������˿�
	int m_nRomoteLogRank;               //�첽��־����
	//ϵͳ���ܲ���
	int m_nCpuCount;                     //���߳�����CPU��
	bool m_bSignCompress;                //�����Ƿ�ѹ��
};

//void sig_quit(int sig);

	G3P2P_SERVERCOMM_END
G3P2P_END

//main �����궨��
#ifndef WIN32
#define  G3P2P_MAINSERVER(MainServer) \
void sig_quit(int sig);\
int main(int argc, char** argv)\
{\
	if(argc>1&&strcmp(argv[1],"-s")==0)\
	{\
		if(daemon(1,1) < 0)\
		{\
			std::cout<<"Failed to switch to daemon mode!!!!"<<std::endl;\
			return (EXIT_FAILURE);\
		}\
	}\
	else\
	{\
		signal(SIGHUP, SIG_IGN);\
		signal(SIGQUIT, SIG_IGN);\
		signal(SIGPIPE, SIG_IGN);\
		signal(SIGINT, sig_quit);\
		signal(SIGTERM, sig_quit);\
	}\
	BOOL bStartFail = FALSE;\
	if(!MainServer.InitServer())\
	{\
		std::cout<<"service init ... [FAILE]"<<std::endl;\
		bStartFail = TRUE;\
	}\
	MainServer.DisplayServerInfo();\
	if(!bStartFail)\
	{\
		if(!MainServer.StartService())\
		{\
			std::cout<<"service start ... [FAILE]"<<std::endl;\
			bStartFail = TRUE;\
			MainServer.OnServiceStartReturn(FALSE);\
		}\
	}\
	if(!bStartFail)\
	{\
		std::cout<<"nservice start ... [OK]"<<std::endl;\
		if(argc>1&&strcmp(argv[1],"-s")==0)\
		{\
			MainServer.OnServiceStartReturn(TRUE);\
			MainServer.waitForTerminationRequest();\
		}\
		else\
		{\
			MainServer.OnServiceStartReturn(TRUE);\
			MainServer.CommandProcess();\
		}\
	}\
	MainServer.StopService();\
	MainServer.WaitForAllThreadExit();\
	MainServer.FInitServer();\
	return 0;\
}\
void sig_quit(int sig)\
{\
	MainServer.StopService();\
	MainServer.WaitForAllThreadExit();\
	MainServer.FInitServer();	\
}

#else

#define  G3P2P_MAINSERVER(MainServer) \
int main(int argc, char** argv)\
{\
	BOOL bStartFail = FALSE;\
	if(!MainServer.InitServer())\
	{\
		std::cout<<"Service init ... [FAILE]"<<std::endl;\
		bStartFail = TRUE;\
	}\
	MainServer.DisplayServerInfo();\
	if(!bStartFail)\
	{\
		if(!MainServer.StartService())\
		{\
			std::cout<<"Service start ... [FAILE]"<<std::endl;\
			bStartFail = TRUE;\
			MainServer.OnServiceStartReturn(FALSE);\
		}\
	}\
	if(!bStartFail)\
	{\
		std::cout<<"Service start ... [OK]"<<std::endl;\
		MainServer.OnServiceStartReturn(TRUE);\
		MainServer.CommandProcess();\
	}\
	MainServer.StopService();\
	MainServer.WaitForAllThreadExit();\
	MainServer.FInitServer();\
	return 0;\
}\
void sig_quit(int sig)\
{\
	MainServer.StopService();\
	MainServer.WaitForAllThreadExit();\
	MainServer.FInitServer();	\
}\


#endif



#endif
