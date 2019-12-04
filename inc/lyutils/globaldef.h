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
static const size_t SERVER_THREAD_POOL_SIZE = 5; //进行数据接收的线程池大小
static const size_t TASK_THREAD_POOL_SIZE = 5; //进行数据处理的线程池大小
static const size_t BUFFER_SIZE = 4096; //数据缓冲区大小

static std::string g_strMediaFileExternSupport = std::string("wma,wmv,asf,ra,rm,rmvb,mkv,mp3");
static std::string g_strMediaFileSubtitleExternSupport = std::string("srt");


enum Packet_Type
{
	Packet_Type_MSASF = 0,
};


enum ServerMassage
{
    SWM_CLIENT_CONNECT_SUCCESS = 0x0001, //客户端连接城
	SWM_CLIENT_DISCONNECT,               //客户端网络断开
	SWM_SERVICE_START_OK,                 //服务启动成功
	SWM_CUSTOM_MESSAGE,                   //自定义消息
};

enum PeerNetStunType
{
	PEER_NET_STUN_TYPE_PUBLIC = 0x0001,//公网IP
	PEER_NET_STUN_TYPE_LOCAL_CAN_SHOOT,//内网UDP可以过NAT
	PEER_NET_STUN_TYPE_LOCAL_CANNOT_SHOOT, //内网不能过NAT
	PEER_NET_STUN_TYPE_LOCAL_CAN_NOT_UDP, //UDP不能使用

