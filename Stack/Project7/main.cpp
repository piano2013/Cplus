#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

class People
{
public:
	People(int Id) :ID(Id) {};
	~People() {};
public:
	int ID;
};
void test()
{
	stack<int> s1;
	stack<int> s2(s1);

	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(100);
	cout << "栈顶元素：" << s1.top() << endl;
	s1.pop();

	//打印
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	cout << s1.size() << endl;
}

//栈容器存放对象指针
void test01()
{
	People p1(1);
	People p2(2);
	People p3(3);

	stack<People*> s;
	s.push(&p1);
	s.push(&p2);
	s.push(&p3);

	while (!s.empty())
	{
		cout << (s.top())->ID << " ";
		s.pop();
	}
	cout << endl;
}

//栈容器存放对象
void test02()
{
	People p1(1);
	People p2(2);
	People p3(3);

	stack<People> s;
	s.push(p1);
	s.push(p2);
	s.push(p3);

	while (!s.empty())
	{
		cout << (s.top()).ID << " ";
		s.pop();
	}
	cout << endl;
}

int main()
{
	//test();
	test01();
	test02();
	system("pause");
	return 0;
}