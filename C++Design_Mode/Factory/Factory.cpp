#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
class Operation
{
private:
	double A, B;
public:
	double GetA() const { return A; }
	double GetB() const { return B; }
	void SetA(double x) { A = x; }
	void SetB(double y) { B = y; }
	double virtual GetResult() { return 0; }
	Operation()
	{
		A = 0;
		B = 0;
	}
};
 
class Add : public Operation
{
public:
	double GetResult()
	{
		return GetA() + GetB();
	}
};
 
class Sub : public Operation
{
public:
	double GetResult()
	{
		return GetA() - GetB();
	}
};
 
class Mul : public Operation
{
public:
	double GetResult()
	{
		return GetA()*GetB();
	}
};
 
class Div : public Operation
{
public:
	double GetResult()
	{
		return GetA() / GetB();
	}
};
 
class SimpleFactory
{
public:
	virtual Operation * CreateOpeartor() = 0;
};
class ADD :public SimpleFactory
{
public:
	Operation * CreateOpeartor()
	{
		return new Add;
	}	
};
class SUB :public SimpleFactory
{
public:
	Operation * CreateOpeartor()
	{
		return new Sub;
	}
};
class DIV :public SimpleFactory
{
public:
	Operation * CreateOpeartor()
	{
		return new Div;
	}
};
class MUL :public SimpleFactory
{
public:
	Operation * CreateOpeartor()
	{
		return new Mul;
	}
};
int main()
{
	double A = 0;
	double B = 0;
	char ch = '\0';
	ADD p1;
	SUB p2;
	MUL p3;
	DIV p4;
	cin >> A >> ch >> B;
	Operation *p = new Operation();
	switch (ch)
	{
		case '+':
			p = p1.CreateOpeartor();
			break;
		case '-':
			p = p2.CreateOpeartor();
			break;
		case '*':
			p = p3.CreateOpeartor();
			break;
		case '/':
			p = p4.CreateOpeartor();
			break;
		
	}
	p->SetA(A);
	p->SetB(B);
	cout << p->GetResult() << endl;
}