#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;


void test()
{
	//map容器的初始化
	//map容器模板参数，第一个参数key的类型，第二个参数value的类型
	map<int, int> mymap;

	//插入数据   pair.first 键值 pair.second 实值
	//第一种
	mymap.insert(pair<int, int>(10, 10));

	//第二种
	mymap.insert(make_pair(20, 20));
	
	//第三种
	mymap.insert(map<int, int>::value_type(30, 30));

	//第四种
	mymap[40] = 40;

	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

void test01()
{
	//map不能插入重复的key
	map<int, int> mymap;
	pair<map<int,int>::iterator,bool> ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second) {
		cout << "第一次插入成功！" << endl;
	}
	else {
		cout << "第一次插入失败！" << endl;
	}

	ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second) {
		cout << "第二次插入成功！" << endl;
	}
	else {
		cout << "第二次插入失败！" << endl;
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
	map<MyKey, int, mycompare> mymap;//要自动排序的，自定义对象时需要定义排序规则

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
		cout << "找到lower_bound!" << endl;
	}
	else
	{
		cout << "没有找到！" << endl;
	}
	if ((ret.second)->second)
	{
		cout << "找到upper_bound!" << endl;
	}
	else
	{
		cout << "没有找到！" << endl;
	}
}

int main()
{
	test03();

	system("pause");
	return 0;
}