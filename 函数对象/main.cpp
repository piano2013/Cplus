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

int num = 0;//�����ڿ����У�����ȥ����ʹ��ȫ�ֱ���
void MyPrint02(int val)
{
	num++;
	cout << val << endl;
}

void test()
{
	MyPrint print;
	print(10);

	//���������������ͨ����һ������
	//���������������ͨ�����������ղ���
	//�������󳬳��˺����ĸ������������Ա��溯�����õ�״̬
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
	cout << "Print���ô�����" << print.mNum << endl;
	cout << "Print���ô�����" << print02.mNum << endl;//��ȷ�ĵ��ô���
}

int main()
{
	test01();

	system("pause");
	return 0;
}