// SingletonPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"

using namespace std;


//加锁可以防止多线程出现多个实例
//两次判断是否等于nullptr可以防止每次判断都上锁，增加效率

class singleton
{
public:
	
	static singleton* getinstance()
	{
		if (nullptr != m_instance)
		{
			//lock();
			if (nullptr != m_instance)
			{
				m_instance = new singleton();
			}
			//unlock();

			return m_instance;;
		}
	}


	static void deleteinstance()
	{
		if (nullptr != m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

private:
	singleton(){};
	 
	static singleton* m_instance;
};


singleton *singleton::m_instance = nullptr;




//因为静态初始化在程序开始时，也就是进入主函数之前，由主线程以单线程方式完成了初始化，所以静态初始化实例保证了线程安全性
//同时没有锁可以提高整体的性能

class singleton2
{
public:
	static singleton2* getinstance()
	{
		return const_cast<singleton2*> (m_instance);
	}

	static void deleteinstance()
	{
		if (nullptr != m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

private:
	singleton2(){};		//这里不加{}，下面初始化会报错
	static const singleton2* m_instance;
};

 const singleton2 *singleton2::m_instance = new singleton2();



//避免上述方式new和delete的过程
class singleton3
{
public:
	
	static singleton3* getinstance()
	{
		static singleton3  m_instance;
		return &m_instance;
	}

private:
	singleton3();
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

