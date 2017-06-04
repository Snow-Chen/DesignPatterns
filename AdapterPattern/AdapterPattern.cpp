// AdapterPattern.cpp : 定义控制台应用程序的入口点。
//


//适配器模式分成两种，分别为类适配器模式和对象适配器模式

#include "stdafx.h"
#include "iostream"

using namespace std;

//类适配器模式
class Target
{
public:
	void virtual Request()
	{
		cout << "this is Target Request" << endl;
	}

};

class Adaptee
{
public :
	void  fool()
	{
		cout << "this is Adaptee Fool" << endl;
	}
};

class AdapteTarget:public Target,Adaptee
{
	void fool()
	{
		Adaptee::fool();
	}
};


//对象适配器
class Adatper : Target
{
public:
	Adatper() :m_adapte(new Adaptee()){}

	~Adatper()
	{
		if (m_adapte != nullptr)
		{
			delete m_adapte;
			m_adapte = nullptr;
		}
	
	}

	void Request()
	{
		m_adapte->fool();
	}
private:
	Adaptee* m_adapte;
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

