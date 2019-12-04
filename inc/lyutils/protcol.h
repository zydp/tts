/************************************************************************
�ļ�����:ϵͳЭ�鶨���ļ�  
��    ��:�С��
��    ˾:�Ϻ���Ԧ��Ϣ�������޹�˾
�������:
�޸ļ�¼:                                                                    
************************************************************************/
#ifndef G3_PP_PROTCOL_H
#define G3_PP_PROTCOL_H

//Э���ʽ
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

service��ʾ��������
version ��Э��汾��
command : ��Э������
subcmd����Э������
uuid���û�uuid
session:�û�session
dataΪ����Э������
*/
/************************************************************************/
//��Э������
#define G3P2P_MAIN_SERVICES_ALL                  "all"             //���з���
#define G3P2P_MAIN_SERVICES_ROUTER               "router"          //router����
#define G3P2P_MAIN_SERVICES_LOGINSERVER          "loginsvr"        //��½����,ƽ�������
#define G3P2P_MAIN_SERVICES_GROUPSERVER          "groupsvr"        //Ⱥ�����
#define G3P2P_MAIN_SERVICES_LOGSERVER            "logsvr"          //��־������
#define G3P2P_MAIN_SERVICES_CONFIRMSERVER        "confsvr"         //��֤����
#define G3P2P_MAIN_SERVICES_ONLINESERVER         "olsvr"           //���߷���,ptprs
#define G3P2P_MAIN_SERVICES_CHANNELSERVER        "chsvr"           //��ý��Ƶ��������
#define G3P2P_MAIN_SERVICES_MEDIASERVER          "mediasvr"        //��ý�������
#define G3P2P_MAIN_SERVICES_EXTERN_FS            "exterfs"         //��չ��������
#define G3P2P_MAIN_SERVICES_STORAGESERVER        "storage"	       //�洢������
#define G3P2P_MAIN_SERVICES_HLSSEGMENTSERVER     "segsrv"          //��Ƭ������
#define G3P2P_MAIN_SERVICES_AUTHORIZATIONSERVER  "authsvr"         //��Ȩ����
#define G3P2P_MAIN_SERVICES_INFOPUBLISHSERVER    "infosvr"         //��Ϣ����������

//Sub Command������
/**************************router***********************************************/
#define G3P2P_COMMAND_ROUTER_REGISTER              "register"          //ע��
#define G3P2P_COMMAND_ROUTER_UNREGISTER            "unregister"        //ע��
#define G3P2P_COMMAND_ROUTER_INFO_REFERESH         "infref"            //��Ϣ����
#define G3P2P_COMMAND_ROUTER_GET_SERVER_INFO       "ginfo"             //��ȡ��������Ϣ�б�
#define G3P2P_COMMAND_ROUTER_TRANSF_INFO           "transinf"          //��Ϣ��ת
#define G3P2P_COMMAND_ROUTER_STOP                  "stop"              //ֹͣ������
#define G3P2P_COMMAND_ROUTER_GET_INFO_BY_ID_FUC    "ginfobyidfuc"      //ͨ��ID�ͷ��������ܻ�ȡΨһ�ķ�������Ϣ
#define G3P2P_COMMAND_ROUTER_GET_AUTHORIZATION     "gauthor"           //��������Ȩ��Ϣ
#define G3P2P_COMMAND_ROUTER_SET_AUTHORIZATION     "sauthor"           //��������Ȩ��Ϣ

//Router���������ظ���������Ϣ
/*******************************************************************************/
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_SUCCESS          "reg_success"        //ע��ɹ�
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_DENY             "reg_deny"           //ע�ᱻ�ܾ�
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_ERROR_PARAM      "reg_eparam"         //ע���������ȷ
#define G3P2P_COMMAND_ROUTER_RET_REGISETER_LOW_VER          "reg_verout"         //Э��汾����

