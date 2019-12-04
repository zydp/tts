#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_
#include <string>
#include "CommToolsExportDef.h"
using std::string;

#define SERIALIZE_BUF_SIZE 4096				//getpagesize()
#define SERIALIZE_REALLOC_MAX_COUNT	8		//���ռ���չ����4096*8
typedef enum {
	LENGTH_CHECK_READ,//�����л�
	LENGTH_CHECK_WRITE,//���л�
}LENGTH_CHECK_TYPE;

/*
* Warning�� һ�����л�����ֻ���������л������л��е�һ����;
*/
typedef struct szBuf  
{
	int iSize;
	char pBuf[SERIALIZE_BUF_SIZE];
}T_SZBUF;
class COMM_TOOLS_API CSerialize
{
public:
	/*���л�ʱʹ��*/
	CSerialize(const int TotalBufLen = SERIALIZE_BUF_SIZE);
	/*�����л�ʱʹ��*/
	CSerialize(const char* szBuf,const int szBufLen);
	~CSerialize(void);
public:
	CSerialize&  operator<<(const bool _Val);
	CSerialize&  operator>>(bool& _Val);
	CSerialize&  operator<<(const short _Val);
	CSerialize&  operator>>(short& _Val);
	CSerialize&  operator<<(const int _Val);
	CSerialize&  operator>>(int& _Val);
	CSerialize&  operator<<(const unsigned int& _Val);
	CSerialize&  operator>>(unsigned int& _Val);
	CSerialize&  operator<<(const double _Val);
	CSerialize&  operator>>(double& _Val);
	CSerialize&  operator<<(const unsigned long long _Val);
	CSerialize&  operator>>(unsigned long long& _Val);
	CSerialize&  operator<<(const string& _Val); 
	CSerialize&  operator>>(string& _Val);
	CSerialize&  operator<<(const T_SZBUF& _Val); 
	CSerialize&  operator>>(T_SZBUF& _Val);
public:
	/*��ȡ�����л���buf��С*/
	inline int GetIndex(){return m_iCurrIndex+1;}
	
	/*�������л����buf*/
	inline const char* Serialize(){return m_strBuf;}
	
	/*�����±�Ϊ��ʼλ��*/
	inline void ResetIndex(){m_iCurrIndex = 0;}

	/*��buf��գ��������±�*/
	bool ClearBuffer();

	/*��ȡ���л�����״̬*/
	inline bool GetSerStatus(){return m_SerStatus;}

	/*�ͷ��ڲ��ռ�*/
	void Release();
private:
	/*���л�ʱ�ڲ��ռ��ʼ��*/
	bool BufInit();
	
	/*buf���ȼ��*/
	bool CheckLength(const int ValueLen,LENGTH_CHECK_TYPE checkType);
	
	/*���л�һ������*/
	void ValueWrite(const char* strValue,const int valueLen);
	
	/*�����л�һ������*/
	void ValueRead(void* ValueAddress,const int valueLen);
private:
	int   m_iTotalLen;				//buf�ܳ�
	int   m_iCurrIndex;				//��ǰ�±�
	char* m_strBuf;					//buf��ַ
	bool  m_isSerialize;			//true->���л�,false->�����л�
	bool  m_SerStatus;				//���л�״̬��trueΪ������falseΪ�쳣
	unsigned short m_iReallocCount;	//�ռ���չ����
private:
	CSerialize(CSerialize& sz){}
	CSerialize& operator=(CSerialize &sz){return *this;}
};

#endif