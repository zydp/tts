/************************************************************************
说明：这个是一个通用函数类
作者：颉小龙
日期：2014－10－15
修改：
记录：
************************************************************************/
#ifndef G3P2P_UTIL_H
#define G3P2P_UTIL_H
#ifdef LYANDROID_NDK
#include "android_types.h"
#endif

#include "LySysTypes.h"
#include "win32_types.h"

#include "macrodefine.h"
#include "globaldebug.h"
#include "globaldef.h"

#ifdef  WIN32
#include <windows.h>
#include <direct.h>

#else 
#ifdef LYANDROID_NDK
#include <pthread.h>
#include <semaphore.h>
#include<signal.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>
#include <string>
#include <linux/limits.h>
#include <sys/time.h>
#else
#include <pthread.h>
#include <semaphore.h>
#include<signal.h>

#ifndef __iOS__
#include <curses.h>
#include <sys/dir.h>
#include <linux/limits.h>
#endif

#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>
#include <string>
#include <sys/time.h>
#endif
#endif

#include <errno.h>
#include <set>
#include <vector>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <map>

//using namespace std;
#ifdef _MSC_VER
#pragma warning(disable:4251)
#pragma warning(disable:4996)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
#endif
//namespace
#define G3P2P_UTIL_BEGIN namespace G3P2P_BY_LONGYU_UTIL {
#define G3P2P_UTIL_END   }

G3P2P_BEGIN
G3P2P_UTIL_BEGIN

//互斥对象类
 class G3P2P_API CCommonMutex  
{
#ifdef  WIN32
	CRITICAL_SECTION    m_thdMutex;         //线程互斥对象
#else
	pthread_mutex_t     m_thdMutex;
#endif

public:
	bool UnLockObject();
	bool LockObject();
	CCommonMutex();
	virtual ~CCommonMutex();
};

//事件类
 class G3P2P_API CCommonEvent  
{
#ifdef  WIN32
	HANDLE  m_hEvent;
#else
	sem_t   m_hEvent;
#endif

public:
	bool WaitForEventSignaled();
	bool WaitForEventSignaled(int nMillonSecond);
	bool SetEvent();
	bool ResetEvent();
	CCommonEvent();
	virtual ~CCommonEvent();
};

//ID管理类
 class G3P2P_API CIDRecycle  
{
public:
	CIDRecycle();
	virtual ~CIDRecycle();
	//方法
public:
	//创建一个新的ID
	int CreateNewID(void);

	//回收一个ID
	void RecycleID(int nID);

	//清空回收站
	void Reset(int nID);

protected:
	DWORD	m_nIncID;					//唯一标识
	std::set<DWORD> m_aryRecycle;		    	//回收站
	CCommonMutex m_recycleSafe;			//回收安全
};
 #define TCP_PACKET_HEAD_LEN 12
// #define TCP_PACKET_LENGTH_LEN 19

//数组链表

class G3P2P_API CByteArray 
{
public:
	// Construction
	CByteArray();
	// Attributes
	int GetSize() const;
	int GetUpperBound() const;
	void SetSize(int nNewSize, int nGrowBy = -1);
	// Operations
	// Clean up
	void FreeExtra();
	void RemoveAll();

	// Accessing elements
	BYTE GetAt(int nIndex) const;
	void SetAt(int nIndex, BYTE newElement);

	BYTE& ElementAt(int nIndex);

	// Direct Access to the element data (may return NULL)
	const BYTE* GetData() const;
	BYTE* GetData();

	// Potentially growing the array
	void SetAtGrow(int nIndex, BYTE newElement);

	int Add(BYTE newElement);

	int Append(const CByteArray& src);
	void Copy(const CByteArray& src);

	// overloaded operator helpers
	BYTE operator[](int nIndex) const;
	BYTE& operator[](int nIndex);

	// Operations that move elements around
	void InsertAt(int nIndex, BYTE newElement, int nCount = 1);

	void RemoveAt(int nIndex, int nCount = 1);
	void InsertAt(int nStartIndex, CByteArray* pNewArray);

	// Implementation
protected:
	BYTE* m_pData;   // the actual array of data
	int m_nSize;     // # of elements (upperBound - 1)
	int m_nMaxSize;  // max allocated
	int m_nGrowBy;   // grow amount


public:
	~CByteArray();

protected:
	// local typedefs for class templates
	typedef BYTE BASE_TYPE;
	typedef BYTE BASE_ARG_TYPE;
};


////////////////////////////////////////////////////////////////////////////

class G3P2P_API CWordArray 
{
public:

	// Construction
	CWordArray();

	// Attributes
	int GetSize() const;
	int GetUpperBound() const;
	void SetSize(int nNewSize, int nGrowBy = -1);

	// Operations
	// Clean up
	void FreeExtra();
	void RemoveAll();

	// Accessing elements
	WORD GetAt(int nIndex) const;
	void SetAt(int nIndex, WORD newElement);

	WORD& ElementAt(int nIndex);

	// Direct Access to the element data (may return NULL)
	const WORD* GetData() const;
	WORD* GetData();

	// Potentially growing the array
	void SetAtGrow(int nIndex, WORD newElement);

	int Add(WORD newElement);

	int Append(const CWordArray& src);
	void Copy(const CWordArray& src);

	// overloaded operator helpers
	WORD operator[](int nIndex) const;
	WORD& operator[](int nIndex);

	// Operations that move elements around
	void InsertAt(int nIndex, WORD newElement, int nCount = 1);

	void RemoveAt(int nIndex, int nCount = 1);
	void InsertAt(int nStartIndex, CWordArray* pNewArray);

	// Implementation
protected:
	WORD* m_pData;   // the actual array of data
	int m_nSize;     // # of elements (upperBound - 1)
	int m_nMaxSize;  // max allocated
	int m_nGrowBy;   // grow amount


public:
	~CWordArray();

protected:
	// local typedefs for class templates
	typedef WORD BASE_TYPE;
	typedef WORD BASE_ARG_TYPE;
};

////////////////////////////////////////////////////////////////////////////

class G3P2P_API CDWordArray
{
public:

	// Construction
	CDWordArray();

	// Attributes
	int GetSize() const;
	int GetUpperBound() const;
	void SetSize(int nNewSize, int nGrowBy = -1);

