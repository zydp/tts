/************************************************************************
文件功能:系统协议定义文件  
作    者:颉小龙
公    司:上海龙驭信息技术有限公司
完成日期:
修改记录:                                                                    
************************************************************************/
#ifndef G3_PP_PROTCOL_H
#define G3_PP_PROTCOL_H

//协议格式
/*
<?xml version="1.0" encoding="UTF-8" protocl="longyug3pp?>
<packet>
    <head>
		<service>router</service>
		<version>1.0.0.0</version>
		<command>reg</command>
		<subcmd></subcmd>
		<uuid></uuid>
		<session></session>
		<ret></ret>
	</head>
	<data>
		<servercount>2</servercount>
		<server>
			<name>stun</name>
			<ip>127.0.0.1</ip>
			<port>3701</port>
		</server>
		<server>
			<name>ptprs</name>
			<ip>127.0.0.1</ip>
			<port>3801</port>
			</server>
	</data>
</packet>

service表示服务类型
version ：协议版本，
command : 主协议命令
subcmd：副协议命令
uuid：用户uuid
session:用户session
data为具体协议内容
*/
/************************************************************************/
//主协议命令
#define G3P2P_MAIN_SERVICES_ALL                  "all"             //所有服务
#define G3P2P_MAIN_SERVICES_ROUTER               "router"          //router服务
#define G3P2P_MAIN_SERVICES_LOGINSERVER          "loginsvr"        //登陆服务,平衡服务器
#define G3P2P_MAIN_SERVICES_GROUPSERVER          "groupsvr"        //群组服务
#define G3P2P_MAIN_SERVICES_LOGSERVER            "logsvr"          //日志服务器
#define G3P2P_MAIN_SERVICES_CONFIRMSERVER        "confsvr"         //认证服务
#define G3P2P_MAIN_SERVICES_ONLINESERVER         "olsvr"           //在线服务,ptprs
#define G3P2P_MAIN_SERVICES_CHANNELSERVER        "chsvr"           //流媒体频道服务器
#define G3P2P_MAIN_SERVICES_MEDIASERVER          "mediasvr"        //流媒体服务器
#define G3P2P_MAIN_SERVICES_EXTERN_FS            "exterfs"         //扩展服务类型
#define G3P2P_MAIN_SERVICES_STORAGESERVER        "storage"	       //存储服务器
#define G3P2P_MAIN_SERVICES_HLSSEGMENTSERVER     "segsrv"          //切片服务器
#define G3P2P_MAIN_SERVICES_AUTHORIZATIONSERVER  "authsvr"         //授权服务
#define G3P2P_MAIN_SERVICES_INFOPUBLISHSERVER    "infosvr"         //信息发布服务器

//Sub Command子命令
/**************************router***********************************************/
#define G3P2P_COMMAND_ROUTER_REGISTER              "register"          //注册
#define G3P2P_COMMAND_ROUTER_UNREGISTER            "unregister"        //注销
#define G3P2P_COMMAND_ROUTER_INFO_REFERESH         "infref"            //信息更新
#define G3P2P_COMMAND_ROUTER_GET_SERVER_INFO       "ginfo"             //获取服务器信息列表
#define G3P2P_COMMAND_ROUTER_TRANSF_INFO           "transinf"          //信息中转
#define G3P2P_COMMAND_ROUTER_STOP                  "stop"              //停止服务器
#define G3P2P_COMMAND_ROUTER_GET_INFO_BY_ID_FUC    "ginfobyidfuc"      //通过ID和服务器功能获取唯一的服务器信息
#define G3P2P_COMMAND_ROUTER_GET_AUTHORIZATION     "gauthor"           //请求已授权信息
#define G3P2P_COMMAND_ROUTER_SET_AUTHORIZATION     "sauthor"           //设置新授权信息

//Router服务器返回给服务器信息
/*******************************************************************************/
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_SUCCESS          "reg_success"        //注册成功
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_DENY             "reg_deny"           //注册被拒绝
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_ERROR_PARAM      "reg_eparam"         //注册参数不正确
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_LOW_VER          "reg_verout"         //协议版本过期

