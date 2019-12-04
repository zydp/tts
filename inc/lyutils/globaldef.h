#ifndef G3_GLOBAL_DEFINE_H
#define G3_GLOBAL_DEFINE_H

#include "win32_types.h"
#include <string>
#include <vector>
#include <list>
#define SIZE_TRANSFER_PICE 64*1024
#define  DEFAULT_VODINFO_SIZE 2*1024*1024

#define GET_PEER_RESOURCE_MAX_COUNT_TETURN 10
static std::string g_protocalstring = std::string("<packet><head><service></service><command></command><subcmd></subcmd><ret></ret></head><data></data></packet>");
static const size_t SERVER_THREAD_POOL_SIZE = 5; //�������ݽ��յ��̳߳ش�С
static const size_t TASK_THREAD_POOL_SIZE = 5; //�������ݴ�����̳߳ش�С
static const size_t BUFFER_SIZE = 4096; //���ݻ�������С

static std::string g_strMediaFileExternSupport = std::string("wma,wmv,asf,ra,rm,rmvb,mkv,mp3");
static std::string g_strMediaFileSubtitleExternSupport = std::string("srt");


enum Packet_Type
{
	Packet_Type_MSASF = 0,
};


enum ServerMassage
{
    SWM_CLIENT_CONNECT_SUCCESS = 0x0001, //�ͻ������ӳ�
	SWM_CLIENT_DISCONNECT,               //�ͻ�������Ͽ�
	SWM_SERVICE_START_OK,                 //���������ɹ�
	SWM_CUSTOM_MESSAGE,                   //�Զ�����Ϣ
};

enum PeerNetStunType
{
	PEER_NET_STUN_TYPE_PUBLIC = 0x0001,//����IP
	PEER_NET_STUN_TYPE_LOCAL_CAN_SHOOT,//����UDP���Թ�NAT
	PEER_NET_STUN_TYPE_LOCAL_CANNOT_SHOOT, //�������ܹ�NAT
	PEER_NET_STUN_TYPE_LOCAL_CAN_NOT_UDP, //UDP����ʹ��

	PEER_NET_STUN_TYPE_UNKNOW,            //δ֪����
};

enum Channel_Source_Type
{
	Channel_Source_Type_Local_File = 0x0000,
	Channel_Source_Type_HTTP_RTSP,
	Channel_Source_Type_LYSP,
	Channel_Source_Type_MS_Stream,
	Channel_Source_Type_Card,
	Channel_Source_Type_Desktop,
	Channel_Source_Type_Unknow,	

};

//�������Ĺ���
enum server_function_type
{
	SERVER_FUNCTION_ALL =0x100,		//������������
	SERVER_FUNCTION_ROUTER,         //Rounter������
	SERVER_FUNCTION_ONLINE,			//���߷�����
	SERVER_FUNCTION_LOGBALANCE,		//���������
	SERVER_FUNCTION_GROUP,			//Ⱥ�������
	SERVER_FUNCTION_STREAM_CHANNEL,	//��ý��Ƶ��������
	SERVER_FUNCTION_STREAM_MEDIA,	//��ý�������
	SERVER_FUNCTION_CONFIRM,		//��֤������
	SERVER_FUNCTION_STORAGE,		//�洢������
	SERVER_FUNCTION_AUTHORIZATION,	//��Ȩ������
	SERVER_FUNCTION_HLSSEGMENT,		//��Ƭ������
	SERVER_FUNCTION_INFOPUBLISH,    //��Ϣ����������
	SERVER_FUNCTION_UNKNOW,			//δ֪����
};

enum authorization_result_type
{
	AUTHORIZATION_RESULT_SUCCESS = 0x1,
	AUTHORIZATION_RESULT_FAIL_TIMEOVER,
	AUTHORIZATION_RESULT_FAIL_CPUINFO,
	AUTHORIZATION_RESULT_FAIL_MACINFO,
	AUTHORIZATION_RESULT_FAIL_UNKONW
};
//��Ȩ��Ϣ����
typedef struct authorization_info
{
	std::string strCpuInfo;
	std::string strMacInfo;
	ULONGLONG qwTimeStart;
	ULONGLONG qwTimeEnd;
	bool bEnableServerStorage;
	bool bEnableServerHlsSegment;
	bool bEnableServerInfoPublish;
	authorization_result_type authorization_result;
	authorization_info()
	{
		strCpuInfo.clear();
		strMacInfo.clear();
		qwTimeStart=0;
		qwTimeEnd=0;
		bEnableServerStorage=false;
		bEnableServerHlsSegment=false;
		bEnableServerInfoPublish=false;
		authorization_result=AUTHORIZATION_RESULT_FAIL_UNKONW;
	}
}Authorization_Info,*LPAuthorization_Info;