	// Operations
	// Clean up
	void FreeExtra();
	void RemoveAll();

	// Accessing elements
	DWORD GetAt(int nIndex) const;
	void SetAt(int nIndex, DWORD newElement);

	DWORD& ElementAt(int nIndex);

	// Direct Access to the element data (may return NULL)
	const DWORD* GetData() const;
	DWORD* GetData();

	// Potentially growing the array
	void SetAtGrow(int nIndex, DWORD newElement);

	int Add(DWORD newElement);

	int Append(const CDWordArray& src);
	void Copy(const CDWordArray& src);

	// overloaded operator helpers
	DWORD operator[](int nIndex) const;
	DWORD& operator[](int nIndex);

	// Operations that move elements around
	void InsertAt(int nIndex, DWORD newElement, int nCount = 1);

	void RemoveAt(int nIndex, int nCount = 1);
	void InsertAt(int nStartIndex, CDWordArray* pNewArray);

	// Implementation
protected:
	DWORD* m_pData;   // the actual array of data
	int m_nSize;     // # of elements (upperBound - 1)
	int m_nMaxSize;  // max allocated
	int m_nGrowBy;   // grow amount


public:
	int GetCount();
	DWORD GetHead();
	DWORD GetTail();
	~CDWordArray();

protected:
	// local typedefs for class templates
	typedef DWORD BASE_TYPE;
	typedef DWORD BASE_ARG_TYPE;
};

class G3P2P_API CLPtrArray 
{
public:

	// Construction
	CLPtrArray();

	// Attributes
	int GetSize() const;
	int GetUpperBound() const;
	void SetSize(int nNewSize, int nGrowBy = -1);

	// Operations
	// Clean up
	void FreeExtra();
	void RemoveAll();

	// Accessing elements
	void* GetAt(int nIndex) const;
	void SetAt(int nIndex, void* newElement);

	void*& ElementAt(int nIndex);

	// Direct Access to the element data (may return NULL)
	const void** GetData() const;
	void** GetData();

	// Potentially growing the array
	void SetAtGrow(int nIndex, void* newElement);

	int Add(void* newElement);

	int Append(const CLPtrArray& src);
	void Copy(const CLPtrArray& src);

	// overloaded operator helpers
	void* operator[](int nIndex) const;
	void*& operator[](int nIndex);

	// Operations that move elements around
	void InsertAt(int nIndex, void* newElement, int nCount = 1);

	void RemoveAt(int nIndex, int nCount = 1);
	void InsertAt(int nStartIndex, CLPtrArray* pNewArray);

	// Implementation
protected:
	void** m_pData;   // the actual array of data
	int m_nSize;     // # of elements (upperBound - 1)
	int m_nMaxSize;  // max allocated
	int m_nGrowBy;   // grow amount


public:
	void* RemoveHead();
	void RemoveTail();
	~CLPtrArray();

protected:
	// local typedefs for class templates
	typedef void* BASE_TYPE;
	typedef void* BASE_ARG_TYPE;
};

#define  BLOCKNUM  800
class 	G3P2P_API CLinkQueue
{
public:
	CLinkQueue();
	~CLinkQueue();

	BOOL Push(void *data);
	void * Pop();
	BOOL IsEmpty();
	
private:
	void *m_pData[BLOCKNUM];
	int m_nInIndex;
	int m_nOutIndex;
};
//配置文件操作
/*定义操作类*/
class G3P2P_API CIniFile
{
	//构造与析构函数
public:
	CIniFile();
	CIniFile(const char* sFileName);
	virtual ~CIniFile();

	//定义私有数据成员
protected:
	//定义行结构
	struct LINE_ITEM
	{
		int 	nType;		//类型
		std::string	sName;		//名称
		std::string sValue;		//值
	};
	CLPtrArray  m_arrayOfLine;	//存放配置文件中的所有行
	std::string		m_sFileName;	//配置文件名称
	int				m_nTotalSection;//总区域数
	bool			m_bAutoFlush;	//是否自动刷新到文件?
	bool			m_bModified;	//是否修改过

	//文件操作方法
public:
	//重新初始化本对象
	void Reset(void);
	//载入配置文件,成功返回0,失败返回小于0的值
	int LoadFromFile(const char* sFileName);
	//刷新当前配置项到文件中,成功返回0,失败返回涉于0的值
	int FlushToFile(void);

	//区域和配置项操作方法
private:
	//根据区域名称,取得所在行号
	int GetSectionIndex(int nStartLine, const char* sSectionName);
	//根据区域行号及配置项名称,取得配置项所在行号
	int GetKeyIndex(int nSectionIndex, const char* sKeyName);
public:
	//取得总区域数
	int GetSectionCount(void);
	//取得区域名称
	std::string GetSectionName(int nIndex);
	//取得指定区域中总配置项数
	int GetKeyCount(const char* sSectionName);
	//取得配置项名称
	std::string GetKeyName(const char* sSectionName, int nIndex);
	//删除一个配置项
	int DelKey(const char* sSectionName, const char* sKeyName);
	//增加一个区域,返回索引值,失败返回小于0的值
	int AddSection(const char* sSectionName);
	//删除一个区域
	void DelSection(const char* sSectionName);

	//配置项值操作方法
public:
	//取得配置项的值(字符串)
	std::string GetString(const char* sSectionName, const char* sKeyName);
	//取得配置项的值(整数)
	int GetInt(const char* sSectionName, const char* sKeyName);
	//取得配置项的值(布尔)
	bool GetBool(const char* sSectionName, const char* sKeyName);
	//设置配置项的值(字符串)
	void SetString(const char* sSectionName, const char* sKeyName, const char* sKeyValue);
	//设置配置项的值(整数)
	void SetInt(const char* sSectionName, const char* sKeyName, int nKeyValue);
	//设置配置项的值(布尔)
	void SetBool(const char* sSectionName, const char* sKeyName, bool bKeyValue);
};

