#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//�º��������� bind1st bind2nd �������� ��һ����Ԫ�ĺ�������ת���һԪ��������
struct MyPrint:public binary_function<int,int,void>
{
	void operator()(int v,int val) const
	{
		cout << "v:" << v << "val:" << val << endl;
		cout << v + val << " ";
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	int addNum = 100;
	for_each(v.begin(), v.end(), bind2nd(MyPrint(),addNum));
	cout << endl;
}

//�º��������� not1 not2 ȡ��������
struct MyCompare :public binary_function<int, int, bool>
{
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

struct MyPrint02
{
	void operator()(int v)
	{
		cout << v << " ";
	}
};

struct MyGreater50:public unary_function<int,bool>
{
	bool operator()(int v) const
	{
		return v > 50;
	}
};

void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100);
	}

	for_each(v.begin(), v.end(), MyPrint02());
	cout << endl;

	sort(v.begin(), v.end(), not2(MyCompare()));

	for_each(v.begin(), v.end(), MyPrint02());
	cout << endl;

	vector<int>::iterator it = find_if(v.begin(), v.end(), MyGreater50());
	if (it == v.end())
	{
		cout << "Not find!" << endl;
	}
	else 
	{
		cout << *it << endl;
	}

	vector<int>::iterator rit = find_if(v.begin(), v.end(), not1(MyGreater50()));
	if (rit == v.end())
	{
		cout << "Not find!" << endl;
	}
	else
	{
		cout << *rit << endl;
	}
}

//�º��������� ptr_fun
void MyPrint03(int val,int val2)
{
	cout << "val1:" << val << " val2:" << val2 << endl;
	cout << val + val2 << endl;
}
void test03()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//����ͨ����ת�ɺ�������
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint03), 10));
}

//��Ա���������� men_fun men_fun_ref
class Person
{
public:
	Person(int age, int id) :age(age), id(id) {}
	void show()
	{
		cout << "age:" << age << " id:" << id << endl;
	}
public:
	int age;
	int id;
};

void test04()
{
	//��������д���Ŷ�����߶���ָ�룬����ϣ��for_each�㷨��ӡ��ʱ�򣬵������Լ��ṩ�Ĵ�ӡ����
	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(50, 60);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for_each(v.begin(), v.end(), mem_fun_ref(&Person::show));

	vector<Person*> v1;

	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);

	for_each(v1.begin(), v1.end(), mem_fun(&Person::show));
}

int main()
{
	test04();

	system("pause");
	return 0;
}