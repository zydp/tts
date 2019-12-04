#ifndef __SYS_TYPES_H_
#define __SYS_TYPES_H_

/*!
  Signed integer, weight is 8 bits. In most case it equal to char.
  */
typedef signed char LYS8;

/*!
  Unsigned integer, weight is 8 bits. In most case it equal to unsigned char.
  */
typedef unsigned char LYU8;

/*!
  Signed integer, weight is 16 bits. In most case it equal to short.
  */
typedef signed short LYS16;

/*!
  Unsigned integer, weight is 16 bits. In most case it equal to unsigned short.
  */
typedef unsigned short LYU16;

/*!
  Signed integer, weight is 32 bits.
  */
typedef signed int LYS32;

/*!
  Unsigned integer, weight is 32 bits.
  */
typedef unsigned int LYU32;
/*!
  Signed integer, weight is 64 bits
  */
typedef signed long long LYS64;
/*!
  Usigned integer, weight is 64 bits
  */
typedef unsigned long long LYU64;

/*!
  Boolean type, the value should be FALSE and TRUE. Recommand replace BOOL by
  RET_CODE as return value.
  */
typedef int LYBOOL;

/*!
  void type
  */
typedef void LYVOID;

/*!
  Instance handle type
  */
typedef void * LYHANDLE;

/*!
  Boolean false
  */
#ifndef  LYFALSE
/*!
  Boolean false
  */
#define LYFALSE (0)             
#endif

/*!
  Boolean true
  */
#ifndef  LYTRUE
#define LYTRUE (1)
#endif

/*!
  Invalid value
  */
#ifndef LYINVALID
#define LYINVALID (~0)
#endif

/*!
  Null pointer type
  */
#ifndef LYNULL
#define LYNULL    NULL
#endif

/*!
  Return code type. Please reference return code macro for the values.
  */
#define LYRET_CODE S32

/*!
  Success return
  */
#define LYSUCCESS ((S32)0)       
/*!
  Fail for common reason
  */
#define LYERR_FAILURE ((S32)-1)  
/*!
  Fail for waiting timeout
  */     
#define LYERR_TIMEOUT ((S32)-2)      
/*!
  Fail for function param invalid
  */ 
#define LYERR_PARAM ((S32)-3) 
/*!
  Fail for module status invalid
  */      
#define LYERR_STATUS ((S32)-4)  
/*!
  Fail for module busy
  */     
#define LYERR_BUSY ((S32)-5)
/*!
  Fail for no enough memory
  */
#define LYERR_NO_MEM ((S32)-6)  
/*!
  Fail for no enough resource
  */     
#define LYERR_NO_RSRC ((S32)-7)
/*!
  Fail for hardware error
  */ 
#define LYERR_HARDWARE ((S32)-8) 
/*!
  Fail for feature not support
  */      
#define LYERR_NOFEATURE ((S32)-9)       

#endif
