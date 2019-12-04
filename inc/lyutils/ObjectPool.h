#ifndef _CObjectPool_H
#define _CObjectPool_H

//#include "networkbasedef.h"
#include "ly_util.h"

using namespace G3P2P_BY_LONGYU;
using namespace G3P2P_BY_LONGYU::G3P2P_BY_LONGYU_UTIL;
/**自定义模板对象池
* @brief 模板对象池
* 
*/
template <typename T>
class CObjectPool
{
public:
	CObjectPool(){}
	
	/**删除所有对象
	*/
	~CObjectPool()
	{
		FinitPool();
	}

	/**从池中取回一个对象
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

	/**使用完的对象重新放回到池中
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

	/**初始化对象池，分配对象
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
	/**向池中继续添加对象
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
	/**空闲的对象链表
	*/
	list<T*> m_free;
	CCommonMutex  m_lock;
};  
template <typename T, typename T1> 
class SmartPtr                                             //智能指针类
{

	CCommonMutex*  m_pLock;
	int* m_pCount;                                                   //引用计数
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
	}                                 //构造函数
	SmartPtr(const SmartPtr &sp):m_pLock(sp.m_pLock)
		,m_pCount(sp.m_pCount)
		,m_p(sp.m_p)
		,m_pPool(sp.m_pPool)
	{
		m_pLock->LockObject();
		++(*m_pCount);
		m_pLock->UnLockObject();
	}            //复制构造函数
	SmartPtr& operator=(const SmartPtr& rhs) {                              //重载赋值操作符
		rhs.m_pLock->LockObject();//	++rhs.count;                                                         //首先将右操作数引用计数加1，
		if(--(*m_pCount) == 0)                                      //当引用计数减为0时，删除辅助类对象指针，从而删除基础对象
			m_pPool->Release(m_p);
		m_p = rhs.m_p;
		m_pPool = rhs.m_pPool;
		m_pLock = rhs.m_pLock;
		rhs.m_pLock->UnLockObject();
		return *this;
	}
	~SmartPtr() {                                            //析构函数
		if (m_pLock)
		{
			m_pLock->LockObject();
			if(--(*m_pCount) == 0) {                   //当引用计数减为0时，删除辅助类对象指针，从而删除基础对象
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