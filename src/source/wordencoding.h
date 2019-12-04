#ifndef _WORD_ENCODING_H_
#define _WORD_ENCODING_H_
#include <windows.h>
#include <wchar.h>
//UTF-8 GBK  
int UTF82GBK(const char *szUtf8, char *szGbk, int Len)
{
	int n = MultiByteToWideChar(CP_UTF8, 0, szUtf8, -1, NULL, 0);
	WCHAR * wszGBK = new WCHAR[sizeof(WCHAR) * n];
	memset(wszGBK, 0, sizeof(WCHAR) * n);
	MultiByteToWideChar(CP_UTF8, 0, szUtf8, -1, wszGBK, n);

	n = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	if (n > Len)
	{
		delete[]wszGBK;
		return -1;
	}
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGbk, n, NULL, NULL);
	delete[]wszGBK;
	wszGBK = NULL;
	return 0;
}

int UTF82GBK_w(const char *szUtf8, WCHAR *szGbk, int Len)
{
	int n = MultiByteToWideChar(CP_UTF8, 0, szUtf8, -1, NULL, 0);

	MultiByteToWideChar(CP_UTF8, 0, szUtf8, -1, szGbk, n);

	//n = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	//if (n > Len)
	//{
	//	delete[]wszGBK;
	//	return -1;
	//}
	//WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGbk, n, NULL, NULL);
	//delete[]wszGBK;
	//wszGBK = NULL;
	return 0;
}



// 注释：多字节包括GBK和UTF-8  
int GBK2UTF8(const char *szGbk, char *szUtf8, int Len)
{
	// 先将多字节GBK（CP_ACP或ANSI）转换成宽字符UTF-16  
	// 得到转换后，所需要的内存字符数  
	int n = MultiByteToWideChar(CP_ACP, 0, szGbk, -1, NULL, 0);
	// 字符数乘以 sizeof(WCHAR) 得到字节数  
	WCHAR *str1 = new WCHAR[sizeof(WCHAR) * n];
	// 转换  
	MultiByteToWideChar(CP_ACP,  // MultiByte的代码页Code Page  
		0,            //附加标志，与音标有关  
		szGbk,        // 输入的GBK字符串  
		-1,           // 输入字符串长度，-1表示由函数内部计算  
		str1,         // 输出  
		n             // 输出所需分配的内存  
	);

	// 再将宽字符（UTF-16）转换多字节（UTF-8）  
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	if (n > Len)
	{
		delete[]str1;
		return -1;
	}
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, szUtf8, n, NULL, NULL);
	delete[]str1;
	str1 = NULL;

	return 0;
}
#endif