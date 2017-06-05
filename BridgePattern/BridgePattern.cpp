// BridgePattern.cpp : �������̨Ӧ�ó������ڵ㡣
//



/*
����Ҫȥ��һ��ͼ�Σ�ͼ���г����Ρ�Բ�κ����εȵȣ�
��ͼ���ֿ��Լ��ϲ�ͬ����ɫ��Ȼ�����ǾͿ��Ի�����ɫ�ĳ����Σ���ɫ�ĳ����Σ���ɫ��Բ�Σ���ɫ��Բ�εȵȡ�
������ͼ�ε���״�ڱ仯��ͼ�ε���ɫҲ�ڱ仯����ʹ�ô���ȥʵ��ʱ�����������ֶ෽��ı仯�أ����Ҫ˵��������Ž�ģʽ�ˡ�
*/


#include "stdafx.h"
#include "iostream"

using namespace std;
class CColor
{
public:
	void virtual printColor() = 0;
private:

};

class CRed : public CColor
{
public:
	void printColor()
	{
		cout << "this is Red" << endl;
	}
private:

};

class CBlue : public CColor
{
public:
	void printColor()
	{
		cout << "this is Blue" << endl;
	}
private:

};



class CShape
{
public:
	CShape(CColor * m_color) :m_color(m_color){};
	void virtual operate()=0;
protected:
	CColor * m_color;
};

class CRectangle:CShape
{
public:
	CRectangle(CColor * m_color) :CShape(m_color){};
	void operate()
	{
		m_color->printColor();
	}

};

class CCirle :CShape
{
public:
	CCirle(CColor * m_color) :CShape(m_color){};
	void operate()
	{
		m_color->printColor();
	}

};



int _tmain(int argc, _TCHAR* argv[])
{
	CBlue *m_cblue = new CBlue();
	CRectangle *m_crectangle = new CRectangle(m_cblue);
	m_crectangle->operate();

	delete m_cblue;
	m_cblue = nullptr;

	delete m_crectangle;
	m_crectangle = nullptr;
	return 0;
}