#define G3P2P_COMMAND_ROUTER_RET_GETSERVERINFO_SUCCESS      "ginfo_success"      //��ȡ��������Ϣ�ɹ�
#define G3P2P_COMMAND_ROUTER_RET_GETSERVERINFO_ERROR_PARAM  "ginfo_eparam"       //��ȡ��������Ϣ��������ȷ
#define G3P2P_COMMAND_ROUTER_RET_GETSERVERINFO_DENY         "ginfo_deny"         //��ȡ��������Ϣ���ܾ�

#define G3P2P_COMMAND_ROUTER_RET_TRANSINFO_ERROR_PARAM      "transinfo_eparam"   //��Ϣ��ת��������ȷ
#define G3P2P_COMMAND_ROUTER_RET_TRANSINFO_DENY             "transinfo_deny"     //��Ϣ��ת���ܾ�
#define G3P2P_COMMAND_ROUTER_RET_TRANSINFO_SUCCESS          "transinfo_success"  //��Ϣ��ת�ɹ�

#define G3P2P_COMMAND_ROUTER_RET_STOP_SUCCESS               "stop_success"       //ֹͣ�ɹ�
#define G3P2P_COMMAND_ROUTER_RET_STOP_FAIL                  "stop_fail"          //ֹͣʧ��

//Router����������������
/*******************************************************************************/
#define G3P2P_COMMAND_ROUTER_TRAN_SERVER_ADD            "svr_add"          //���µķ��������
#define G3P2P_COMMAND_ROUTER_TRAN_SERVER_DEL            "svr_del"          //�з������Ͽ�
#define G3P2P_COMMAND_ROUTER_TRAN_SERVER_INFO_REFRESH   "ser_ifrefresh"    //��������Ϣ����

//peer�˺�Login Banlance server������
/*******************************************************************************/
#define G3P2P_COMMAND_PEER_GET_ONLINE_SERVER  "pgolsvr"  //��ȡһ��Online Server�ĵ�ַ

//login banlance server���ظ�peer������
/*******************************************************************************/
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_SUCCESS      "pgols_sucs"      //��ȡ�ɹ�
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_ERROR_PARAM  "pgolsvr_epm"     //��������
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_NO_OLSA      "pgolsvr_noolsf"  //û�����߷���������
#define G3P2P_COMMAND_LONGINBANLANCE_GET_ONLINE_SERVER_DENY         "pgolsvr_deny"    //���ܾ�

//online server ��Peer�˵�Э��
/*******************************************************************************/
#define  G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER    "plogintols"   //Pee�˵�½���߷�����
#define  G3P2P_COMMAND_ONLINESERVER_LOGOUT_TO_SERVER   "plogouttols"  //Peer��ע�����߷�����
#define  G3P2P_COMMAND_ONLINESERVER_KEEP_LIVE          "pkpltols"     //Peer�˷�������
#define  G3P2P_COMMAND_ONLINESERVER_GET_FUNSERID       "pgfsidl"      //peer ��ȡ���ܷ�����ID
#define  G3P2P_COMMAND_ONLINESERVER_GET_FUNSER_INFO    "pgfsfi"       //Peer�˻�ȡһ�����ܷ�������Ϣ

//Online server���ظ�Peer�˵�����
/*******************************************************************************/
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_SUCCESS         "plogtols_sucs"   //��½�ɹ�
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_ERROR_PARAM     "plogtols_epm"    //��½��������
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_OUT_VERSION     "plogtols_outver" //�汾����
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_ERROR_USER      "plogtols_euser"  //������û�����������
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_DENY            "plogtols_deny"   //��½���ܾ�
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_MAX_CLIENT      "plogtols_maxc"   //�������ﵽ�������
#define G3P2P_COMMAND_ONLINESERVER_LOGIN_TO_SERVER_MAX_TCP_CLIENT  "plogtols_maxtc"  //�������ﵽ���TCP��������
#define G3P2P_COMMAND_ONLINESERVER_RELOGIN                         "polstp_relogin"  //�û������ڱ�ĵط���½