//Ⱥ�����Ͷ���
enum group_function_type
{
	GROUP_FUNCTION_GROUP_HALFPAUL_CHATROOM = 0x0080, //С������������0x0001;
	GROUP_FUNCTION_GROUP_CHATROOM,                   //������        0x0002;
	GROUP_FUNCTION_GROUP_MEDIACHANNEL_LIVE,          //��ý��Ƶ��ֱ��    0x0004;
	GROUP_FUNCTION_GROUP_MEDIACHANNEL_VOD,           //��ý��Ƶ���㲥
	GROUP_FUNCTION_GROUP_NETDATATRANSCHANNEL,        //����ת��ͨ��  0x0008
	GROUP_FUNCTION_GROUP_UNKNOW                      //δ֪����
	////////////////////////////////////////////
};
//�����������Ͷ���
enum net_connect_type
{
	CONNECT_TYPE_TCP = 0, //TCP
	CONNECT_TYPE_UDP,     //UDP  
	CONNECT_TYPE_HTTP     //HTTP
};
//�ͻ��˷�����Ϣ�ڵ�ṹ
typedef struct client_service_struct
{
	std::string strServerUuid; //��������ID
	std::string strServerFuction;//�������Ĺ���
	std::string strGroupID;      //Ⱥ��ţ��������������Ⱥ�飬��ֵ��Ч
	std::string strServerIP;     //��������IP��ַ
	unsigned short uServerUdpPort; //������UDP�����˿�
	unsigned short uServerTcpPort; //��������TCP�����˿�
	client_service_struct()
	{
		strServerIP.clear();
		strServerFuction.clear();
		strGroupID.clear();
		strServerUuid.clear();
		uServerTcpPort = 0;
		uServerUdpPort = 0;
	}
}CLIENT_SERVICE_STRUCT,*LPCLIENT_SERVICE_STRUCT;

typedef std::vector<CLIENT_SERVICE_STRUCT> CLIENT_SERVICE_VECTOR;
//�ͻ���ͷ�ṹ
typedef struct client_struct
{
	std::string strUuid; //UUID
	unsigned int dwSessionID; //SessionID
	std::string strDomain;    //�ͻ��˵���
	std::string strToken;     //�ͻ��˵�����
	std::string strLocalIP; //����IP
	std::string strExternIP;//�ⲿIP
	int         nNetType;   //��������
	int         nConnectedType;//��������
	unsigned short wConnectedPort; //���Ӷ˿�
	unsigned short wLocalPort;  //���ض˿�
	unsigned short wLocalListenTCPPort; //���ؼ����˿�
	unsigned short wLocalListenUDPPort; //����UDP�����˿�
	int  nSocketPeerHandle;    //�����TCP���ӣ���ֵ�����׽���ָ��
	bool bConnectSuccess;  //�����Ƿ�ɹ�
	bool bPublicIP;        //�Ƿ�Ϊ����IP
	int  nConnnetStatus;   //��������״̬
	int  nNetCapbility;    //������������������
	std::string strLoginTime; //��½ʱ��
	CLIENT_SERVICE_VECTOR vectorServices; //�ͻ��˽���ķ������б�
	client_struct()
	{
		strUuid.clear();
		dwSessionID = 0;
		strLocalIP.clear();
		strExternIP.clear();
		strDomain.clear();
		strToken.clear();
		nNetType = 0;//0��ʾ�����û���1��ʾ�����û�
		nConnectedType = 1;
		wConnectedPort = 0;
		wLocalPort = 0;
		wLocalListenUDPPort = 0;
		wLocalListenTCPPort = 0;
		nSocketPeerHandle = -1;
		bConnectSuccess = false;
		nConnnetStatus = 0;//�������ӣ�1��ʾû�м�⵽������2��ʾ�Ѿ�����
		nNetCapbility = 1;//1��2��3
		vectorServices.clear();
	}
}CLIENT_NODE_STRUCT,*LPCLIENT_NODE_STRUCT;

