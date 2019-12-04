#ifndef _LOG_HELPER_H_
#define _LOG_HELPER_H_
#include <iostream>
#include "CommToolsExportDef.h"
//The log buf size
#define LOG_BUF_SIZE 4096

// The log level
enum log_level
{
	LERROR,		// ����
	LWARN,		// ����
	LNOTICE,	// ֪ͨ
	LINFO,		// �����Ϣ
	LDEBUG,		// ��ʽ��Ϣ
};

class COMM_TOOLS_API CLogHelper
{
public:
	static bool read_config_init(const char* confile);
	static void record_log(const std::string& file, const int& line, const std::string module, const log_level& level, const std::string &message);
	static void record_log_with_args(const std::string& file, const int& line, const std::string module, const log_level& level, const std::string &format, ...);
private:
	CLogHelper(){};
	~CLogHelper(){};
};


//record
#ifndef ANDROID_NDK
	#define PROCESS_LOG(module, level, message) CLogHelper::record_log(__FILE__, __LINE__, module, level, message)
	#define PROCESS_ARGS_LOG(module, level, format, ...) CLogHelper::record_log_with_args(__FILE__, __LINE__, module, level, format, ##__VA_ARGS__)
#else
	#define PROCESS_LOG(module, level, message)
	#define PROCESS_ARGS_LOG(module, level, format, ...)
#endif




#endif