#define G3P2P_COMMAND_ONLINESERVER_RET_FUNINFOID_SUCCESS           "pgfidl_sucs"     //��ȡ���ܷ�����ID List�ɹ�
#define G3P2P_COMMAND_ONLINESERVER_RET_FUNINFO_SUCCESS             "pgfif_sucs"      //��ȡ��������Ϣ�ɹ�
#define G3P2P_COMMAND_ONLINESERVER_RET_FUNINFOID_NOFUN             "pgfidl_nof"      //û�ҵ���Ӧ�ķ�����
#define G3P2P_COMMAND_ONLINESERVER_RET_FUNSERINFO_NOFUN            "pgfif_nof"       //û�ҵ���Ӧ�ķ�����

#define G3P2P_COMMAND_PEER_KEEPLIVE_ONLINESERVER                   "pkpltols"        //Peer��keeplive
#define G3P2P_COMMAND_ONLINESERVER_RET_KEEP_LIVE                   "olskl_ret"       //Onlineserver����keeplive

//group server��group client��Э��
/*******************************************************************************/
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP                "gctg_crt"     //����һ��Ⱥ��
#define G3P2P_COMMAND_GROUPSERVER_CREATEANDJOIN_GROUP         "gctg_caj"     //����������Ⱥ��
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP               "gctg_dstry"   //ɾ��һ��Ⱥ��
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP                  "gctg_join"    //����һ��Ⱥ��
#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP                  "gctg_quit"    //�˳�һ��Ⱥ��
#define G3P2P_COMMAND_GROUPSERVER_COMMAND_IN_GROUP            "gctg_ingrp"   //Ⱥ�ڲ���Ϣ
#define G3P2P_COMMAND_GROUPSERVER_COMMAND_REPORT_FILE_LIST    "gctg_rfl"     //Vod �ļ��б�

//Vod Client�� Vod Group��Э��
/*******************************************************************************/
#define G3P2P_COMMAND_GROUPSERVER_GETPEER                "gctg_gpl"   //��ȡPeer��Դ
#define G3P2P_COMMAND_GROUPSERVER_SHOTTO                 "gctg_st"    //������
#define G3P2P_COMMAND_GROUPSERVER_UPDATEFILE_CACHE       "gctg_ufc"   //�����ļ�����״̬
#define G3P2P_COMMAND_GROUPSERVER_CHANGE_VOD_FILE        "gctg_cvf"   //�ı�vod�ļ�
#define G3P2P_COMMAND_GROUPSERVER_CHANGE_VOD_START       "gctg_sttv"  //��ʼVOD�㲥
#define G3P2P_COMMAND_GROUPSERVER_CHANGE_VOD_STOP        "gctg_stpv"  //ֹͣVOD�㲥
#define G3P2P_COMMAND_GROUPSERVER_UPDATE_DATATRANS_PORT  "gctg_udtp"  //�������ݴ���˿�

//group server���ظ�group client��Э��
/*******************************************************************************/
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_SUCCESS         "gtgc_crt_sucs"     //����Ⱥ�ɹ�
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_OUT_VERSION     "gtgc_crt_outver"   //�汾����
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_ERROR_PARAM     "gtgc_crt_eparam"   //��������
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_DENY            "gtgc_crt_deny"     //�������ܾ�
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_MAX_GROUP       "gtgc_crt_maxg"     //Ⱥ������
#define G3P2P_COMMAND_GROUPSERVER_CREATE_GROUP_FAIL            "gtgc_crt_fail"     //����ʧ��

#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_SUCCESS           "gtgc_join_sucs"    //����Ⱥ��ɹ�
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_DENY              "gtgc_join_deny"    //����Ⱥ�鱻�ܾ�
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_OUT_VERSION       "gtgc_join_outver"  //����Ⱥ��汾����
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_EPSWD             "gtgc_join_epswd"   //����Ⱥ���������
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_ERROR_PARAM       "gtgc_join_eparam"  //����Ⱥ���������
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_MAX_CLIENT        "gtgc_join_maxc"    //Ⱥ����������
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_NOEXIST           "gtgc_join_nest"    //Ҫ�����Ⱥ�鲻����
#define G3P2P_COMMAND_GROUPSERVER_JOIN_GROUP_FAIL              "gtgc_join_fail"    //����ʧ��,ԭ��δ֪