//xml
 using namespace std;

 struct _tagXMLAttr;
 typedef _tagXMLAttr XAttr, *LPXAttr;
 typedef std::vector<LPXAttr> XAttrs;

 struct _tagXMLNode;
 typedef _tagXMLNode XNode, *LPXNode;
 typedef std::vector<LPXNode> XNodes, *LPXNodes;

 struct _tagXMLDocument;
 typedef struct _tagXMLDocument XDoc, *LPXDoc;

 // Entity Encode/Decode Support
 typedef struct _tagXmlEntity
 {
	 char entity;                    // entity ( & " ' < > )
	 char ref[10];                   // entity reference ( &amp; &quot; etc )
	 int ref_len;                    // entity reference length
 }XENTITY,*LPXENTITY;

 typedef struct _tagXMLEntitys : public std::vector<XENTITY>
 {
	 LPXENTITY GetEntity( int entity );
	 LPXENTITY GetEntity( const char* entity );
	 int GetEntityCount( const char* str );
	 int Ref2Entity( const char* estr, const char* str, int strlen );
	 int Entity2Ref( const char* str, const char* estr, int estrlen );
	 string Ref2Entity( const char* estr );
	 string Entity2Ref( const char* str );

	 _tagXMLEntitys(){};
	 _tagXMLEntitys( LPXENTITY entities, int count );
 }XENTITYS,*LPXENTITYS;

 typedef enum
 {
	 PIE_PARSE_WELFORMED = 0,
	 PIE_ALONE_NOT_CLOSED,
	 PIE_NOT_CLOSED,
	 PIE_NOT_NESTED,
	 PIE_ATTR_NO_VALUE
 }PCODE;

 // display optional environment
 typedef struct  _tagDispOption
 {
	 bool newline;               // newline when new tag
	 bool reference_value;       // do convert from entity to reference ( < -> &lt; )
	 char value_quotation_mark;  // val="" (default value quotation mark "
	 LPXENTITYS entitys;         // entity table for entity encode

	 int tab_base;               // internal usage
	 _tagDispOption();
 }DISP_OPT, *LPDISP_OPT;

 // Parse info.
 typedef struct  _tagParseInfo
 {
	 bool        trim_value;         // [set] do trim when parse?
	 bool        entity_value;       // [set] do convert from reference to entity? ( &lt; -> < )
	 LPXENTITYS  entitys;            // [set] entity table for entity decode
	 char        escape_value;       // [set] escape value (default '\\')
	 bool        force_parse;        // [set] force parse even if xml is not welformed

	 const char* xml;                // [get] xml source
	 bool        erorr_occur;        // [get] is occurance of error?
	 const char* error_pointer;      // [get] error position of xml source
	 PCODE       error_code;         // [get] error code
	 string      error_string;       // [get] error string

	 LPXDoc      doc;
	 _tagParseInfo() ;
 }PARSEINFO,*LPPARSEINFO;



 // XAttr : Attribute Implementation
 typedef struct _tagXMLAttr
 {
	 string name;
	 string value;

	 _tagXMLNode* parent;

	 string GetXML( LPDISP_OPT opt);
 }XAttr, *LPXAttr;

 typedef enum
 {
	 XNODE_ELEMENT,              // general node '<element>...</element>' or <element/>
	 XNODE_PI,                   // <?xml version="1.0" ?>
	 XNODE_COMMENT,              // <!-- comment -->
	 XNODE_CDATA,                // <![CDATA[ cdata ]]>
	 XNODE_DOC,                  // internal virtual root
 }NODE_TYPE;

 // XMLNode structure
 typedef struct G3P2P_API _tagXMLNode
 {
	 // name and value
	 string name;
	 string value;

	 // internal variables
	 LPXNode parent;     // parent node
	 XNodes childs;      // child node
	 XAttrs attrs;       // attributes
	 NODE_TYPE type;     // node type
	 LPXDoc doc;         // document
	 static LPDISP_OPT opt;
	 static LPPARSEINFO pi;
	 LPDISP_OPT GetDispOpt();
	 LPPARSEINFO GetParseInfo();
	 void DisableEscape();
	 void EnableEscape();
	 static BOOL Init();
	 static BOOL FInit();

	 // Load/Save XML
	 const char* Load( const char* pszXml);
	 string GetXML();
	 string GetText();

	 // in own value
	 int GetInt();
	 void SetInt(int intvalue);
	 unsigned int GetUint();
	 void SetUint(UINT32 uintvalue);

	 // internal load functions
	 const char* LoadAttributes( const char* pszAttrs);
	 const char* LoadAttributes( const char* pszAttrs, const char* pszEnd);
	 const char* LoadProcessingInstrunction( const char* pszXml );
	 const char* LoadComment( const char* pszXml);
	 const char* LoadCDATA( const char* pszXml );

	 // in own attribute list
	 LPXAttr GetAttr( const char* attrname );
	 const char* GetAttrValue( const char* attrname );
	 XAttrs GetAttrs( const char* name );

	 // in one level child nodes
	 LPXNode GetChild( const char* name );
	 const char* GetChildValue( const char* name );
	 string GetChildText( const char* name);
	 void   SetChildText(const char * name,const char * textvalue);
	 int GetChildInt(const char* name);
	 void SetChildInt(const char * name,int intvalue);
	 UINT32 GetChildUint(const char* name);
	 void SetChildUint(const char * name, UINT32 uintvalue);
	 
	 XNodes GetChilds( const char* name );
	 XNodes GetChilds();

	 LPXAttr GetChildAttr( const char* name, const char* attrname );
	 const char* GetChildAttrValue( const char* name, const char* attrname );

	 // search node
	 LPXNode Find( const char* name );

	 // modify DOM
	 int     GetChildCount();
	 LPXNode GetChild( int i );
	 XNodes::iterator GetChildIterator( LPXNode node );
	 LPXNode CreateNode( const char* name = NULL, const char* value = NULL );
	 LPXNode AppendChild( const char* name = NULL, const char* value = NULL );
	 LPXNode AppendChild( LPXNode node );
	 bool    RemoveChild( LPXNode node );
	 LPXNode DetachChild( LPXNode node );

	 // node/branch copy
	 void    CopyNode( LPXNode node );
	 void    CopyBranch( LPXNode branch );
	 void    _CopyBranch( LPXNode node );
	 LPXNode AppendChildBranch( LPXNode node );

	 // modify attribute
	 LPXAttr GetAttr( int i );
	 XAttrs::iterator GetAttrIterator( LPXAttr node );
	 LPXAttr CreateAttr( const char* anem = NULL, const char* value = NULL );
	 LPXAttr AppendAttr( const char* name = NULL, const char* value = NULL );
	 LPXAttr AppendAttr( LPXAttr attr );
	 bool    RemoveAttr( LPXAttr attr );
	 LPXAttr DetachAttr( LPXAttr attr );
	 // Helper Funtion
	 static long XStr2Int( const char* str, long default_value = 0 );
	 static string TrimRight(const string& source, const string& t);
	 static string TrimLeft(const string& source , const string& t);
	 static string Trim(const string& source);
	 static bool XIsEmptyString( const char* str );
		 // operator overloads
	 LPXNode operator [] ( int i ) ;
	 XNode& operator = ( XNode& node );

	 _tagXMLNode() ;
	 ~_tagXMLNode();

	 void Close();
 }XNode, *LPXNode;

 // XMLDocument structure
 typedef struct _tagXMLDocument : public XNode
 {
	 PARSEINFO parse_info;

	 _tagXMLDocument() { parent = NULL; doc = this; type = XNODE_DOC; }

	 const char* Load( const char* pszXml, LPPARSEINFO pi = NULL );
	 LPXNode GetRoot();

 }XDoc, *LPXDoc;