#define G3P2P_COMMAND_ROUTER_RET_GETSERVERINFO_SUCCESS      "ginfo_success"      //获取服务器信息成功
#define G3P2P_COMMAND_ROUTER_RET_GETSERVERINFO_ERROR_PARAM  "ginfo_eparam"       //获取服务器信息参数不正确
#define G3P2P_COMMAND_ROUTER_RET_GETSERVERINFO_DENY         "ginfo_deny"         //获取服务器信息被拒绝

#define G3P2P_COMMAND_ROUTER_RET_TRANSINFO_ERROR_PARAM      "transinfo_eparam"   //信息中转参数不正确
#define G3P2P_COMMAND_ROUTER_RET_TRANSINFO_DENY             "transinfo_deny"     //信息中转被拒绝
#define G3P2P_COMMAND_ROUTER_RET_TRANSINFO_SUCCESS          "transinfo_success"  //信息中转成功

#define G3P2P_COMMAND_ROUTER_RET_STOP_SUCCESS               "stop_success"       //停止成功
#define G3P2P_COMMAND_ROUTER_RET_STOP_FAIL                  "stop_fail"          //停止失败

//Router服务器发出的命令
/*******************************************************************************/
#define G3P2P_COMMAND_ROUTER_TRAN_SERVER_ADD            "svr_add"          //有新的服务器添加
#define G3P2P_COMMAND_ROUTER_TRAN_SERVER_DEL            "svr_del"          //有服务器断开
#define G3P2P_COMMAND_ROUTER_TRAN_SERVER_INFO_REFRESH   "ser_ifrefresh"    //服务器信息更新

//peer端和Login Banlance server的命令
/*******************************************************************************/
#define G3P2P_COMMAND_PEER_GET_ONLINE_SERVER  "pgolsvr"  //获取一个Online Server的地址

//login banlance server返回给peer的命令
/*******************************************************************************/
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_SUCCESS      "pgols_sucs"      //获取成功
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_ERROR_PARAM  "pgolsvr_epm"     //参数错误
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_NO_OLSA      "pgolsvr_noolsf"  //没有在线服务器可用
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_DENY         "pgolsvr_deny"    //被拒绝

//online server 和Peer端的协议
/*******************************************************************************/
#define  G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER    "plogintols"   //Pee端登陆在线服务器
#define  G3P2P_COMMAND_ONLINESERVER_LOGOUT_TO_SERVER   "plogouttols"  //Peer端注销在线服务器
#define  G3P2P_COMMAND_ONLINESERVER_KEEP_LIVE          "pkpltols"     //Peer端发送心跳
#define  G3P2P_COMMAND_ONLINESERVER_GET_FUNSERID       "pgfsidl"      //peer 获取功能服务器ID
#define  G3P2P_COMMAND_ONLINESERVER_GET_FUNSER_INFO    "pgfsfi"       //Peer端获取一个功能服务器信息

//Online server返回给Peer端的命令
/*******************************************************************************/
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_SUCCESS         "plogtols_sucs"   //登陆成功
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_ERROR_PARAM     "plogtols_epm"    //登陆参数错误
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_OUT_VERSION     "plogtols_outver" //版本过期
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_ERROR_USER      "plogtols_euser"  //错误的用户名或者密码
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_DENY            "plogtols_deny"   //登陆被拒绝
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_MAX_CLIENT      "plogtols_maxc"   //服务器达到最大人数
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_MAX_TCP_CLIENT  "plogtols_maxtc"  //服务区达到最大TCP连接人数
#define G3P2P_COMMAND_ONLINESERVER_RELOGIN                         "polstp_relogin"  //用户重新在别的地方登陆

#define G3P2P_COMMAND_ONLINESERVER_RET_FUNINFOID_SUCCESS           "pgfidl_sucs"     //获取功能服务器ID List成功
#define G3P2P_COMMAND_ONLINESERVER_RET_FUNINFO_SUCCESS             "pgfif_sucs"      //获取服务器信息成功
#define G3P2P_COMMAND_ONLINESERVER_RET_FUNINFOID_NOFUN             "pgfidl_nof"      //没找到相应的服务器
#define G3P2P_COMMAND_ONLINESERVER_RET_FUNSERINFO_NOFUN            "pgfif_nof"       //没找到相应的服务器

