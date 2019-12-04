#ifndef _CObjectPool_H
#define _CObjectPool_H

//#include "networkbasedef.h"
#include "ly_util.h"

using namespace G3P2P_BY_LONGYU;
using namespace G3P2P_BY_LONGYU::G3P2P_BY_LONGYU_UTIL;
/**�Զ���ģ������
* @brief ģ������
* 
*/
template <typename T>
class CObjectPool
{
public:
	CObjectPool(){}
	
	/**ɾ�����ж���
	*/
	~CObjectPool()
	{
		FinitPool();
	}

	/**�ӳ���ȡ��һ������
	*/
	T* Get()
	{
		m_lock.LockObject();
		if (m_free.empty())
		{
			m_lock.UnLockObject();
			return new T;
		}

		T* p = m_free.front();
		m_free.pop_front();
		m_lock.UnLockObject();
		return p;
	}

	/**ʹ����Ķ������·Żص�����
	*/
	void Release(T* p){

		if (p==NULL)
		{
			printf("%s:%s:%d obj is nil",__FILE__,__FUNCTION__,__LINE__);
			return;
		}
		m_lock.LockObject();
		m_free.push_back(p);
		m_lock.UnLockObject();
	}

	/**��ʼ������أ��������
	*/
	void InitPool(int nCount)
	{
		AddObject(nCount);
	}
	void FinitPool()
	{
		m_lock.LockObject();
		size_t idle = m_free.size();
		while (idle--)
		{
			T* p = m_free.back();
			m_free.pop_back();
			delete p;
		}
		m_lock.UnLockObject();
	}
	/**����м�����Ӷ���
	*/
	void AddObject(int nCount)
	{
		m_lock.LockObject();
		for (int i = 0; i < nCount; i++)
		{
			T* p = new T();
			m_free.push_back(p);
		}
		m_lock.UnLockObject();
	}

	size_t IdleObject()
	{
		m_lock.LockObject();
		size_t freeSize = m_free.size();
		m_lock.UnLockObject();
		return freeSize;
	}
private:
	/**���еĶ�������
	*/
	list<T*> m_free;
	CCommonMutex  m_lock;
};  
template <typename T, typename T1> 
class SmartPtr                                             //����ָ����
{

	CCommonMutex*  m_pLock;
	int* m_pCount;                                                   //���ü���
	T  *m_p;    
	T1* m_pPool; 
	SmartPtr():m_pLock(NULL)
		,m_pCount(NULL)
		,m_p(NULL)
		,m_pPool(NULL)
	{};
public: 
	SmartPtr(T *ptr,T1* pPool):m_pLock(new CCommonMutex)
		,m_pCount(new int(1))
		,m_p(ptr)
		,m_pPool(pPool)
	{
	}                                 //���캯��
	SmartPtr(const SmartPtr &sp):m_pLock(sp.m_pLock)
		,m_pCount(sp.m_pCount)
		,m_p(sp.m_p)
		,m_pPool(sp.m_pPool)
	{
		m_pLock->LockObject();
		++(*m_pCount);
		m_pLock->UnLockObject();
	}            //���ƹ��캯��
	SmartPtr& operator=(const SmartPtr& rhs) {                              //���ظ�ֵ������
		rhs.m_pLock->LockObject();//	++rhs.count;                                                         //���Ƚ��Ҳ��������ü�����1��
		if(--(*m_pCount) == 0)                                      //�����ü�����Ϊ0ʱ��ɾ�����������ָ�룬�Ӷ�ɾ����������
			m_pPool->Release(m_p);
		m_p = rhs.m_p;
		m_pPool = rhs.m_pPool;
		m_pLock = rhs.m_pLock;
		rhs.m_pLock->UnLockObject();
		return *this;
	}
	~SmartPtr() {                                            //��������
		if (m_pLock)
		{
			m_pLock->LockObject();
			if(--(*m_pCount) == 0) {                   //�����ü�����Ϊ0ʱ��ɾ�����������ָ�룬�Ӷ�ɾ����������
				m_pPool->Release(m_p);
				m_p = NULL;//add by daiping
				delete m_pCount;
				m_pCount = NULL;
				m_pLock->UnLockObject();
				delete m_pLock;
				m_pLock = NULL;
			}
			else{
				m_pLock->UnLockObject();
			}
		}
	}

	T &operator*(){
		return *m_p;
	}
	T *operator->()
	{
		return m_p;
	}
	T *GetPtr()
	{
		return m_p;
	}

}; 
 

#endif