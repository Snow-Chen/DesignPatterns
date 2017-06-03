// PrototypePattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//原型模型，通过克隆来生成新的对象

class Prototype
{
public:
	Prototype(){};
	virtual ~Prototype(){};

	virtual Prototype* Clone()=0;
private:

};



class  ConcretePrototype : public Prototype
{
public:
	ConcretePrototype() :m_count(0){};
	virtual ~ConcretePrototype(){};

	ConcretePrototype(const ConcretePrototype& rhs)
	{
		 this->m_count = rhs.m_count;
	}


	virtual ConcretePrototype* Clone()
	{
		return new ConcretePrototype(*this);
	}
private:
	int m_count;
};




int _tmain(int argc, _TCHAR* argv[])
{
	ConcretePrototype *obj1 = new ConcretePrototype();
	ConcretePrototype *obj2 = obj1->Clone();

	delete obj1;
	obj1 = nullptr;

	delete obj2;
	obj2 = nullptr;
	return 0;
}

