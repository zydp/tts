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


//服务基本类
#define MESSAGE_LENGTH 256 


class G3P2P_API CMainServerBase
{
public:
	CMainServerBase();	
	~CMainServerBase();

	void CommandProcess();	
	void PrintfConMessage(const char *pFormat,...);
	//在Linux下Demo模式运行，等待Kill结束
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
	//基本属性
public:
	std::string m_strServerName; //服务器名称
	std::string m_strCopyRight; //版权信息
	std::string m_strServerVerion;//服务器版本号
	std::string m_strServerFunction; //服务器的功能
	std::string m_strServerFunctionDecript;//服务功能描述
	//日志信息
	std::string m_strLogFilePath; //日志的基本路径
	int m_nWriteErrorLogRank;     //错误日志级别
	int m_nCommonLogRank;         //常规日志级别
	int m_nOutputLogRank;         //屏幕打印日志级别
	//日志服务器信息
	std::string m_RomoteLogServerIP; //异步日志服务器地址
	unsigned short m_RomoteLogServerPort;//异步日志服务器端口
	int m_nRomoteLogRank;               //异步日志级别
	//系统性能参数
	int m_nCpuCount;                     //主线程数，CPU数
	bool m_bSignCompress;                //信令是否压缩
};

//void sig_quit(int sig);

	G3P2P_SERVERCOMM_END
G3P2P_END

//main 函数宏定义
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
