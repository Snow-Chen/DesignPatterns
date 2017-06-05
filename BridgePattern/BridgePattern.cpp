// BridgePattern.cpp : 定义控制台应用程序的入口点。
//



/*
现在要去画一个图形，图形有长方形、圆形和扇形等等；
而图形又可以加上不同的颜色，然后，我们就可以画出红色的长方形，绿色的长方形；红色的圆形，绿色的圆形等等。
而这种图形的形状在变化，图形的颜色也在变化，当使用代码去实现时，如何面对这种多方面的变化呢？这就要说到今天的桥接模式了。
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