#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_SUCCESS        "gtgc_dstry_sucs"   //����Ⱥ��ɹ�
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_NOCREATOR      "gtgc_dstry_nocrtr" //����Ⱥ��ʧ��,�Ǵ�����
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_NOEXIST        "gtgc_dstry_noest"  //Ҫ���ٵ�Ⱥ�鲻����
#define G3P2P_COMMAND_GROUPSERVER_DESTROY_GROUP_EPARAM         "gtgc_dstry_ep"     //Ҫ���ٵ�Ⱥ�鲻����

#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP_SUCCESS           "gtgc_quit_sucs"    //�˳���Ⱥ�ɹ�
#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP_NOEXIST           "gtgc_quit_noest"   //Ҫ�˳���Ⱥ�鲻����
#define G3P2P_COMMAND_GROUPSERVER_QUIT_GROUP_ERROR_PARAM       "gtgc_quit_ep"      //�����������

#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_SUCCESS     "gtgc_rfl_sucs"     //�����ļ��б�ɹ�
#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_FAIL        "gtgc_rfl_fail"     //�����ļ��б�ʧ��
#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_EP          "gtgc_rfl_ep"       //�����ļ��б��������
#define G3P2P_COMMAND_GROUPSERVER_REPORT_FILE_LIST_DENY        "gtgc_rfl_deny"     //�����ļ��б��ܾ�

#define G3P2P_COMMAND_GROUPSERVER_GETPEER_SUCCESS              "gctg_gpl_sucs"     //��ȡPeer��Դ�ɹ�

//Channel Server�� channel publisher ��Э�� 
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH                "cptc_pblsh"       //����һ��Ƶ��
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE                 "cptc_rm"          //ɾ��һ��Ƶ��
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO   "cptc_ufi"         //����VOD�ļ���Ϣ
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE                 "cptc_up"          //����Ƶ����Ϣ

//Vod Client ��Channel Server��Э��
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNELID_LIST            "ctcs_gcl"    //��ȡƵ��ID�б�
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_INFO              "ctcs_gci"    //��ȡƵ����Ϣ
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_VOD_FILE_LIST     "ctcs_gvfl"   //��ȡVod�ļ��б�
#define G3P2P_COMMAND_CHANNELSERVER_GET_CHANNEL_GET_GROUP_SERVER  "ctcs_ggsi"   //��ȡgroupserverinfo

//Channel Server���ظ�vod client��Э��
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

//Channel Server���ظ�channel publisher��Э��
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_SUCCESS      "cptc_pblsh_sucs"    //����һ��Ƶ���ɹ�
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_DENY         "cptc_pblsh_deny"    //����Ƶ�����ܾ�
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_ERROR_PARAM  "cptc_pblsh_ep"      //����Ƶ������������
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_EXIST        "cptc_pblsh_exist"   //Ƶ���Ѿ�����
#define G3P2P_COMMAND_CHANNELSERVER_PUBLISH_FAIL         "cptc_pblsh_fail"    //����Ƶ��ʧ��

#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_SUCCESS       "cptc_rm_sucs"       //ɾ��һ��Ƶ���ɹ�
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_DENY          "cptc_rm_deny"       //ɾ��һ��Ƶ�����ܾ�
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_ERROR_PARAM   "cptc_rm_ep"         //ɾ��һ��Ƶ����������
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_NO_EXIST      "cptc_rm_ne"         //Ҫɾ����Ƶ��������
#define G3P2P_COMMAND_CHANNELSERVER_REMOVE_FAIL          "cptc_rm_fail"       //Ҫɾ��Ƶ��ʧ��

#define G3P2P_COMMAND_CHANNELSERVER_START_SUCCESS        "cptc_st_sucs"       //����һ��Ƶ���ɹ�
#define G3P2P_COMMAND_CHANNELSERVER_START_FAIL           "cptc_st_fail"       //����һ��Ƶ��ʧ��

#define G3P2P_COMMAND_CHANNELSERVER_STOP_SUCCESS         "cptc_sp_sucs"       //ͣ��һ��Ƶ���ɹ�
#define G3P2P_COMMAND_CHANNELSERVER_STOP_FAIL            "cptc_sp_fail"       //����һ��Ƶ��ʧ��

