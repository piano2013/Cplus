#include<iostream>
#include"MyArray.h"

using namespace std;

int main()
{
	cout << "���ԡ���������" << endl;
	MyArray array1(10);
	cout << "==============" << endl;
	cout << "��ֵ���ԡ�����" << endl;
	for (int i = 0; i < 10; i++)
	{
		array1.setData(i, i + 10);
	}
	cout << "array1:" << endl;
	for (int i = 0; i < 10; i++)
	{
				cout << array1.getData(i) << " ";
	}
	cout << endl;
	cout << "==============" << endl;
	cout << "�������ԡ�����" << endl;
	MyArray array2 = array1;
	cout << "array2:" << endl;
	for (int i = 0; i < array2.getLen(); i++)
	{
		cout << array2.getData(i) << " ";
	}
	cout << endl;

	return 0;

}
