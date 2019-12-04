#include "PapereaderVersion.h"
#include "PapereaderGlobalDef.h"

const char* PapereaderVersionString()
{
	string strTime = GetCurTimeBuild();
	string strConfig;
#ifdef _DEBUG
	strConfig = "Debug";
#else
	strConfig = "Release";
#endif

	static char aVersion[128];
#ifdef WIN32
	sprintf_s(aVersion, "%s-%s-%s-%s-%s", MODULE_LOG_TAG, PAPEREADER_VERSION, GetCurTimeBuild().c_str(), strConfig.c_str(), VERSION_SVN);
#else
	sprintf(aVersion, "%s-%s-%s-%s-%s", MODELNAME, PAPEREADER_VERSION, GetCurTimeBuild().c_str(), strConfig.c_str(), VERSION_SVN);
#endif
	return aVersion;
}
int PapereaderVersionInt()
{
	return PAPEREADER_VERSION_INT;
}
