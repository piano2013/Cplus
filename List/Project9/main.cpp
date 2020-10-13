#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

void test()
{
	list<int> l;
	list<int> l1(10, 10);//有参构造
	list<int> l2(l1);//拷贝构造
	list<int> l3(l1.begin(), l1.end());

	for (list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int> mlist;

	mlist.push_back(10);
	mlist.push_front(20);

	mlist.insert(mlist.begin(), 30);
	mlist.insert(mlist.end(), 20);

	list<int>::iterator it = mlist.begin();
	it++;
	it++;
	mlist.insert(it, 50);

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	/*mlist.pop_back();
	mlist.pop_front();
	mlist.erase(mlist.begin(), mlist.end());*/

	mlist.remove(20);

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int> mlist;
	mlist.assign(10, 10);

	list<int> mlist2;
	mlist2 = mlist;

	mlist2.swap(mlist);
}

void test03()
{
	list<int> mlist;
	for (int i = 0; i < 10; i++)
	{
		mlist.push_back(i);
	}

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	mlist.reverse();

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


bool mycompare(int v1,int v2)
{
	return v1 > v2;
}
void test04()
{
	list<int> mlist;
	mlist.push_back(2);
	mlist.push_back(7);
	mlist.push_back(3);
	mlist.push_back(1);
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	mlist.sort();//默认从小到大
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	mlist.sort(mycompare);

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test04();

	system("pause");
	return 0;
}