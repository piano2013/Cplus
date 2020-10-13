#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//transform ��һ�������е�Ԫ�ذ��˵���һ��������
struct MyPlus
{
	int operator()(int val)
	{
		return val;
	}
};

void MyPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v1;
	vector<int> v2;
	v2.resize(100);//���ﲻ������reserve����Ϊreserve���ٵĿռ䲻���ʼ��������޷��������������

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	transform(v1.begin(), v1.end(), v2.begin(), MyPlus());
	for_each(v2.begin(), v2.end(), MyPrint);
}

//���õĲ����㷨
void test02()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>::iterator it = find(v1.begin(), v1.end(), 5);
	if (it == v1.end())
	{
		cout << "Not find!" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}

class Person
{
public:
	Person(int age, int id) :age(age), id(id) {}
	bool operator==(const Person& p) const
	{
		return p.id == this->id && p.age == this->age;
	}
public:
	int age;
	int id;
};

void test03()
{
	vector<Person> v1;

	Person p1(10, 20), p2(20, 30);

	v1.push_back(p1);
	v1.push_back(p2);

	vector<Person>::iterator it = find(v1.begin(), v1.end(), p1);
	if (it == v1.end())
	{
		cout << "Not find!" << endl;
	}
	else
	{
		cout << "age:" << (*it).age << " id:" << (*it).id << endl;
	}
}

//binary_search ���ֲ��ҷ�
void test04()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if (ret)
	{
		cout << "Find!" << endl;
	}
	else
	{
		cout << "Not find!" << endl;
	}
}

//adjacent_find ���������ظ���Ԫ��
void test05()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	v1.push_back(9);

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end())
	{
		cout << "Not find!" << endl;
	}
	else
	{
		cout << "Find:" << *it << endl;
	}
}

//find_if
bool MySearch(int val)
{
	return val > 5;
}

void test06()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>::iterator it = find_if(v1.begin(), v1.end(), MySearch);
	if (it == v1.end())
	{
		cout << "Not find!" << endl;
	}
	else
	{
		cout << "Find:" << *it << endl;
	}
}

//count count_if
bool MySearch02(int val)
{
	return val > 5;
}

void test07()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	v1.push_back(9);

	int num = count(v1.begin(), v1.end(), 9);
	cout << "9���ֵĴ�����" << num << endl;
	num = count_if(v1.begin(), v1.end(), MySearch02);
	cout << "����5�����ֵĸ�����" << num << endl;
}

int main()
{
	test07();

	system("pause");
	return 0;
}