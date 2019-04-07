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
	Operation() :A(0), B(0) {}
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
	static Operation * CreateOpeartor(char ch)
	{
		Operation *p=new Operation();
		switch (ch)
		{
		case '+':
			p = new Add();
			break;
		case '-':
			p = new Sub();
			break;
		case '*':
			p = new Mul();
			break;
		case '/':
			p = new Div();
			break;
		}
		return p;
	}
};
 
int main()
{
	double A = 0;
	double B = 0;
	char ch = '\0';
	cin >> A >> ch >> B;
 
	std::shared_ptr<Operation> op(SimpleFactory::CreateOpeartor(ch));
	op->SetA(A);
	op->SetB(B);
	cout << op->GetResult() << endl;
}