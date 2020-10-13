#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MyPrint
{
	MyPrint()
	{
		mNum = 0;
	}
	void operator()(int val)
	{
		mNum++;
		cout << val << endl;
	}
public:
	int mNum;
};

int num = 0;//真正在开发中，尽量去避免使用全局变量
void MyPrint02(int val)
{
	num++;
	cout << val << endl;
}

void test()
{
	MyPrint print;
	print(10);

	//函数对象可以像普通函数一样调用
	//函数对象可以像普通函数那样接收参数
	//函数对象超出了函数的概念，函数对象可以保存函数调用的状态
}

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	MyPrint print;
	MyPrint print02 = for_each(v.begin(), v.end(), print);
	cout << "Print调用次数：" << print.mNum << endl;
	cout << "Print调用次数：" << print02.mNum << endl;//正确的调用次数
}

int main()
{
	test01();

	system("pause");
	return 0;
}