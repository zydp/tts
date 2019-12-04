#ifndef _GOLD_DEBUG_H
#define _GOLD_DEBUG_H
#include <stdio.h>
#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

	//#define GI_DEBUG

#ifdef _DEBUG

#define LY_DEBUG_POINT(s) printf("%s  [File:%s Line:%d] Function:%s\n\n",s, __FILE__, __LINE__, __FUNCTION__)
#define LY_DEBUG_PRINTF(arg) printf(arg)

#define LY_ASSERT(expr) \
	do{ \
	if (!(expr)) { \
	printf("\nASSERT failed at:\n >File name: %s\n >Function : %s\n >Line No. : %d\n >Condition: %s\n", \
	__FILE__,__FUNCTION__, __LINE__, #expr);\
	} \
	}while(0);
#define LY_DEBUG_PAUSE() \
	do \
	{ \
	LY_DEBUG_POINT("pause for debug, press 'q' to exit!\n"); \
	char c; \
	while( ( c = getchar() ) ) \
	{ \
	if('q' == c) \
	{ \
	getchar(); \
	break; \
} \
} \
}while(0);
#define LY_DEBUG_PAUSE_ARG(arg) \
	do \
	{ \
	printf(arg); \
	LY_DEBUG_PAUSE() \
}while(0);


#define LY_DEBUG_ASSERT(expression) \
	if(!(expression)) \
	{ \
	printf("[ASSERT],%s,%s:%d\n", __FILE__, __FUNCTION__, __LINE__);\
	exit(-1); \
}
#else
#define LY_DEBUG_PRINTF(arg)
#define LY_ASSERT(expr)
#define LY_DEBUG_PAUSE()
#define GI_DEBUG_PAUSE_ARG(arg)
#define LY_DEBUG_POINT(arg)
#define dbg_printf(arg)
#define LY_DEBUG_ASSERT(expression)

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif 