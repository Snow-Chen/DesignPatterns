// AdapterPattern.cpp : �������̨Ӧ�ó������ڵ㡣
//


//������ģʽ�ֳ����֣��ֱ�Ϊ��������ģʽ�Ͷ���������ģʽ

#include "stdafx.h"
#include "iostream"

using namespace std;

//��������ģʽ
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


//����������
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

