#ifndef ERROR_HELPER_H
#define ERROR_HELPER_H
#include <map>
#include <iostream>
#include "CommToolsExportDef.h"
#include "ly_util.h"
using namespace std;
using namespace G3P2P_BY_LONGYU;
using namespace G3P2P_BY_LONGYU::G3P2P_BY_LONGYU_UTIL;
//#include <atomic>
#ifdef WIN32
#pragma warning(disable:4251)
#endif
/*

*/
enum ERROR_CODE
{
	ERROR_CODE_SUCCEED = 0,								/*Ψһ�ɹ���*/
	//ERROR_CODE_PAYLOAD_EMPTY = -16000000,				/*����Э��PayloadΪ��*/
	//ERROR_CODE_UNKNOWN_ACTION = -16000001,				/*�ͻ��˲���Action���ʹ���*/
	//ERROR_CODE_OUT_OF_MEMORY = -16000002,				/*�������ڲ������ڴ����*/
	//ERROR_CODE_CANNOT_CALL_CONFIG_SERVER= -16000003,	/*Զ�����÷��������ܷ���*/
	//ERROR_CODE_CLIENT_IDENTITY_FAILED = -16000004,		/*�û���֤��Ϣ��֤ʧ��*/
	//ERROR_CODE_CLIENT_TOKEN_ISNULL = -16000005,			/*�û���֤TokenΪ��*/
	//ERROR_CODE_CHECK_TOKEN_FAILED = -16000006,			/*�û�Token���ʧ��*/
	//ERROR_CODE_CHECK_BIND_FAILED = -16000007,			/*�û����ϵ���ʧ��*/
	//ERROR_CODE_GET_ONLINEINFO_FAILED = -16000008,		/*��ѯ������Ϣ����*/
	//ERROR_CODE_PUSH_MSG_FAILED = -16000009,				/*������Ϣʧ��*/
	//ERROR_CODE_PARMAS_EMPTY = -16000010,				//ȱ�ٲ���
	//ERROR_CODE_GET_WHITE_LIST_FROM_DB_FAILED = -16000011,//ȱ�ٲ���
	//ERROR_CODE_FIRST_PACKET_TYPE_NOT_AUTH = -16000012,	/*�׸����ݰ���������֤��*/
	//ERROR_CODE_HAS_NO_USABLE_FUNC_SERVER = -16000013,	/*û�п��õĹ��ܷ�����*/
	//ERROR_CODE_MSG_FORWARD_FAILED = -16000014,			/*��Ϣת��ʧ��*/
	//ERROR_CODE_ACCOUNT_OFFSITE_LOGIN = -16000015,		/*�˺���ص�¼*/
	//ERROR_CODE_ACCOUNT_OFFLINE = -16000016,              /*�û�������*/
	ERROR_CODE_NETWORK_PACKET_LENGTH_TOO_LONG = -101000,	    /*���ݰ��ܳ��ȴ��ڻ�������󳤶�*/
	ERROR_CODE_NETWORK_EXTEND_ZERO,								/*�ڶ���Э�����չ��Ϊ��*/
	ERROR_CODE_NETWORK_NONE_USER_DATA,							/*�ڶ���Э����û����ݲ�����*/
	ERROR_CODE_NETWORK_CHECKSUM_FAILED,							/*���ݰ�У��ʧ��*/
	ERROR_CODE_NETWORK_PROTOCOL_FLAG_ERROR,						/*Э���Ǵ���*/
	ERROR_CODE_NETWORK_NONE_SOCKET_HANDLE,						/*Socket���������*/
	ERROR_CODE_BUSINESS_COMMON_ERROR_PARAMETER = -110000,		/*��������*/
	ERROR_CODE_BUSINESS_COMMON_EMPTY_PARAMETER,					/*����Ϊ��*/
	ERROR_CODE_BUSINESS_COMMON_CANNOT_ACCESS_ROMOTE_SERVER,		//�޷�����Զ�˷�����
	ERROR_CODE_BUSINESS_COMMON_OUT_OF_MEMORY,					/*�����ڴ�ʧ��*/
	ERROR_CODE_BUSINESS_COMMON_PAYLOAD_EMPTY,					/*����Э��PayloadΪ��*/
	ERROR_CODE_BUSINESS_COMMON_ERROR_REQUEST_ACTION,			/*�������ʹ���*/
	ERROR_CODE_BUSINESS_COMMON_PUSH_MSG_FAILED,					/*������Ϣʧ��*/
	ERROR_CODE_BUSINESS_COMMON_NULL_POINTER,					/*ָ��Ϊ��*/
	ERROR_CODE_CONFIG_SERVER_NO_AVAILABLE_DATA = -111000,		/*�޿��õ�����*/
	ERROR_CODE_CONFIG_SERVER_CANNOT_GET_DATA ,					/*�޷���ȡ����*/
	ERROR_CODE_CONFIG_SERVER_REGISTER_FAILED,					/*�����÷�����ע��ʧ��*/
	ERROR_CODE_AUTH_SERVER_CLIENT_IDENTITY_FAILED = -114000,	/*�ͻ�����֤��Ϣ��֤ʧ��*/
	ERROR_CODE_AUTH_SERVER_CLIENT_TOKEN_IS_NULL,				/*�û���֤TokenΪ��*/
	ERROR_CODE_AUTH_SERVER_CHECK_TOKEN_FAILED ,					/*�û�Token���ʧ��*/
	ERROR_CODE_USER_NOT_ONLINE,									/*�û���δ����*/
	ERROR_CODE_USER_ALREADY_ONLINE,								/*�û��Ѿ�����*/
	ERROR_CODE_AUTH_SERVER_REMOTE_INVOKE_FAILED,				/*Զ���ڲ�����������ʧ��*/
	ERROR_CODE_AUTH_USER_NAME_OR_PASSWD_INCORRECT,				/*��¼�û������������*/
	ERROR_CODE_AUTH_USER_CAPTCHAT_INCORRECT,					/*��֤�����*/
	ERROR_CODE_AUTH_USER_CAPTCHAT_EXPIRE,						/*��֤�����*/
	ERROR_CODE_MSG_SERVER_FIRST_PACKET_TYPE_NOT_AUTH = -115000,	/*�׸����ݰ���������֤��*/
	ERROR_CODE_MSG_SERVER_ACCOUNT_OFFSITE_LOGIN,				/*�˺���ص�¼*/
	ERROR_CODE_MSG_SERVER_MSG_FORWARD_FAILED ,					/*��Ϣת��ʧ��*/
	ERROR_CODE_ONLINE_SERVER_QUERY_DATA_FAILED = -116000,		/*��ѯ����ʧ��*/
	ERROR_CODE_ONLINE_SERVER_UPDATE_DATA_FAILED ,				/*��������ʧ��*/
	ERROR_CODE_ONLINE_SERVER_DELETE_DATA_FAILED ,				/*ɾ������ʧ��*/
	ERROR_CODE_ONLINE_SERVER_ADD_DATA_FAILED ,					/*�������ʧ��*/
	ERROR_CODE_INESAHOME_SERVER_CHECK_BIND_FAILED = -117000,	/*�û����ϵ���ʧ��*/
	ERROR_CODE_INESAHOME_SERVER_DEVICE_ILLEGAL_EQUIPMENT,		/*�Ƿ����豸*/
	ERROR_CODE_INESAHOME_SERVER_GET_ONLINEINFO_FAILED,			/*��ѯ������Ϣ����*/
	ERROR_CODE_INESAHOME_SERVER_ACCOUNT_OFFLINE,				/*�û�������*/
	ERROR_CODE_INESAHOME_SERVER_SAVE_ONEKEYWARNINGMSG_FAILED,	/*����һ��������Ϣʧ��*/
	ERROR_CODE_INESAHOME_SERVER_GET_WHITE_LIST_FROM_DB_FAILED,	/*��ȡ�������б�ʧ��*/
	ERROR_CODE_INESAHOME_SERVER_ADD_WHITE_LIST_TO_DB_FAILED,    /*��Ӱ������б�ʧ��*/
	ERROR_CODE_INESAHOME_SERVER_SAVE_STRATEGY_FAILED,           /*�������ʧ��*/
	ERROR_CODE_INESAHOME_SERVER_DEL_STRATEGY_FAILED,            /*ɾ������ʧ��*/
	ERROR_CODE_INESAHOME_SERVER_ENABLE_STRTATEGY_FAILED,        /*ʹ�ܲ���ʧ��*/
	ERROR_CODE_INESAHOME_SERVER_OPT_CANNOT_SUPPORT,				/*������֧��*/
	ERROR_CODE_DATA_STORAGE_SERVER_SQL_CMD_EMPTY = -118000,		/*sql�������Ϊ��*/
	ERROR_CODE_DATA_STORAGE_SERVER_REQDATA_TOO_MUCH,			/*�û���������̫��*/	
	ERROR_CODE_DATA_STORAGE_DATA_CACHE_FAILED,					/*���ݻ���ʧ��*/
	ERROR_CODE_DATAPROXY_REQ_PATH_ERROR =  -119000,				/*����·������*/

};

class COMM_TOOLS_API ErrorHelper
{
public:
	ErrorHelper(void);
	~ErrorHelper(void);
public:
	static const char* GetErrorMessage(const int errnum);
	static void InitErrorMessage();
private:
	static std::map<int,std::string> m_ErrDescribe;
	//static std::atomic_bool m_isInit;
	static bool m_isInit;
	static CCommonMutex m_ErrMsgMutex;
	
};

#endif