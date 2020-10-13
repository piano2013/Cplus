#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>//动态数组 可变数组
#include <algorithm>
using namespace std;

//容器也可以存放自定义的数据类型
class Person {
public:
	Person(int age, int id) :age(age), id(id) {}
public:
	int age;
	int id;
};

void PrintVector(int v)
{
	cout << v << endl;
}

void PrintVector2(Person* v2)
{
	cout << v2->age << " " << v2->id << endl;
}

void PrintVector3(vector<int>& v3)
{
	vector<int>::iterator pBegin = v3.begin();
	vector<int>::iterator pEnd = v3.end();
	for (vector<int>::iterator it = pBegin; it != pEnd; it++)
	{
		cout << *it << " ";
	}
	
}

void test01()
{
	vector<int> v;//定义一个容器，并且指定这个容器存放的元素类型是int
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//通过STL提供的for_each算法
	//容器提供迭代器
	//vector<int>::iterator 迭代器的类型
	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();
	//容器中可能存放基础的数据类型，也可能存放自定义的数据类型
	for_each(pBegin, pEnd, PrintVector);
}



void test02()
{
	//创建容器，并且指定容器的元素类型是Person
	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(50, 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).age << " " << (*it).id << endl;
	}
}


//容器中存放Person类型的指针，并且使用for_each打印或者迭代器方式打印
void test03()
{
	vector<Person*> ptr;
	/*Person* p1 = new Person(10, 20);
	Person* p2 = new Person(30, 40);
	Person* p3 = new Person(50, 60);
	ptr.push_back(p1);
	ptr.push_back(p2);
	ptr.push_back(p3);*/
	Person p1(10, 20), p2(30, 40), p3(50, 60);
	ptr.push_back(&p1);
	ptr.push_back(&p2);
	ptr.push_back(&p3);

	//vector<Person*>::iterator ptrBegin = ptr.begin();
	//vector<Person*>::iterator ptrEnd = ptr.end();
	//for_each(ptrBegin,ptrEnd, PrintVector2);

	for (vector<Person*>::iterator it = ptr.begin(); it != ptr.end(); it++)
	{
		cout << (*it)->age << " " << (*it)->id << endl;
	}

}

bool Find(int target, vector<vector<int> > array) {
	int len = sizeof(array) / sizeof(int) / array.size();
	int i = 0;
	int j = len - 1;
	while (i < array.size() && j >= 0) {
		int end = array[i][j];
		if (target == end) {
			return true;
		}

		if (target < end) {
			j--;
		}
		else {
			i++;
		}
	}

	return false;
}

//容器嵌套容器 一个容器作为另一个容器的元素
void test04()
{
	vector<int> arr1,arr2,arr3;
	vector<vector<int>> ary;
	arr1.push_back(10);
	arr1.push_back(20);
	arr2.push_back(30);
	arr2.push_back(40);
	arr3.push_back(50);
	arr3.push_back(60);
	ary.push_back(arr1);
	ary.push_back(arr2);
	ary.push_back(arr3);

	//vector<vector<int>>::iterator pBegin = ary.begin();
	//vector<vector<int>>::iterator pEnd = ary.end();
	//for_each(pBegin, pEnd, PrintVector3);

	for (vector<vector<int>>::iterator it = ary.begin(); it != ary.end(); it++)
	{
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << " ";
		}
	}
	
	cout << endl;
	bool a = Find(70, ary);
	cout << a << endl;
}



int main(void)
{
	test04();
	
	system("pause");
	return 0;
}