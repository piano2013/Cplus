#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

//�º���
class mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}

};
	 
void printset1(set<int,mycompare>& s1)
{
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printset(set<int>& s1)
{
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test()
{

	set<int> s1;
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);
	//Ĭ������
	printset(s1);

	set<int,mycompare> s;
	s.insert(7);
	s.insert(2);
	s.insert(4);
	s.insert(5);
	s.insert(1);
	//�޸�����
	printset1(s);
#if 0
	//��ֵ
	set<int> s2;
	s2 = s1;

	//ɾ��
	s1.erase(s1.begin());
	printset(s1);
	s1.erase(7);
	printset(s1);
#endif
}

void test01()
{
	set<int> s1;
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);

	set<int>::iterator it = s1.find(14);
	if (it == s1.end())
	{
		cout << "Not find!" << endl;
	}
	else {
	
		cout << "val:" << *it << endl;
	}

	it = s1.lower_bound(3);//�ҵ���һ�����ڵ��ڲ��ҵ����ݵĵ�����
	if (it == s1.end())
	{
		cout << "Not find!" << endl;
	}
	else {

		cout << "val:" << *it << endl;
	}
	//����low_bound��upper_bound��ֵ
	pair<set<int>::iterator, set<int>::iterator> myret = s1.equal_range(2);
	if (myret.first == s1.end())
	{
		cout << "Not find!" << endl;
	}
	else {
		cout << "val:" << *(myret.first) << endl;
	}

	if (myret.second == s1.end())
	{
		cout << "Not find!" << endl;
	}
	else {
		cout << "val:" << *(myret.second) << endl;
	}
}

class Person
{
public:
	Person(int id, int age) :id(id), age(age) {}
public:
	int id;
	int age;
};
class mysort {
public:
	bool operator()(Person p1, Person p2)const
	{
		return p1.age > p2.age;
	}
};
void test02()
{
	set<Person, mysort> sp;
	//setĬ�����򣬷������ʱ��Ҫָ�������������
	Person p1(10, 20), p2(30, 40), p3(50, 60);
	sp.insert(p1);
	sp.insert(p2);
	sp.insert(p3);

	Person p4(10, 40);
	for (set<Person, mysort>::iterator it = sp.begin(); it != sp.end(); it++)
	{
		cout << (*it).age << " " << (*it).id << endl;
	}
	cout << endl;

	//����
	set<Person, mysort>::iterator ret = sp.find(p4);
	if (ret == sp.end())
	{
		cout << "Not find!" << endl;
	}
	else {
		cout << "ret:" << (*ret).age << " " << (*ret).id << endl;
	}
}

int main()
{
	test02();

	system("pause");
	return 0;
}
