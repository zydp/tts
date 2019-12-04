#ifndef _COMM_TOOLS_EXPORT_DEF_H_
#define _COMM_TOOLS_EXPORT_DEF_H_

#if (defined(_WIN32) || defined(__CYGWIN__))
#if defined(COMMTOOLS_EXPORTS)
#define COMM_TOOLS_API __declspec(dllexport)
#else
#define COMM_TOOLS_API __declspec(dllimport)
#endif
#endif

#ifndef COMM_TOOLS_API
#define COMM_TOOLS_API
#endif

#endif
