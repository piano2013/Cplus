#include<iostream>

using namespace std;

class shape1
{
public:
	virtual void getArea1(int a) = 0;
};

class shape2
{
public:
	virtual void getArea2(int a, int b) = 0;
};

class circle :public shape1,public shape2
{
public:
	virtual void getArea1(int a)
	{
		cout << "shape1" << endl;
	}
	virtual void getArea2(int a, int b)
	{
		cout << "shape2" << endl;
	}
};

int main(void)
{
	shape1 *p = new circle;
	shape2 *cp = new circle;

	p->getArea1(10);
	cp->getArea2(1, 2);
	getchar();
	return 0;
}