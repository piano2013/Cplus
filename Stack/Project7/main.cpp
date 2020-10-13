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
	cout << "ջ��Ԫ�أ�" << s1.top() << endl;
	s1.pop();

	//��ӡ
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	cout << s1.size() << endl;
}

//ջ������Ŷ���ָ��
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

//ջ������Ŷ���
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