typedef struct G3P2P_Struct_Server_Node //����������Լ�����Ϣ
{
	bool bReg;  //�Ƿ�ע��ɹ�
	bool bInfoShare; //�Ƿ���Ϣ��������������������������
	unsigned int dwSessionID; //ServerID ��Router����������
	std::string strLoginTime;    //��������½ʱ��
	std::string strHashID;       //��������HashID
	std::string strServerName;   //����������
	std::string strFounctionDescript;    //�������Ĺ�������
	std::string strDomain;      //����������
	std::string strFounction;//�������Ĺ���
	unsigned int wConnectPort;//���Ӷ˿�
	unsigned short wTCPListenPort;  //TCP�����˿�
	unsigned short wUDPListerPort;  //�Կͻ��˵�UDP����˿�
	std::string strIPAddress;           //��������IP��ַ������Ϊ�ⲿIP
	std::string strVersion;             //��Ӧ�������İ汾��
	unsigned int  dwServerUserCount;//��������ǰ����
	unsigned int  dwCurrentGroupCount; //group ר��,��ǰgroup����
	unsigned int  dwLocalServerID; //storageר�ã�����serverid
	unsigned int  dwServerSubFunctionSupport;
	unsigned int  dwServerXCountRerserver1; //��������
	unsigned int  dwServerXCountRerserver2; //��������
	int  nClientSocketHandle; //����������Socketָ��
	int nServerFunctionType; //�������Ĺ�������
	G3P2P_Struct_Server_Node()
	{
		nClientSocketHandle = 0;
		bReg = false;
		bInfoShare = false;
		dwSessionID = 0xFFFFFFFF;
		strLoginTime ="0-0-0 0-0 0:0:0";
		strHashID="";
		strDomain = "";
		strFounction="Unknow";
		strFounctionDescript="Unknow";
		strServerName = "Unknow";
		wTCPListenPort = 0;
		wUDPListerPort = 0;
		wConnectPort = 0;
		strIPAddress = "0.0.0.0";
		strVersion = "1.0.0.0";
		dwServerUserCount = 0;
		dwCurrentGroupCount = 0;
		dwLocalServerID = 0;
		dwServerSubFunctionSupport = 0;
		dwServerXCountRerserver1 = 0;
		dwServerXCountRerserver2 = 0;
		nServerFunctionType = SERVER_FUNCTION_UNKNOW;
	}
}SERVER_NODE,*LPSERVER_NODE;

enum LY_Media_Channel_type
{
	LY_Media_Channel_type_Vod = 0x00,
	LY_Media_Channel_type_Live,
};

enum LY_Media_Channel_Vod_File_Type
{
	LY_Media_Channel_Vod_File_Type_MediaFile,
	LY_Media_Channel_Vod_File_Type_SubtitleFile,
    LY_Media_Channel_Vod_File_Type_AudioTrackFile,
	LY_Media_Channel_Vod_File_Type_Unknow,
};

typedef struct Peer_P2P_Info_Base
{
	std::string strUuid;
	std::string strIP;
	net_connect_type nType;
	unsigned short uUdpDataPort;
	unsigned short uTcpDataPort;
}PEER_P2P_INFO_BASE,*LPPEER_P2P_INFO_BASE;

//��ý��Ƶ�����Զ���
typedef struct LY_Media_Channel_Struct
{
	//Ƶ������
	std::string strTitle;           //Ƶ������
	std::string strDescription;     //Ƶ������
	std::string strAuthor;          //Ƶ������
	std::string strPromulgator;     //Ƶ��������
	ULONGLONG   qwPublishDate;      //��������
	std::string strHashID;		    //Ƶ��ID
	std::string strUserID;          //������ID
	std::string strUrl;             //������URL
	std::string strDomain;          //Ƶ�����ڵ���Ϊ����Ƶ�����û����ڵ���
	std::string strChannelPassword; //Ƶ�����룬ȱʡΪ��
	std::string strSublineURL;      //Ƶ����subline��ַ
	std::string strIconURL;         //Ƶ����ͼ���ַ
	int         nChannelType;       //Ƶ������
	int         nCountryIndex;      //�������
	std::string strLanguage;        //����
	int m_nMaxPeerCount;            //�����������
	//Ƶ����Ŀ����
	std::string strActName;         //��Ŀ����
	int         nBitRate;           //����
	int         nPicWidth;          //������
	int         nPicHeight;         //����߶�
	bool        bAuditingPassed;    //�Ƿ�ͨ�����
	bool        bStarted;           //�Ƿ񿪲�
	bool        bAutoDeleteAfterNoPeer;  //�Ƿ��Զ�ɾ��
	bool        bAutoDeleteAfterNoCreator;
	int         nChannelCount;      //����Ƶ����Peer��
	ULONGLONG   qwLastModifyDate;   //����޸�����
	int         mediafilecount;     //��Ƶ�ļ���
	int         filetotalcount;     //�ļ�����
	int         subtitlecount;      //��Ļ�ļ�����
	int         publishtype;        //Ƶ�����ͣ��㲥����ֱ��
}LY_MEDIA_CHANNEL,*LPLY_MEDIA_CHANNEL;

