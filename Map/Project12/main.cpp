#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;


void test()
{
	//map�����ĳ�ʼ��
	//map����ģ���������һ������key�����ͣ��ڶ�������value������
	map<int, int> mymap;

	//��������   pair.first ��ֵ pair.second ʵֵ
	//��һ��
	mymap.insert(pair<int, int>(10, 10));

	//�ڶ���
	mymap.insert(make_pair(20, 20));
	
	//������
	mymap.insert(map<int, int>::value_type(30, 30));

	//������
	mymap[40] = 40;

	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

void test01()
{
	//map���ܲ����ظ���key
	map<int, int> mymap;
	pair<map<int,int>::iterator,bool> ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second) {
		cout << "��һ�β���ɹ���" << endl;
	}
	else {
		cout << "��һ�β���ʧ�ܣ�" << endl;
	}

	ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second) {
		cout << "�ڶ��β���ɹ���" << endl;
	}
	else {
		cout << "�ڶ��β���ʧ�ܣ�" << endl;
	}

}

class MyKey
{
public:
	MyKey(int index, int id)
	{
		this->mID = id;
		this->mIndex = index;
	}
public:
	int mIndex;
	int mID;
};
struct mycompare
{
	bool operator()(MyKey key1, MyKey key2)
	{
		return key1.mIndex > key2.mIndex;
	}
};
void test02()
{
	map<MyKey, int, mycompare> mymap;//Ҫ�Զ�����ģ��Զ������ʱ��Ҫ�����������

	mymap.insert(make_pair(MyKey(1, 2), 10));
	mymap.insert(make_pair(MyKey(4, 5), 20));

	for (map<MyKey, int, mycompare>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << (*it).first.mID << ":" << (*it).first.mIndex << "=" << (*it).second << endl;
	}
}

void test03()
{
	map<int, int> mymap;
	mymap.insert(make_pair(1, 4));
	mymap.insert(make_pair(2, 5));
	mymap.insert(make_pair(3, 6));

	pair<map<int, int>::iterator, map<int, int>::iterator> ret = mymap.equal_range(2);
	if ((ret.first)->second)
	{
		cout << "�ҵ�lower_bound!" << endl;
	}
	else
	{
		cout << "û���ҵ���" << endl;
	}
	if ((ret.second)->second)
	{
		cout << "�ҵ�upper_bound!" << endl;
	}
	else
	{
		cout << "û���ҵ���" << endl;
	}
}

int main()
{
	test03();

	system("pause");
	return 0;
}