#define G3P2P_COMMAND_PEER_KEEPLIVE_ONLINESERVER                   "pkpltols"        //Peer端keeplive
#define G3P2P_COMMAND_ONLINESERVER_RET_KEEP_LIVE                   "olskl_ret"       //Onlineserver返回keeplive

//group server和group client的协议
/*******************************************************************************/
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP                "gctg_crt"     //创建一个群组
#define G3P2P_COMMAND_GROUPSERVER_CREATEANDJOIN_GROUP         "gctg_caj"     //创建并加入群组
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP               "gctg_dstry"   //删除一个群组
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP                  "gctg_join"    //加入一个群组
#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP                  "gctg_quit"    //退出一个群组
#define G3P2P_COMMAND_GROUPSERVER_COMMAND_IN_GROUP            "gctg_ingrp"   //群内部消息
#define G3P2P_COMMAND_GROUPSERVER_COMMAND_REPORT_FILE_LIST    "gctg_rfl"     //Vod 文件列表

//Vod Client和 Vod Group的协议
/*******************************************************************************/
#define G3P2P_COMMAND_GROUPSERVER_GETPEER                "gctg_gpl"   //获取Peer资源
#define G3P2P_COMMAND_GROUPSERVER_SHOTTO                 "gctg_st"    //打洞请求
#define G3P2P_COMMAND_GROUPSERVER_UPDATEFILE_CACHE       "gctg_ufc"   //更新文件缓冲状态
#define G3P2P_COMMAND_GROUPSERVER_CHANGE_VOD_FILE        "gctg_cvf"   //改变vod文件
#define G3P2P_COMMAND_GROUPSERVER_CHANGE_VOD_START       "gctg_sttv"  //开始VOD点播
#define G3P2P_COMMAND_GROUPSERVER_CHANGE_VOD_STOP        "gctg_stpv"  //停止VOD点播
#define G3P2P_COMMAND_GROUPSERVER_UPDATE_DATATRANS_PORT  "gctg_udtp"  //更新数据传输端口

//group server返回给group client的协议
/*******************************************************************************/
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_SUCCESS         "gtgc_crt_sucs"     //创建群成功
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_OUT_VERSION     "gtgc_crt_outver"   //版本过期
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_ERROR_PARAM     "gtgc_crt_eparam"   //参数错误
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_DENY            "gtgc_crt_deny"     //创建被拒绝
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_MAX_GROUP       "gtgc_crt_maxg"     //群组已满
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_FAIL            "gtgc_crt_fail"     //创建失败

#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_SUCCESS           "gtgc_join_sucs"    //进入群组成功
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_DENY              "gtgc_join_deny"    //进入群组被拒绝
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_OUT_VERSION       "gtgc_join_outver"  //进入群组版本过期
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_EPSWD             "gtgc_join_epswd"   //进入群组密码错误
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_ERROR_PARAM       "gtgc_join_eparam"  //进入群组参数错误
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_MAX_CLIENT        "gtgc_join_maxc"    //群组人数已满
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_NOEXIST           "gtgc_join_nest"    //要加入的群组不存在
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_FAIL              "gtgc_join_fail"    //加入失败,原因未知

#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_SUCCESS        "gtgc_dstry_sucs"   //销毁群组成功
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_NOCREATOR      "gtgc_dstry_nocrtr" //销毁群组失败,非创建者
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_NOEXIST        "gtgc_dstry_noest"  //要销毁的群组不存在
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_EPARAM         "gtgc_dstry_ep"     //要销毁的群组不存在

#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP_SUCCESS           "gtgc_quit_sucs"    //退出该群成功
#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP_NOEXIST           "gtgc_quit_noest"   //要退出的群组不存在
#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP_ERROR_PARAM       "gtgc_quit_ep"      //命令参数错误

