#include "Speaker.h"
#include "MainServer.h" 
#include "CommToolsVersion.h"
#include "PapereaderVersion.h"

CMainServer*  CMainServer::m_pMainServer = NULL;


string CMainServer::GetVersionInfo()
{
	ostringstream os;
	os << m_strServerName << std::endl;
	os << "MessageServer Version:" << PapereaderVersionString() << std::endl;
	os << "CommTools     Version:" << CommToolsVersionString() << std::endl;
	os << m_strCopyRight << std::endl;
	return os.str();
}

CMainServer::CMainServer(void)
{
	m_pMainServer = this;
	m_pHttpServerHandle_ = NULL;
}

CMainServer::~CMainServer(void)
{
	if (NULL != m_pHttpServerHandle_) {
		delete m_pHttpServerHandle_;
	}
}
#define SERVER_CONFIG_FILE	"Papereader.conf"
BOOL CMainServer::InitServer()
{
	if (!LoadConfigFromFile(SERVER_CONFIG_FILE))
	{
		PrintfConMessage("Load config file fail,Please Check !!!");
		getchar();
		return false;
	}
	//log init
	CLogHelper::read_config_init(SERVER_CONFIG_FILE);/* alternative log modules */
	
	ErrorHelper::InitErrorMessage();//ErrorMsg InIt
	
	PROCESS_ARGS_LOG(MODULE_LOG_TAG, LINFO, "ServerInfo:%s", GetVersionInfo().c_str());
	PROCESS_LOG(MODULE_LOG_TAG, LINFO, "Init Server");
	
	return true;
}

BOOL CMainServer::StartService()
{
	try {
		PROCESS_LOG(MODULE_LOG_TAG, LINFO, "Start Http Server");
		m_pHttpServerHandle_ = new HttpServer(m_nListenPort, m_workThreadCount);
		CommonHandler* h = new CommonHandler();
		m_pHttpServerHandle_->RouteHandle(m_strAPIPath, h);
	}
	catch (const std::runtime_error& err) {
		PROCESS_ARGS_LOG(MODULE_LOG_TAG, LERROR, "StartService failed:%s", err.what());
		return false;
	}
	catch (const std::exception& err) {
		PROCESS_ARGS_LOG(MODULE_LOG_TAG, LERROR, "StartService failed:%s", err.what());
		return false;
	}
	return true;
}

BOOL CMainServer::StopService()
{
	PROCESS_LOG(MODULE_LOG_TAG, LINFO, __FUNCTION__);

	PROCESS_LOG(MODULE_LOG_TAG, LINFO, "Stop Http Server");
	if (m_pHttpServerHandle_) {
		m_pHttpServerHandle_->StopService();
	}
	return TRUE;
}

void CMainServer::FInitServer()
{
	PROCESS_LOG(MODULE_LOG_TAG, LINFO, __FUNCTION__);
}

void CMainServer::DisplayServerInfo()
{
	std::cout << GetVersionInfo();
}

void CMainServer::WaitForAllThreadExit()
{
	PROCESS_LOG(MODULE_LOG_TAG, LINFO, __FUNCTION__);
}

CMainServer* CMainServer::GetMainServer()
{
	return m_pMainServer;
}

BOOL CMainServer::LoadConfigFromFile(std::string strConfigFile)
{
	if (strConfigFile.empty())
	{
		PrintfConMessage("Load config file fail, param is null!!!");
		return FALSE;
	}
	if (m_IniFile.LoadFromFile(strConfigFile.c_str()) < 0)
	{
		PrintfConMessage("Load config file fail,Server can't started!!!");
		return FALSE;
	}

	m_strServerName = m_IniFile.GetString("SERVERINFO", "SERVERNAME");
	if (m_strServerName.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "SERVERNAME");
		return FALSE;
	}

	m_strCopyRight = m_IniFile.GetString("SERVERINFO", "COPYRIGHT");
	if (m_strCopyRight.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "COPYRIGHT");
		return false;
	}

	m_strLimitVerion = m_IniFile.GetString("SERVERINFO", "LMTVERSION");
	if (m_strLimitVerion.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "LMTVERSION");
		return FALSE;
	}

	m_strDomain = m_IniFile.GetString("SERVERINFO", "DOMAIN");
	if (m_strLimitVerion.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "DOMAIN");
		return FALSE;
	}

	m_strListenIp = m_IniFile.GetString("SERVERINFO", "LOCALTCPLISTENIP");
	if (m_strListenIp.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "LOCALTCPLISTENIP");
		return FALSE;
	}

	m_nListenPort = (unsigned short)m_IniFile.GetInt("SERVERINFO", "LOCALTCPSIGNPORT");
	if (m_nListenPort <= 0)
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "LOCALTCPSIGNPORT");
		return FALSE;
	}

	m_strAPIPath = m_IniFile.GetString("SERVERINFO", "API_PATH");
	if (m_strAPIPath.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "API_PATH");
		return FALSE;
	}

	m_nMaxTcpConn = m_IniFile.GetInt("SERVERINFO", "MAXTCPCON");
	if (m_nMaxTcpConn <= 0)
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "MAXTCPCON");
		return FALSE;
	}

	m_workThreadCount = m_IniFile.GetInt("SERVERINFO", "WORKER_THREAD_COUNT");
	if (m_workThreadCount <= 0)
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SERVERINFO", "WORKER_THREAD_COUNT");
		return FALSE;
	}
	
	m_strFilePath = m_IniFile.GetString("SPEAKER", "VOICE_FILE_PATH");
	if (m_strFilePath.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SPEAKER", "VOICE_FILE_PATH");
		return FALSE;
	}

	m_strFileNamePrefix = m_IniFile.GetString("SPEAKER", "FILE_NAME_PREFIX");
	if (m_strFileNamePrefix.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SPEAKER", "FILE_NAME_PREFIX");
		return FALSE;
	}

	m_strFileServerUrl = m_IniFile.GetString("SPEAKER", "FILE_SERVER_URL");
	if (m_strFileServerUrl.empty())
	{
		PrintfConMessage("Read the configuration items fail, [%s]->[%s] is empty.", "SPEAKER", "FILE_SERVER_URL");
		return FALSE;
	}
	return TRUE;
}