	PEER_NET_STUN_TYPE_UNKNOW,            //未知类型
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

//服务器的功能
enum server_function_type
{
	SERVER_FUNCTION_ALL =0x100,		//包含所有类型
	SERVER_FUNCTION_ROUTER,         //Rounter服务器
	SERVER_FUNCTION_ONLINE,			//在线服务器
	SERVER_FUNCTION_LOGBALANCE,		//均衡服务器
	SERVER_FUNCTION_GROUP,			//群组服务器
	SERVER_FUNCTION_STREAM_CHANNEL,	//流媒体频道服务器
	SERVER_FUNCTION_STREAM_MEDIA,	//流媒体服务器
	SERVER_FUNCTION_CONFIRM,		//认证服务器
	SERVER_FUNCTION_STORAGE,		//存储服务器
	SERVER_FUNCTION_AUTHORIZATION,	//授权服务器
	SERVER_FUNCTION_HLSSEGMENT,		//切片服务器
	SERVER_FUNCTION_INFOPUBLISH,    //信息发布服务器
	SERVER_FUNCTION_UNKNOW,			//未知类型
};

enum authorization_result_type
{
	AUTHORIZATION_RESULT_SUCCESS = 0x1,
	AUTHORIZATION_RESULT_FAIL_TIMEOVER,
	AUTHORIZATION_RESULT_FAIL_CPUINFO,
	AUTHORIZATION_RESULT_FAIL_MACINFO,
	AUTHORIZATION_RESULT_FAIL_UNKONW
};
//授权信息定义
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

//群组类型定义
enum group_function_type
{
	GROUP_FUNCTION_GROUP_HALFPAUL_CHATROOM = 0x0080, //小半推送聊天室0x0001;
	GROUP_FUNCTION_GROUP_CHATROOM,                   //聊天室        0x0002;
	GROUP_FUNCTION_GROUP_MEDIACHANNEL_LIVE,          //流媒体频道直播    0x0004;
	GROUP_FUNCTION_GROUP_MEDIACHANNEL_VOD,           //流媒体频道点播
	GROUP_FUNCTION_GROUP_NETDATATRANSCHANNEL,        //数据转发通道  0x0008
	GROUP_FUNCTION_GROUP_UNKNOW                      //未知类型
	////////////////////////////////////////////
};
//网络连接类型定义
enum net_connect_type
{
	CONNECT_TYPE_TCP = 0, //TCP
	CONNECT_TYPE_UDP,     //UDP  
	CONNECT_TYPE_HTTP     //HTTP
};
//客户端服务信息节点结构
typedef struct client_service_struct
{
	std::string strServerUuid; //服务器的ID
	std::string strServerFuction;//服务器的功能
	std::string strGroupID;      //群组号，如果服务器进入群组，该值有效
	std::string strServerIP;     //服务器的IP地址
	unsigned short uServerUdpPort; //服务器UDP监听端口
	unsigned short uServerTcpPort; //服务器的TCP监听端口
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
//客户端头结构
typedef struct client_struct
{
	std::string strUuid; //UUID
	unsigned int dwSessionID; //SessionID
	std::string strDomain;    //客户端的域
	std::string strToken;     //客户端的令牌
	std::string strLocalIP; //本地IP
	std::string strExternIP;//外部IP
	int         nNetType;   //网络类型
	int         nConnectedType;//连接类型
	unsigned short wConnectedPort; //连接端口
	unsigned short wLocalPort;  //本地端口
	unsigned short wLocalListenTCPPort; //本地监听端口
	unsigned short wLocalListenUDPPort; //本地UDP监听端口
	int  nSocketPeerHandle;    //如果是TCP连接，此值保存套节字指针
	bool bConnectSuccess;  //连接是否成功
	bool bPublicIP;        //是否为公网IP
	int  nConnnetStatus;   //网络连接状态
	int  nNetCapbility;    //网络质量，传输能力
	std::string strLoginTime; //登陆时间
	CLIENT_SERVICE_VECTOR vectorServices; //客户端进入的服务器列表
	client_struct()
	{
		strUuid.clear();
		dwSessionID = 0;
		strLocalIP.clear();
		strExternIP.clear();
		strDomain.clear();
		strToken.clear();
		nNetType = 0;//0表示内网用户，1表示外网用户
		nConnectedType = 1;
		wConnectedPort = 0;
		wLocalPort = 0;
		wLocalListenUDPPort = 0;
		wLocalListenTCPPort = 0;
		nSocketPeerHandle = -1;
		bConnectSuccess = false;
		nConnnetStatus = 0;//正常连接，1表示没有检测到心跳，2表示已经断线
		nNetCapbility = 1;//1，2，3
		vectorServices.clear();
	}
}CLIENT_NODE_STRUCT,*LPCLIENT_NODE_STRUCT;

typedef struct G3P2P_Struct_Server_Node //保存服务器自己的信息
{
	bool bReg;  //是否注册成功
	bool bInfoShare; //是否信息共享，如果共享，用许其他的域访问
	unsigned int dwSessionID; //ServerID 由Router服务器分配
	std::string strLoginTime;    //服务器登陆时间
	std::string strHashID;       //服务器的HashID
	std::string strServerName;   //服务器名称
	std::string strFounctionDescript;    //服务器的功能描述
	std::string strDomain;      //服务器的域
	std::string strFounction;//服务器的功能
	unsigned int wConnectPort;//连接端口
	unsigned short wTCPListenPort;  //TCP监听端口
	unsigned short wUDPListerPort;  //对客户端的UDP信令端口
	std::string strIPAddress;           //服务器的IP地址，必须为外部IP
	std::string strVersion;             //对应服务器的版本号
	unsigned int  dwServerUserCount;//服务器当前人数
	unsigned int  dwCurrentGroupCount; //group 专用,当前group总数
	unsigned int  dwLocalServerID; //storage专用，本地serverid
	unsigned int  dwServerSubFunctionSupport;
	unsigned int  dwServerXCountRerserver1; //保留数字
	unsigned int  dwServerXCountRerserver2; //保留数字
	int  nClientSocketHandle; //服务器连接Socket指针
	int nServerFunctionType; //服务器的功能类型
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

//流媒体频道属性定义
typedef struct LY_Media_Channel_Struct
{
	//频道属性
	std::string strTitle;           //频道标题
	std::string strDescription;     //频道描述
	std::string strAuthor;          //频道作者
	std::string strPromulgator;     //频道发布者
	ULONGLONG   qwPublishDate;      //发布日期
	std::string strHashID;		    //频道ID
	std::string strUserID;          //发布者ID
	std::string strUrl;             //创办人URL
	std::string strDomain;          //频道所在的域，为发布频道的用户所在的域
	std::string strChannelPassword; //频道密码，缺省为空
	std::string strSublineURL;      //频道的subline地址
	std::string strIconURL;         //频道的图标地址
	int         nChannelType;       //频道类型
	int         nCountryIndex;      //国家序号
	std::string strLanguage;        //语言
	int m_nMaxPeerCount;            //最大人数限制
	//频道节目属性
	std::string strActName;         //节目名称
	int         nBitRate;           //码流
	int         nPicWidth;          //画面宽度
	int         nPicHeight;         //画面高度
	bool        bAuditingPassed;    //是否通过审核
	bool        bStarted;           //是否开播
	bool        bAutoDeleteAfterNoPeer;  //是否自动删除
	bool        bAutoDeleteAfterNoCreator;
	int         nChannelCount;      //在线频道总Peer数
	ULONGLONG   qwLastModifyDate;   //最后修改日期
	int         mediafilecount;     //视频文件数
	int         filetotalcount;     //文件总数
	int         subtitlecount;      //字幕文件总数
	int         publishtype;        //频道类型，点播或者直播
}LY_MEDIA_CHANNEL,*LPLY_MEDIA_CHANNEL;

typedef struct Media_Channel_Extern
{
	std::string  strHashID; //频道号
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

//用户权限定义
enum User_Power_Type
{
	USER_POWER_USER_MANAGE=1, //用户管理权限
	USER_POWER_LY_MEDIA,      //流媒体频道权限
	USER_POWER_CHATROOM,      //聊天室（会议室）权限
	USER_POWER_PPCHATROOM,    //半推拉类型聊天室权限
};

enum User_Power_User_Manage
{
	POWER_USER_MANAGE_ADUSER=0, //增加删除用户
	POWER_USER_MANAGE_RPASSWD,//更改用户密码
    POWER_USER_MANAGE_RPOWER , //用户授权
};

enum User_Power_LY_Media
{
    POWER_LY_MEDIA_VIEW =0, //观看频道
	POWER_LY_MEDIA_PUBLISH,//发布频道
	POWER_LY_MEDIA_AUDTING,//审核频道
	POWER_LY_MEDIA_MANAGE, //管理频道（删除）
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