typedef struct Media_Channel_Extern
{
	std::string  strHashID; //Ƶ����
	std::string  strGroupServerID;
	std::string  strGroupHashID;
}LY_MEDIA_CHANNEL_EXTERN,*LPLY_MEDIA_CHANNEL_EXTERN;

typedef struct Media_Channel_Vod_File_List
{
	std::string strFileName;
	ULONGLONG   qwFileSize;
	int         nFileType;
}MEDIA_CHANNEL_VOD_FILE_INFO,*LPMEDIA_CHANNEL_VOD_FILE_INFO;

typedef struct Task_List_Node
{
	void * pUserPram;
	int    nTaskCommand;
	int    nTaskID;
	std::string strXID;
}TASK_LIST_NODE,*LPTASK_LIST_NODE;

typedef struct Task_Result_Node
{
	int nTaskResult;
	std::string strXID;
}TASK_RESULT_NODE,*LPTASK_RESULT_NODE;

//�û�Ȩ�޶���
enum User_Power_Type
{
	USER_POWER_USER_MANAGE=1, //�û�����Ȩ��
	USER_POWER_LY_MEDIA,      //��ý��Ƶ��Ȩ��
	USER_POWER_CHATROOM,      //�����ң������ң�Ȩ��
	USER_POWER_PPCHATROOM,    //����������������Ȩ��
};

enum User_Power_User_Manage
{
	POWER_USER_MANAGE_ADUSER=0, //����ɾ���û�
	POWER_USER_MANAGE_RPASSWD,//�����û�����
    POWER_USER_MANAGE_RPOWER , //�û���Ȩ
};

enum User_Power_LY_Media
{
    POWER_LY_MEDIA_VIEW =0, //�ۿ�Ƶ��
	POWER_LY_MEDIA_PUBLISH,//����Ƶ��
	POWER_LY_MEDIA_AUDTING,//���Ƶ��
	POWER_LY_MEDIA_MANAGE, //����Ƶ����ɾ����
};

enum User_Power_ChatRoom
{

};

enum User_Power_PPChatRoom
{

};


typedef struct Add_Update_Channel
{
	std::list<std::string> FileList;
	LY_MEDIA_CHANNEL ChannelInfo;
	bool IsUpdate;
	bool bReecode;
	int  nChannelSourceType;
	std::string strFileBasePath;
}ADD_UPDATE_CHANNEL,*LPADD_UPDATE_CHANNEL;

enum Audio_Encode_Type
{
	Audio_Encode_Mp3 = 0,
};

enum Video_Encode_Type
{
	Video_Encode_H264 = 0,
};

typedef struct Add_NewChannel_Reencode
{
	bool bKeepAudioParam;
	int  nAudioChannles;
	int  nAudioBitsPerSample;
	int  nAudioSampleRate;
	int  nAudioEncodeType;

	bool bKeepVideoParam;
	bool bKeepVideoAspect;
	int  nVideoWidth;
	int  nVideoHeight;
	int  nVideoEncodeType;
	int  nPacketType;
	int  nPacketSize;

}ADD_NEWCHANNANL_REENCODE,*LPADD_NEWCHANNANL_REENCODE;

typedef struct Add_NewChannel_CAPTURE
{
	bool bCapture;

}ADD_NEWCHANNANL_CAPTURE,*LPADD_NEWCHANNANL_CAPTURE;

typedef struct Channel_Publish_Param
{
	ADD_UPDATE_CHANNEL ChannelUpdateParam;
	ADD_NEWCHANNANL_REENCODE ChannelRecodeParam;
	ADD_NEWCHANNANL_CAPTURE ChannelCaputerparam;    
}CHANNEL_PUBLISH_PARAM,*LPCHANNEL_PUBLISH_PARAM;

#endif