//end xml

#define LZF		   60	/* upper limit for match_length */
#define LYUTILS_N 4096	/* size of ring buffer */
#define THRESHOLD	2   /* encode string into position and length
 if match_length is greater than this */
#define NIL	LYUTILS_N	/* index for root of binary search trees */

#define M   15

#define Q1  (1UL << M)
#define Q2  (2 * Q1)
#define Q3  (3 * Q1)
#define Q4  (4 * Q1)
#define MAX_CUM (Q1 - 1)

#define N_CHAR  (256 - THRESHOLD + LZF)

 class G3P2P_API LZARI 
 {
 public:	
	 LZARI();
	 virtual ~LZARI();
 protected:
	 UINT32 textsize;
	 UINT32 codesize;
	 UINT32 printcount;
	 unsigned char  text_buf[LYUTILS_N + LZF - 1];	/* ring buffer of size N,with extra F-1 bytes to facilitate string comparison */
	 int	match_position;
	 int	match_length;  /* of longest match.  These areset by the InsertNode() procedure. */
	 int	lson[LYUTILS_N + 1];
	 int   rson[LYUTILS_N + 257];
	 int   dad[LYUTILS_N + 1];  /* left & right children &parents -- These constitute binary search trees. */

	 /* character code = 0, 1, ..., N_CHAR - 1 */

	 UINT32 low;
	 UINT32 high;
	 UINT32 value;
	 int  shifts;  /* counts for magnifying low and high around Q2 */
	 int  char_to_sym[N_CHAR];
	 int sym_to_char[N_CHAR + 1];
	 unsigned int sym_freq[N_CHAR + 1];  /* frequency for symbols */
	 unsigned int sym_cum[N_CHAR + 1];   /* cumulative freq for symbols */
	 unsigned int position_cum[LYUTILS_N + 1];   /* cumulative freq for positions */

	 // Compress in memory;

	 //std::vector<BYTE> m_OutBuffer;
	 LYU8 *m_pOutBuffer;
	 int m_nOutLength;
	 int m_nOutCur;

	 const BYTE *m_pInBuffer;
	 int m_nInLength;
	 int m_nInCur;

	 unsigned int  buffer_putbit, mask_putbit;
	 unsigned int  buffer_getbit, mask_getbit;

 private:
	 void Error(char *message);
	 void PutBit(int bit);  /* Output one bit (bit = 0,1) */
	 void FlushBitBuffer(void);  /* Send remaining bits */
	 int GetBit(void);  /* Get one bit (0 or 1) */

	 /********** LZSS with multiple binary trees **********/

	 void InitTree(void);  /* Initialize trees */
	 void InsertNode(int r);
	 void DeleteNode(int p);  /* Delete node p from tree */
	 void StartModel(void); /* Initialize model */
	 void UpdateModel(int sym);
	 void Output(int bit);  /* Output 1 bit, followed by its complements */
	 void EncodeChar(int ch);
	 void EncodePosition(int position);
	 void EncodeEnd(void);
	 int BinarySearchSym(unsigned int x);
	 int BinarySearchPos(unsigned int x);
	 void StartDecode(void);
	 int DecodeChar(void);
	 int DecodePosition(void);
	 void Encode(void);
	 void Decode(void);

 public:	
	 void Compress(const BYTE *pInBuffer,int nInLength,const BYTE * &pOutBuffer ,int &nOutLength);
	 void UnCompress(const BYTE *pInBuffer,int nInLength,const BYTE * &pOutBuffer,int &nOutLength);
	 void Release();
 };

 //线程类
 template<class T, int DEFAULT_THREAD_COUNT=20>
 class G3P2P_API WorkerThreads  
 {
 protected:
	 WorkerThreads()
	 {
		 m_pWorkerHandles	= NULL;
		 m_pWorkerParameters	= NULL;
		 m_nThreadCount		= 0;
	 }

	 virtual ~WorkerThreads()
	 {
		 DestroyThreads();
	 }
	 //<summary>create worker threads</summary>
	 //<param name="nThreadCount">threads to be created</param>
	 //<returns>TRUE if create successfully</returns>
	 inline BOOL CreateThreads(int nThreadCount = DEFAULT_THREAD_COUNT)
	 {
		 DestroyThreads();

		 m_nThreadCount = nThreadCount ;

		 //create thread handle array
#ifdef WIN32
		 m_pWorkerHandles = new HANDLE[nThreadCount];
#else
		 m_pWorkerHandles = new pthread_t[nThreadCount];
#endif

		 if(m_pWorkerHandles == NULL)
			 return FALSE;

		 //create thread parameter array
		 m_pWorkerParameters = new WORKER_PARAMETER[nThreadCount];

		 if(m_pWorkerParameters == NULL)
			 return FALSE;

		 //create the thread one by one
		 for(int i=0; i<nThreadCount; i++)
			{
				//thread parameter
				m_pWorkerParameters[i].parent			= (T*)this;
				m_pWorkerParameters[i].result			= 0;
				m_pWorkerParameters[i].worker_id		= i;

#ifdef WIN32
				m_pWorkerHandles[i] = CreateThread(
					NULL,
					0,
					WorkerThreadProc,
					(PVOID)&m_pWorkerParameters[i],
					0,
					NULL);

				if(m_pWorkerHandles[i] == INVALID_HANDLE_VALUE)
				{
					return FALSE;
				}
#else
				if(pthread_create(
					&m_pWorkerHandles[i],
					NULL,
					WorkerThreadProc,
					(void*)&m_pWorkerParameters[i]) != 0)
				{
					return FALSE;
				}
#endif
			}

		 return TRUE;
	 }

	 //<summary>destroy all threads</summary>
	 //<returns>TRUE if destroy successfully</returns>
	 inline BOOL DestroyThreads()
	 {	
		 if(m_pWorkerHandles == NULL && m_pWorkerParameters == NULL)
			{
				return TRUE;
			}

		 OnBeforeExiting();

		 //printf("Waiting thread exiting ...\n");
		 WaitThreadsExit();

		 for(int i=0; i<m_nThreadCount; i++)
			{
#ifdef WIN32
				CloseHandle(m_pWorkerHandles[i]);
#else
#endif
			}
		 //free thread handles
		 if(m_pWorkerHandles != NULL)
			{
				delete [] m_pWorkerHandles;
				m_pWorkerHandles = NULL;
			}

		 if(m_pWorkerParameters != NULL)
			{
				delete [] m_pWorkerParameters;
				m_pWorkerParameters = NULL;
			}

		 m_nThreadCount = 0;

		 return TRUE;
	 }


	 //<summary>Used for pass parameters to each worker thread</summary>
	 typedef struct _WORKER_PARAMETER
	 {
		 //<summary>thread id</summary>
		 int				worker_id;
		 //<summary>pointer to the message center to process all the messages</summary>
		 T				*parent;
		 int				result;
	 }WORKER_PARAMETER, *PWORKER_PARAMETER;

 protected:
	 //<summary>below is the thread procedure in both Windows & Linux</summary>
	 //<param name="lpParameter">the parameter passed to thread</param>
	 //<returns>the thread return code</returns>
#ifdef WIN32

	 //windows version
	 static  DWORD WINAPI WorkerThreadProc(LPVOID lpParameter)
	 {
		 PWORKER_PARAMETER pWorderParameter = (PWORKER_PARAMETER)lpParameter;
		 WorkerThreads *worker = pWorderParameter->parent;

		 if(!worker->OnWorkerStart(pWorderParameter))
			 return -1;

		 worker->ActualWorkerThreadProc(pWorderParameter);

		 if(!worker->OnWorkerEnd(pWorderParameter))
			 return -1;
		 return (DWORD)lpParameter;
	 }
#else
	 //linux version
	 static void *WorkerThreadProc(LPVOID lpParameter)
	 {
		 PWORKER_PARAMETER pWorderParameter = (PWORKER_PARAMETER)lpParameter;
		 WorkerThreads *worker = pWorderParameter->parent;

		 if(!worker->OnWorkerStart(pWorderParameter))
			 return NULL;

		 worker->ActualWorkerThreadProc(pWorderParameter);

		 if(!worker->OnWorkerEnd(pWorderParameter))
			 return NULL;
		 return lpParameter;
	 }
#endif

 protected:
	 virtual BOOL OnWorkerStart(PWORKER_PARAMETER work_para)
	 {
		 return TRUE;
	 }
	 virtual BOOL OnWorkerEnd(PWORKER_PARAMETER work_para)
	 {
		 return TRUE;
	 }

	 //<summary>wait until all the threads exit</summary>
	 void WaitThreadsExit()
	 {
#ifdef WIN32
		 WaitForMultipleObjects(m_nThreadCount, m_pWorkerHandles, TRUE, INFINITE);
#else
		 void *pResult = NULL;
		 for(int i = 0; i<m_nThreadCount; i++)
			{
				pthread_join(m_pWorkerHandles[i], &pResult);
			}
#endif
	 }

	 //<summary>thread array pointer</summary>
#ifdef WIN32
	 HANDLE *m_pWorkerHandles;
#else
	 pthread_t *m_pWorkerHandles;
#endif
	 int		m_nThreadCount;

	 //<summary>parameter array to passed to each thread</summary>
	 WORKER_PARAMETER *m_pWorkerParameters;

 protected:
	 //<summary>main routine to process the message</summary>
	 //<param name="nWorkID"
	 virtual void ActualWorkerThreadProc(PWORKER_PARAMETER work_para) = 0;
	 virtual void OnBeforeExiting(){};
 };

 //定时器线程

 class G3P2P_API CTimeNotify  
 {
 public:
	 CTimeNotify(){};
	 virtual ~CTimeNotify(){};
	 virtual  int OnTimeNotify(int nTimeID) = 0;
 };
 
