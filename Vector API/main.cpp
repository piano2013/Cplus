#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Printvector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Printvector2(int v)
{
	cout << v << " ";
}

void test()
{
	
	int arr[] = { 1,2,3,4,5,6 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());

	vector<int> v3;
	v3 = v2;

	int arr1[] = { 10,20,30,40 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));
	v4.swap(v1);
	
	Printvector(v1);
	Printvector(v2);
	Printvector(v3);
	Printvector(v4);

}

//´óÐ¡²Ù×÷
void test01()
{
	int arr[] = { 1,24,67,6 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test02()
{
	vector<int> v;
	v.reserve(100000);
	int *p = NULL;
	int count = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
		}
	}
}

int main()
{
	//vector<int> v = { 10, 20, 30, 40 };
	
	//vector<int>::iterator pBegin = v.begin();
	//vector<int>::iterator pEnd = v.end();
	/*vector<int>::reverse_iterator prBegin = v.rbegin();
	vector<int>::reverse_iterator prEnd = v.rend();
	for_each(prBegin, prEnd, Printvector2);*/
	
	test();

	system("pause");
	return 0;
}
