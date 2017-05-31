// factoryPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"

using namespace std;

//参考 http://www.jellythink.com/archives/878


//简单工厂模式
//一个工厂生产出不同的产品

typedef enum ProductTypeTag
{
	TypeOne,
	TypeTwo,
	TypeThree
}PRODUCTTYPE;


class Product
{
public:
	virtual void show() = 0;

};


class Product_A : public Product
{
public:
	void show()
	{
		cout << "This is Product_A" << endl;
	}

};

class Product_B : public Product
{
public:
	void show()
	{
		cout << "This is Product_B" << endl;
	}

};

class Product_C : public Product
{
public:
	void show()
	{
		cout << "This is Product_C" << endl;
	}

};

class SimpleFactory
{
public:
	Product * createProduct(PRODUCTTYPE Type)
	{
		switch (Type)
		{
		case TypeOne:
			return  new Product_A();
		case TypeTwo:
			return  new Product_B();
		case TypeThree:
			return  new Product_C();
		default:
			break;
		}
	}

};



// 工厂方法模式
// 每个工厂只生产一种产品

class Factory
{
public:
	virtual Product * createProduct() = 0;

};


class FactoryA : public Factory
{
public:
	Product * createProduct()
	{
		return new Product_A();
	}
};

class FactoryB : public Factory
{
public:
	Product * createProduct()
	{
		return new Product_B();
	}
};


class FactoryC : public Factory
{
public:
	Product * createProduct()
	{
		return new Product_C();
	}
};


// 抽象工厂模式
// 将简单工厂模式和工厂模式相结合，在工厂Factory中的每一个方法，就好比是一条生产线，而生产线实际需要生产什么样的产品


class Product_A_Plus : public Product
{
public:
	void show()
	{
		cout << "This is Product_A_Plus" << endl;
	}

};

class Product_B_Plus : public Product
{
public:
	void show()
	{
		cout << "This is Product_B_Plus" << endl;
	}

};


class Factory_Plus
{
public:
	virtual Product * createProductA() = 0;
	virtual Product * createProductB() = 0;

};


class FactoryA_Plus : public Factory_Plus
{
public:
	Product * createProductA()
	{
		return new Product_A();
	}


	Product * createProductB()
	{
		return new Product_A_Plus();
	}
};

class FactoryB_Plus : public Factory_Plus
{
public:
	Product * createProduct()
	{
		return new Product_B();
	}

	Product * createProductB()
	{
		return new Product_B_Plus();
	}
};











int _tmain(int argc, _TCHAR* argv[])
{
	SimpleFactory *myFactory = new SimpleFactory();

	Product *productA = myFactory->createProduct(TypeOne);
	if (nullptr != productA)
	{
		productA->show();
	}

	Product *productB = myFactory->createProduct(TypeTwo);
	if (nullptr != productB)
	{
		productB->show();
	}

	Product *productC = myFactory->createProduct(TypeThree);
	if (nullptr != productC)
	{
		productC->show();
	}

	delete myFactory;
	myFactory = NULL;

	delete productA;
	productA = NULL;

	delete productB;
	productB = NULL;

	delete productC;
	productC = NULL;


	return 0;
}

