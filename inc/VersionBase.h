#ifndef VERSION_BASE_H
#define VERSION_BASE_H
#include "SvnVersion.h"
#define VERSION_INT(a, b, c) ((a)<<16 | (b)<<8 | (c))
#define VERSION_DOT(a, b, c) #a"."#b"."#c
#define VERSION(a, b, c) VERSION_DOT(a, b, c)
#define TOSTRING(s) #s
#ifdef  WIN32 
#include <stdio.h>
#include <windows.h>
#include <winbase.h>
#else 
#include <stdio.h>
#include <time.h>
#endif //  WIN32
#include <string>
using namespace std;
inline string GetCurTimeBuild()
{	
	return BUILD_DATE;
}
#endif