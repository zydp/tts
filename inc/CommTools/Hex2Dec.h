#ifndef __HEX_2_DEC_H__
#define __HEX_2_DEC_H__
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "CommToolsExportDef.h"
using namespace std;

unsigned long long COMM_TOOLS_API HextoDec(const char *hex, int length)  
{  
	unsigned long long sum=0;  
	for(int i=length-1;i>=0;i--)  
	{  
		if(hex[i]>='0'&&hex[i]<='9')
		{  
			sum+=(hex[i]-48)*pow(16,length-i-1);  
		}  
		else if(hex[i]>='A'&&hex[i]<='F')  
		{  
			sum+=(hex[i]-55)*pow(16,length-i-1);  
		}  
	} 
	return sum;
}












#endif