/************************************************************************
说明：这个是项目所有宏定义文件
作者：颉小龙
日期：2007－10－15
修改：
记录：
************************************************************************/

#ifndef G3P2P_MACRO_DEFINE_H
#define G3P2P_MACRO_DEFINE_H

//导出类的定义
#if (defined(_WIN32) || defined(__CYGWIN__)) && defined(G3P2P_DLL)
#if defined(G3P2P_EXPORTS)
#define G3P2P_API __declspec(dllexport)
#else
#define G3P2P_API __declspec(dllimport)
#endif
#endif

#if !defined(G3P2P_API)
#define G3P2P_API
#endif

//域名定义
#define G3P2P_BEGIN namespace G3P2P_BY_LONGYU {
#define G3P2P_END   }

#endif
