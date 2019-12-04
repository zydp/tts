#ifndef ID_GENERATION_H 
#define ID_GENERATION_H
#define  MAXID 0x7FFFFFFF
#ifdef INESAHOME_USE_CXX11
#include <atomic>
#endif

class CIDGeneration
{
#ifdef INESAHOME_USE_CXX11
	std::atomic_int m_iIdIndex;
#else
	volatile int m_iIdIndex;
#endif
public: 
	CIDGeneration()
	{
		m_iIdIndex = 1;
	}
	int CreateNewID()
	{
		if (m_iIdIndex>MAXID)
		{
			m_iIdIndex = 1;
		}
		return m_iIdIndex++;
	}
};

#endif // ID_GENERATION_H 