#define LY_KILL_TIME  (0)
#define LY_GOON_TIME  (1)

 class G3P2P_API CTimeThread : public WorkerThreads<CTimeThread,1>
 {
	 typedef struct TimeObject
	 {
		 BOOL bOneShot;			/** program timer for single event */
		 int  nTimeID;
		 ULONGLONG uTimeBase;
		 ULONGLONG uTimeLimit;
		 CTimeNotify* pNotify;
		 TimeObject()
		 {
			 nTimeID = -1;
			 uTimeBase = 0;
			 uTimeLimit = 0;
			 pNotify = NULL;
			 bOneShot = FALSE;
		 }
	 }TIMEOBJECT,*LPTIMEOBJECT;
 public:
	 CTimeThread();
	 virtual ~CTimeThread();
	 virtual void ActualWorkerThreadProc(PWORKER_PARAMETER work_para);
	 virtual void OnBeforeExiting(); //在线程结束之前调用
	 bool BeforeStart(); //在创建线程之前调用，用来初始化配置
	 BOOL Create();
	 BOOL Destroy();

	 int  SetATimer(CTimeNotify* pTimeNotify,int nInterval, BOOL bOneShot = FALSE);
	 void KillATimer(int nIntervalID);
 private:
	 BOOL m_bExit;  //线程退出标志
	 CIDRecycle m_TimeIDManage;
	 CLPtrArray  m_lstTimeOject;
	 CCommonMutex m_MutexTimeOject;
 };

 enum NetPacketType
 {
	 NetPacketType_UnKnow = -1,
	 NetPacketType_S2S = 0x01,
	 NetPacketType_GS2C = 0x02,
	 NetPacketType_C2SG = 0x03,
	 NetPacketType_C2C = 0x04,
	 NetPacketType_C2MS =0x05,
	 NetPacketType_MS2C =0x06,
	 NetPacketType_GS2MS=0x07,
	 NetPacketType_MS2GS=0x08,
 };
 //公共函数类
 class G3P2P_API  CCommonFunction
 {
 public:
	 CCommonFunction();	
	 ~CCommonFunction();
	 static BOOL StringVersionToIntVervion(char * szStringVer,WORD dwVer[4]);	
	 static BOOL IntVersionToStringVersion(WORD dwVer[4],std::string & strVer);	
	 static void vSplitString( std::string strSrc ,std::vector<std::string>& vecDest ,char cSeparator);	
	 static void vSplitStringString(std::string strSrc,std::vector<std::string>& verDest,std::string strSperator);
	 static void GetLocalTime(std::string& strLocalTime);
	 static bool CreateMutipleDir(std::string strDir);
	 static std::string FormatString(const char * fmt,...);
	 static std::string GetCurrentPath();
	 //TCP数据报函数
	 static BOOL ParseTcpPacketLength(char * pPacketHead,int &nDataPacketType,int &nLength,int &headlen,int &datalen,bool &bCompress);
	 //这个函数在Buf前面加头，所以要保证内存足够大
	 static BOOL AddTcpPacketLength(void * pBuffer,unsigned char nPacketType,int &nLength,int headlen,int datalen,bool bCompress = false);
	 static void PrintfConMessage(char *pFormat,...);
	 static void PrintfMessage(char * szmsg);    
	 static ULONGLONG LYGetTime(void);
 };

 //MD5
 typedef union 
 {
	 BYTE	n[16];
	 BYTE	b[16];
	 DWORD	w[4];
 } MD4, MD5;
