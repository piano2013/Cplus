#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void test()
{
	queue<int> q1;

	queue<int> q2(q1);

	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);

	cout << "��βԪ�أ�" << q1.back() << endl;

	while (q1.size()>0)
	{
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;
}

//queue������Ŷ���ָ��
//queue�������stack����
void test01()
{
	stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	stack<int> s2;
	s2.push(70);
	s2.push(80);
	s2.push(90);

	stack<int> s3(s2);

	queue<stack<int>> q;
	q.push(s1);
	q.push(s2);
	q.push(s3);

	//��ӡ
	while (!q.empty())
	{
		while (!(q.front()).empty())
		{
			cout << (q.front()).top() << " ";
			(q.front()).pop();
		}
		q.pop();
	}
	cout << endl;
}
int main()
{
	test01();

	system("pause");
	return 0;
}