#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_SUCCESS     "gtgc_rfl_sucs"     //创建文件列表成功
#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_FAIL        "gtgc_rfl_fail"     //创建文件列表失败
#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_EP          "gtgc_rfl_ep"       //创建文件列表参数错误
#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_DENY        "gtgc_rfl_deny"     //创建文件列表被拒绝

#define G3P2P_COMMAND_GROUPSERVER_GETPEER_SUCCESS              "gctg_gpl_sucs"     //获取Peer资源成功

//Channel Server和 channel publisher 的协议 
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH                "cptc_pblsh"       //发布一个频道
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE                 "cptc_rm"          //删除一个频道
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO   "cptc_ufi"         //更新VOD文件信息
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE                 "cptc_up"          //更新频道信息

//Vod Client 和Channel Server的协议
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNELID_LIST            "ctcs_gcl"    //获取频道ID列表
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_INFO              "ctcs_gci"    //获取频道信息
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_VOD_FILE_LIST     "ctcs_gvfl"   //获取Vod文件列表
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_GET_GROUP_SERVER  "ctcs_ggsi"   //获取groupserverinfo

//Channel Server返回给vod client的协议
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNELID_LIST_SUCCESS  "cstc_gcl_sucs"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNELID_LIST_EPRAM    "cstc_gcl_ep"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNELID_LIST_DENY     "cstc_gcl_deny"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNELID_LIST_FAIL     "cstc_gcl_fail"

#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_INFO_SUCCESS    "cstc_gci_sucs"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_INFO_NOCHANNEL  "cstc_gci_nc"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_INFO_EPARAM     "cstc_gci_ep"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_INFO_FAIL       "cstc_gci_fail"

#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_VOD_FILE_LIST_SUCCESS     "cstc_gvfl_sucs"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_VOD_FILE_LIST_EPARAM      "cstc_gvfl_ep"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_VOD_FILE_LIST_NOVODFILE   "cstc_nf"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_VOD_FILE_LIST_FAIL        "cstc_fail"

#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_GET_GROUP_SERVER_SUCCESS  "cstc_ggsi_sucs"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_GET_GROUP_SERVER_EPARAM   "cstc_ggsi_ep"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_GET_GROUP_SERVER_NOEXIST  "cstc_ggsi_ne"
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_GET_GROUP_SERVER_FAIL     "cstc_ggsi_fail"

//Channel Server返回给channel publisher的协议
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_SUCCESS      "cptc_pblsh_sucs"    //发布一个频道成功
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_DENY         "cptc_pblsh_deny"    //发布频道被拒绝
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_ERROR_PARAM  "cptc_pblsh_ep"      //发布频道被参数错误
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_EXIST        "cptc_pblsh_exist"   //频道已经存在
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_FAIL         "cptc_pblsh_fail"    //发布频道失败

#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_SUCCESS       "cptc_rm_sucs"       //删除一个频道成功
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_DENY          "cptc_rm_deny"       //删除一个频道被拒绝
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_ERROR_PARAM   "cptc_rm_ep"         //删除一个频道参数错误
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_NO_EXIST      "cptc_rm_ne"         //要删除的频道不存在
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_FAIL          "cptc_rm_fail"       //要删除频道失败

#define G3P2P_COMMAND_CHANNELSERVER_START_SUCCESS        "cptc_st_sucs"       //开播一个频道成功
#define G3P2P_COMMAND_CHANNELSERVER_START_FAIL           "cptc_st_fail"       //开播一个频道失败

#define G3P2P_COMMAND_CHANNELSERVER_STOP_SUCCESS         "cptc_sp_sucs"       //停播一个频道成功
#define G3P2P_COMMAND_CHANNELSERVER_STOP_FAIL            "cptc_sp_fail"       //开播一个频道失败

#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_SUCCESS       "cptc_up_sucs"       //更新频道信息成功
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_DENY          "cptc_up_deny"       //更新失败
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_FAIL          "cptc_up_fail"       //开播一个频道失败
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_NO_EXIST      "cptc_up_nexist"     //更新频道不存在
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_ERROR_PARAM   "cptc_up_ep"         //更新频道参数错误