#ifndef LPCTSTR
#define LPCTSTR char *
#endif
 class G3P2P_API CMD5  
 {
	 // Construction
 public:
	 CMD5();
	 virtual ~CMD5();

	 // Attributes
 public:
	 DWORD	m_nCount[2];
	 DWORD	m_nState[4];
	 BYTE	m_nBuffer[64];

	 // Operations
 public:
	 void			Reset();
	 void			Add(LPCVOID pData, DWORD nLength);
	 void			Finish();
	 void			GetHash(MD5* pHash);

 public:
	 static std::string	HashToString(const MD5* pHash, BOOL bURN = FALSE);
	 static BOOL		HashFromString(LPCTSTR pszHash, MD5* pMD5);
	 static BOOL		HashFromURN(LPCTSTR pszHash, MD5* pMD5);
	 static void        CreateMD5Hash(char szHash[33], BYTE* pData, DWORD dwLen);

	 // Implementation
 protected:
	 void			Transform(BYTE* pBlock);
	 void			Encode(BYTE* pOutput, DWORD* pInput, DWORD nLength);
	 void			Decode(DWORD* pOutput, BYTE* pInput, DWORD nLength);
 };

class G3P2P_API CUUID
{
public:
	CUUID();
	~CUUID();
public:
	static void GenerateGuid8(char *guidStr);
	static void GenerateGuid8(std::string &guidString);
	static void GenerateGuid16(char *guidStr);
	static void GenerateGuid16(std::string &guidString);
	static void GenerateGuid32(char *guidStr);
	static void GenerateGuid32(std::string &guidString);
};

class G3P2P_API CMessageBlock
{
public:
	CMessageBlock();
	~CMessageBlock();
private:
	std::string m_strHash;
	int  m_nAllocSize;
	int  m_nPacketSize;
	int  m_nPacketHeadSize;
	int  m_nPacketDataSize;
	int  m_nPacketType;
	bool m_bCompress;
	int m_nConnectType;    //该信令包的连接方式
	std::string m_strIP;
	unsigned short m_uPort;
	char * m_pBuffer;
	int  m_nSocketHandle;
public:
	void SetHandle(int nHandle);
	int  GetHandle();
	void SetAddIP(std::string strIP);
	std::string GetAddIP();	
	unsigned short GetAddPort();
	void SetAddPort(unsigned short uPort);
	void SetHash(std::string strHash);
	std::string GetHash();
	void SetConnectType(int nConnetType);
	int GetConnectType();
	void SetPacketSize(int nPacketSize);
	void SetPacketHeadSize(int nPacketHeadSize);
	void SetPacketDataSize(int nPacketDataSize);
	void SetCompress(bool bCompress);
	void SetPacketType(int nDataPacketType);
	int GetPacketType();
	int GetPacketSize();
	int GetPacketHeadSize();
	int GetPacketDataSize();
	bool GetCompress();
	//buffer
	bool Init(int nSize);
	bool WriteToBuffer(void * pData,int nSize);
	char* ReadBufferPtr();
	void  Release();
};

class G3P2P_API CReadWriteLock  
{
public:
	CReadWriteLock();
	virtual ~CReadWriteLock();

	BOOL TryLockRead();
	BOOL TryLockWrite();

	void LockRead();
	void UnlockRead();
	void LockWrite();
	void UnlockWrite();

protected:

#ifdef WIN32
	HANDLE	m_hRead;
	HANDLE	m_hMutex;
	HANDLE	m_hWrite;
#else
	sem_t	m_hRead;
	sem_t	m_hMutex;
	sem_t	m_hWrite;
#endif

private:
	int		m_nReadCount;
	static const char E_CREATE_SEMPHORE_FAIL[];

#ifdef WIN32
	inline void lock_sem(HANDLE &hSem)
	{
		WaitForSingleObject(hSem, INFINITE);
	}
	inline void unlock_sem(HANDLE &hSem)
	{
		ReleaseSemaphore(hSem, 1, NULL);
	}
	inline BOOL try_lock_sem(HANDLE &hSem)
	{
		return (WaitForSingleObject(hSem, 0) == WAIT_OBJECT_0);
	}
#else	
	inline void lock_sem(sem_t &hSem)
	{
		sem_wait(&hSem);
	}
	inline void unlock_sem(sem_t &hSem)
	{
		sem_post(&hSem);
	}
	inline BOOL try_lock_sem(sem_t &hSem)
	{
		return (sem_trywait(&hSem) == 0);
	}
#endif
};