#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_SUCCESS       "cptc_up_sucs"       //����Ƶ����Ϣ�ɹ�
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_DENY          "cptc_up_deny"       //����ʧ��
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_FAIL          "cptc_up_fail"       //����һ��Ƶ��ʧ��
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_NO_EXIST      "cptc_up_nexist"     //����Ƶ��������
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_ERROR_PARAM   "cptc_up_ep"         //����Ƶ����������

#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_SUCCESS       "cptc_uvfi_sucs"    //����VOD�ļ���Ϣ�ɹ�
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_DENY          "cptc_uvfi_deny"    //����VOD�ļ���Ϣ���ܾ�
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_ERROR_PARAM   "cptc_uvfi_ep"      //����VOD�ļ���Ϣ��������
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_NOEXIST       "cptc_uvfi_nest"    //����VOD�ļ���ϢƵ��������
#define G3P2P_COMMAND_CHANNELSERVER_UPDATE_VOD_FILE_INFO_FAIL          "ptc_uvfi_fail"     //����VOD�ļ���Ϣʧ��


//Channel Server���ظ�channel client��Э��
/*******************************************************************************/
#define G3P2P_COMMAND_CHANNELSERVER_GET_GSERVER          "cptc_gs_gs"         //��ȡgroup server
#define G3P2P_COMMAND_CHANNELSERVER_GET_SUCCESS          "cptc_gs_sucs"       //��ȡgroup server�ɹ�
#define G3P2P_COMMAND_CHANNELSERVER_GET_NOGS             "cptc_gs_ngs"        //û�п��õ�group server
#define G3P2P_COMMAND_CHANNELSERVER_GET_FAIL             "cptc_gs_fail"       //��ȡgroup server ʧ��


//Info Publish Server ��Info Publish Client��Э��
/*******************************************************************************/
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER    "plogintoips"   //Pee�˵�½���߷�����
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_LOGOUT_TO_SERVER   "plogouttoips"  //Peer��ע�����߷�����
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_KEEP_LIVE          "pkpltoips"     //Peer�˷�������
#define  G3P2P_COMMAND_INFOPUBLISHSERVER_SEND_CMD_TO_CLIENT "ipscmdtop"     //Server���͸�Peerָ��

//Info Publish Server���ظ�Peer�˵�����
/*******************************************************************************/
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_SUCCESS         "plogtoips_sucs"     //��½�ɹ�
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_ERROR_PARAM     "plogtoips_epm"      //��½��������
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_OUT_VERSION     "plogtoips_outver"   //�汾����
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_ERROR_USER      "plogtoips_euser"    //������û�����������
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_DENY            "plogtoips_deny"     //��½���ܾ�
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_MAX_CLIENT      "plogtoips_maxc"     //�������ﵽ�������
#define G3P2P_COMMAND_INFOPUBLISHSERVER_LOGIN_TO_SERVER_MAX_TCP_CLIENT  "plogtoips_maxtc"    //�������ﵽ���TCP��������
#define G3P2P_COMMAND_INFOPUBLISHSERVER_RELOGIN                         "plogtoips_relogin"  //�û������ڱ�ĵط���½

#define G3P2P_COMMAND_PEER_KEEPLIVE_INFOPUBLISHSERVER                   "pkpltoips"        //Peer��keeplive
#define G3P2P_COMMAND_INFOPUBLISHSERVER_RET_KEEP_LIVE                   "ipskl_ret"        //server����keeplive


//channel ���²���
enum Channel_Update_Method
{
	CHANNEL_UPDATE_METHOD_ALL = 0,  //ȫ������
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
    GET_CHANNEL_LISTID_METHOD_START_NO_AUDITINGED, //����δͨ�����Ƶ��
    GET_CHANNEL_LISTID_METHOD_START_AUDITINGED,    //δ�������ͨ��Ƶ��
	GET_CHANNEL_LISTID_METHOD_NO_AUDITINGED,         //δ��˵�Ƶ��
    GET_CHANNEL_LISTID_METHOD_NO_START,                //δ������Ƶ��
};
#endif