#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_SUCCESS       "cptc_uvfi_sucs"    //更新VOD文件信息成功
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_DENY          "cptc_uvfi_deny"    //更新VOD文件信息被拒绝
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_ERROR_PARAM   "cptc_uvfi_ep"      //更新VOD文件信息参数错误
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_NOEXIST       "cptc_uvfi_nest"    //更新VOD文件信息频道不存在
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_FAIL          "ptc_uvfi_fail"     //更新VOD文件信息失败


//Channel Server返回给channel client的协议
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_GET_GSERVER          "cptc_gs_gs"         //获取group server
#define G3P2P_COMMAND_CHANNELSERVER_GET_SUCCESS          "cptc_gs_sucs"       //获取group server成功
#define G3P2P_COMMAND_CHANNELSERVER_GET_NOGS             "cptc_gs_ngs"        //没有可用的group server
#define G3P2P_COMMAND_CHANNELSERVER_GET_FAIL             "cptc_gs_fail"       //获取group server 失败


//Info Publish Server 和Info Publish Client的协议
/*******************************************************************************/
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER    "plogintoips"   //Pee端登陆在线服务器
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_LOGOUT_TO_SERVER   "plogouttoips"  //Peer端注销在线服务器
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_KEEP_LIVE          "pkpltoips"     //Peer端发送心跳
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_SEND_CMD_TO_CLIENT "ipscmdtop"     //Server发送给Peer指令

//Info Publish Server返回给Peer端的命令
/*******************************************************************************/
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_SUCCESS         "plogtoips_sucs"     //登陆成功
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_ERROR_PARAM     "plogtoips_epm"      //登陆参数错误
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_OUT_VERSION     "plogtoips_outver"   //版本过期
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_ERROR_USER      "plogtoips_euser"    //错误的用户名或者密码
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_DENY            "plogtoips_deny"     //登陆被拒绝
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_MAX_CLIENT      "plogtoips_maxc"     //服务器达到最大人数
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_MAX_TCP_CLIENT  "plogtoips_maxtc"    //服务区达到最大TCP连接人数
#define G3P2P_COMMAND_INFOPUBLISHSERVER_RELOGIN                         "plogtoips_relogin"  //用户重新在别的地方登陆

#define G3P2P_COMMAND_PEER_KEEPLIVE_INFOPUBLISHSERVER                   "pkpltoips"        //Peer端keeplive
#define G3P2P_COMMAND_INFOPUBLISHSERVER_RET_KEEP_LIVE                   "ipskl_ret"        //server返回keeplive


//channel 更新策略
enum Channel_Update_Method
{
	CHANNEL_UPDATE_METHOD_ALL = 0,  //全部更新
	CHANNEL_UPDATE_METHOD_AUDITING, //
	CHANNEL_UPDATE_METHOD_START,
	CHANNEL_UPDATE_METHOD_CHANNEL_COUNT,
	CHANNEL_UPDATE_METHOD_MEDIAINFO,
};

enum Channel_Remove_Method
{
	CHANNEL_REMOVE_METHOD_UUID = 0,
	CHANNEL_REMOVE_METHOD_HASHID,
};

enum Get_Channel_List_ID_Type
{
	GET_CHANNEL_LISTID_METHOD_TYPE_VOD = 1,
    GET_CHANNEL_LISTID_METHOD_TYPE_LIVE,
	GET_CHANNEL_LISTID_METHOD_TYPE_ALL,
};
enum Get_Channel_list_ID_Method
{
	GET_CHANNEL_LISTID_METHOD_ALL = 1,
    GET_CHANNEL_LISTID_METHOD_START_NO_AUDITINGED, //开播未通过审核频道
    GET_CHANNEL_LISTID_METHOD_START_AUDITINGED,    //未开播审核通过频道
	GET_CHANNEL_LISTID_METHOD_NO_AUDITINGED,         //未审核的频道
    GET_CHANNEL_LISTID_METHOD_NO_START,                //未开播的频道
};
#endif