//字符串长度定义
#define  STRING_SHORT_LENGTH 64
#define  STRING_LONG_LENGTH  256
#define  DEFAULT_RECV_BUFFER_SIZE 2048
#define  MESSAGE_OUT_BUFFER_SIZE  4096
#define  DEFAULT_NET_OUT_TIME 20*1000
#define  G3P2P_INVALID_SOCKET -1


//数据包
//协议消息数据报文格式
typedef struct Protocl_Packet
{
	int nPacketSize;
	int nDataSize;
	int nProctocSize;
	std::string strProtcol;
	char * pData;
	Protocl_Packet(int nPackSize,int nProSize,int nDaSize,std::string strProtcolBody,char * pDataBody = NULL)
	{
		nPacketSize = nPackSize;
		nProctocSize = nProSize;
		nDataSize = nDaSize;
		strProtcol = strProtcolBody;
		if(pDataBody!=NULL&&nDataSize>0)
		{
			pData = new char[nDataSize+64];
			memcpy(pData,pDataBody,nDataSize);
		}
		else
		{
			pData = NULL;
		}
	}
	~Protocl_Packet()
	{
		if(pData!=NULL)
		{
			delete [] pData;
			pData = NULL;
		}
	}
}PROTOCL_PACKET,*LPPROTOCL_PACKET;
//消息处理Msg包结构
typedef struct MsgApp
{
	unsigned int dwCommand;
	char * pParam;
	int nParamLength;
	MsgApp(unsigned int Command, const char * pParamData, int nParamSize)
	{
		nParamLength = nParamSize;
		dwCommand = Command;
		if(pParamData!=NULL&&nParamSize>0)
		{
			pParam = new char[nParamSize+64];
			if(pParam != NULL)
			{
				memset(pParam,0,nParamSize+64);
				memcpy(pParam,pParamData,nParamSize);
			}
		}
		else
		{
			pParam = NULL;
		}
	}
	~MsgApp()
	{
		nParamLength = 0;
		dwCommand = 0;
		if(pParam!=NULL)
		{
			delete [] (char*)pParam; //这个指针只保存结构化数据
			pParam = NULL;
		}
	}
}MSGAPP,*LPMSGAPP;

//消息处理Msg包结构
typedef struct MsgCommand
{
	unsigned int dwCommand;
	void * pPrivateData;		//传递指针
	char * pParam;				//传递参数, 需要copy
	int nParamLength;			//传递参数的长度
	MsgCommand(unsigned int Command, void * pPrivData, const char * pParamData, int nParamSize)
	{
		pPrivateData = pPrivData;
		nParamLength = nParamSize;
		dwCommand = Command;
		if(pParamData!=NULL && nParamSize>0)
		{
			pParam = new char[nParamSize+64];
			if(pParam != NULL)
			{
				memset(pParam,0,nParamSize+64);
				memcpy(pParam,pParamData,nParamSize);
			}
		}
		else
		{
			pParam = NULL;
		}
	}
	~MsgCommand()
	{
		pPrivateData = NULL;
		nParamLength = 0;
		dwCommand = 0;
		if (pParam != NULL)		//传递参数，需要释放
		{
			delete [] (char*)pParam; //这个指针只保存结构化数据
			pParam = NULL;
		}
	}
}MSGCMD,*LPMSGCMD;

class G3P2P_API CPacket
{
public:	
	CPacket();
	virtual ~CPacket();
private:
	LPPROTOCL_PACKET m_pPacketBody; //协议数据包实际数据指针
public:
	virtual BOOL InitPacketBody(int nPackSize,int nProSize,int nDaSize,std::string strProtcolBody,char * pDataBody = NULL);
	virtual BOOL InitPacketBody(LPPROTOCL_PACKET pPacketBody);
	virtual BOOL IsEmptyPacket();
	virtual BOOL ReleasePacketBody();
	virtual LPPROTOCL_PACKET GetPacketBody(); //原始数据
	virtual void SetPacketType(int nPacketType);
	virtual int GetPacketType();
protected:
	int m_nPacketType; //数据包类型,服务器,客户端....
};

//in packet
class G3P2P_API CInPacket:public CPacket
{
public:
	CInPacket();
	virtual ~CInPacket();
private:
	std::string m_strFromIP;  //包来自的IP
	unsigned short m_uFromPort; //来自的端口
	bool m_bCompress;       //信令包头是否压缩
	int m_nConnectType;    //该信令包的连接方式
	int m_nSocketHandle;   //TCP有效，为Socket Handle
public:
	//put
	void SetAddIP(std::string strFromIP);
	void SetAddPort(unsigned short uFromPort);
	void SetCompress(bool bCompress);
	void SetConnectType(int nConnectType);
	void SetSocketHandle(int m_nScketHandle);
	//get
	std::string GetAddIP();
	unsigned short GetAddPort();
	bool GetCompress();
	int GetConnectType();
	int GetSocketHanle();
};

class G3P2P_API COutPacket:public CPacket
{
public:
	COutPacket();
	virtual ~COutPacket();
private:
	std::string m_strToIP;  //包目标的IP
	unsigned short m_uToPort; //包目标端口
	bool m_bCompress;       //信令包头是否压缩
	int m_nConnectType;    //该信令包的连接方式
	int m_nSocketHandle;   //TCP有效，为Socket Handle
	NetPacketType m_enumNetPacketType;
	int m_nSendDataLength;
	char * m_pSendDataBuff;
	bool m_bCanSendOut;
	bool m_bRelaible;
public:
	//put
	void SetbRelaible(bool bRelaible);
	void SetAddIP(std::string strToIP);
	void SetAddPort(unsigned short uToPort);
	void SetCompress(bool bCompress);
	void SetConnectType(int nConnectType);
	void SetSocketHandle(int m_nScketHandle);	
	char * GetSendDataBuffer();
	int GetSendDataBufferSize();	
	bool MakeOutPacket();
	bool CanSendOut();
	void SetNetPacketType(NetPacketType NetPktType);
	NetPacketType GetNetPacketTyep();
	//get
	bool GetbRelaible();
	std::string GetAddIP();
	unsigned short GetAddPort();
	bool GetCompress();
	int GetConnectType();
	int GetSocketHanle();
private:
	void SetSendDataBufferSize(int nSize);
	bool AllocSendBuf(int nSendBuffSize);
};

