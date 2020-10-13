#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

void printdeque(deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//初始化
void test()
{
	deque<int> d1;
	deque<int> d2(10, 5);
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);

	printdeque(d4);
}

//赋值 大小操作
void test01()
{
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10, 5);
	d2.assign(d1.begin(), d1.end());
	d3 = d2;

	d1.swap(d2);

	if (d1.empty())
	{
		cout << "empty!" << endl;
	}
	else
	{
		cout << "size:" << d1.size() << endl;
	}

	d1.resize(5);
	printdeque(d1);
}

//插入和删除
void test02()
{
	deque<int> d1;
	d1.push_back(100);
	d1.push_front(200);
	d1.push_back(300);
	d1.push_back(400);
	d1.push_front(500);

	printdeque(d1);

	int val = d1.front();//拿到要删除的数据
	cout << val << endl;
	d1.pop_front();//删除
	printdeque(d1);

	val = d1.back();
	cout << val << endl;
	d1.pop_back();
	printdeque(d1);

}

int main()
{
	test02();

	system("pause");
	return 0;
}