// SingletonPattern.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "iostream"

using namespace std;


//�������Է�ֹ���̳߳��ֶ��ʵ��
//�����ж��Ƿ����nullptr���Է�ֹÿ���ж϶�����������Ч��

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




//��Ϊ��̬��ʼ���ڳ���ʼʱ��Ҳ���ǽ���������֮ǰ�������߳��Ե��̷߳�ʽ����˳�ʼ�������Ծ�̬��ʼ��ʵ����֤���̰߳�ȫ��
//ͬʱû��������������������

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
	singleton2(){};		//���ﲻ��{}�������ʼ���ᱨ��
	static const singleton2* m_instance;
};

 const singleton2 *singleton2::m_instance = new singleton2();



//����������ʽnew��delete�Ĺ���
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