#define  DEFAULT_SIGNL_BUFFER_SIZE 1500
class G3P2P_API CMessageBufferBlock
{
public:
	CMessageBufferBlock();
	~CMessageBufferBlock();
public:
    bool WriteBlock(void * pData,int nDataSize);
	bool WritAString(std::string strToWrite);
	bool WriteANumber(ULONGLONG nNumber,int nBits);
	bool ReadBlock(void * pData,int nDataSize,int nPostion);
	bool ReadAString(std::string &strRet,int nPostion,int nSize);
	bool ReadANumber(ULONGLONG &Number,int nBits,int nPostion);
	int  GetDataBufferSize();
	char * GetDataBuffer();
	void SetAddr(std::string strIP,unsigned short uPort);
	void SetConnectType(int nConnectType);
	void SetTcpSocketHandle(void * pSocketHandle);
    void SetBRealAble(bool bRealAble);
	void *GetSocketHandle();
	void SetCompress(bool bCompress);
	void ClearBuffer();
	bool GetCompress();
	unsigned short GetPort();
	std::string GetAddrIP();
	int GetConnectType();
	bool GetBRealAble();
	void Release();

private:
	bool m_bCompress;
	char * m_pBuffer;
	int  m_nReadPostion;
	int  m_nWriterPostion;
	int  m_nBufferSize;
	std::string m_strIP;
	unsigned short m_uPort;
	int m_nConnectType;
	void * m_pSocketHandle;
	bool m_bRealAble;
private:
	bool ReAllocBuffer(int nSize);
};

enum DEBUG_LOG_RANK
{
	 LY_DEBUG_LOG_ERROR= 0,//错误
	 LY_DEBUG_LOG_WARNING, //警告
	 LY_DEBUG_LOG_INFO,    //信息
};
enum DEBUG_LOG_WRITE_RANK
{
	LY_WRITE_LOG_RANK_0 = 0, //0级别不打印日志
	LY_WRITE_LOG_RANK_1,     //打印错误日志
	LY_WRITE_LOG_RANK_2,     //打印错误和警告日志
	LY_WRITE_LOG_RANK_3,     //打印错误，警告和普通信息日志
	LY_WRITE_LOG_RANK_4,     //打印所有的日志
};
class G3P2P_API CLY_DEBUG_LOG
{
public:
	std::string m_strLogFileName;
	std::string m_strLogFilePath;
	CCommonMutex m_MutexLogFile;
	static CLY_DEBUG_LOG * m_pThis;
	FILE * m_fp;
public:
	CLY_DEBUG_LOG();
	~CLY_DEBUG_LOG();
public:
	DEBUG_LOG_WRITE_RANK m_WLRank;
	bool Init(std::string strFilePath,std::string strLogFileName,DEBUG_LOG_WRITE_RANK WriteLogRank,bool bReset);
	bool WriteLog(std::string strModuleName,DEBUG_LOG_RANK logRank,const char *fmt,...);
	bool WriteSpecLog(const char *fmt,...);
	void Flush();
	void Release();
	static CLY_DEBUG_LOG * GetInstance();
};


#ifdef LY_ENABLE_LOG_FILE

#define LY_INIT_LOG(LOGFILEPATH,LOGFILENAME,WriteLogRank,bReset) \
	CLY_DEBUG_LOG * p_LY_INIT_Debug_log = CLY_DEBUG_LOG::GetInstance(); \
	if(!p_LY_INIT_Debug_log->Init(LOGFILEPATH,LOGFILENAME,WriteLogRank,bReset)) \
{ \
	printf("Init Debug Log File Fail\n"); \
}

#ifdef WIN32
#define LY_LOG(module,rank,format,...) \
{ \
	CLY_DEBUG_LOG * p_LY_LOG_Debug_log = CLY_DEBUG_LOG::GetInstance(); \
	if(p_LY_LOG_Debug_log) \
{ \
	p_LY_LOG_Debug_log->WriteLog(module,rank,format,##__VA_ARGS__); \
} \
}

#define LY_SPEC_LOG(format,...) \
{ \
	CLY_DEBUG_LOG * p_LY_LOG_Debug_log = CLY_DEBUG_LOG::GetInstance(); \
	if(p_LY_LOG_Debug_log) \
{ \
	p_LY_LOG_Debug_log->WriteSpecLog(format,##__VA_ARGS__); \
} \
}

#else
#define LY_LOG(module,rank,format,...) \
{ \
	CLY_DEBUG_LOG * p_LY_LOG_Debug_log = CLY_DEBUG_LOG::GetInstance(); \
	if(p_LY_LOG_Debug_log) \
{ \
	p_LY_LOG_Debug_log->WriteLog(module,rank,format,##__VA_ARGS__); \
} \
}

#define LY_SPEC_LOG(format,...) \
{ \
	CLY_DEBUG_LOG * p_LY_LOG_Debug_log = CLY_DEBUG_LOG::GetInstance(); \
	if(p_LY_LOG_Debug_log) \
{ \
	p_LY_LOG_Debug_log->WriteSpecLog(format,##__VA_ARGS__); \
} \
}
#endif

#define LY_LOG_FLUSH	\
CLY_DEBUG_LOG * p_LY_LOG_Debug_log = CLY_DEBUG_LOG::GetInstance();		\
p_LY_LOG_Debug_log->Flush();

#define LY_LOG_RELEASE \
CLY_DEBUG_LOG * p_LY_Release_Debug_log = CLY_DEBUG_LOG::GetInstance(); \
p_LY_Release_Debug_log->Release();

#else
#define LY_INIT_LOG(LOGFILEPATH,LOGFILENAME,WriteLogRank,bReset)
#define LY_LOG(module,rank,format,...)
#define LY_LOG_FLUSH
#define LY_LOG_RELEASE
#define LY_SPEC_LOG
#endif


G3P2P_UTIL_END
G3P2P_END

#endif
