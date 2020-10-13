#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "DynamicArray.h"

void test()
{
	//��ʼ����̬����
	Dynamic_Array* MyArray = Init_Array();
	//��ӡ����
	printf("��������:%d\n", Capacity_Array(MyArray));
	printf("�����С:%d\n", Size_Array(MyArray));
	//����Ԫ��
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(MyArray, i);
	}
	printf("��������:%d\n", Capacity_Array(MyArray));
	printf("�����С:%d\n", Size_Array(MyArray));
	//��ӡ
	Print_Array(MyArray);
	//ɾ��
	RemoveByPos_Array(MyArray, 0);
	RemoveByValue_Array(MyArray, 2);
	//��ӡ
	Print_Array(MyArray);
	//����
	int p;
	p = Find_Array(MyArray, 5);
	if (p == -1)
	{
		printf("Cannot find!\n");
	}
	else 
	{
		printf("MyArray[%d] = %d\n", p, At_Array(MyArray, p));
	}
	//����
	FreeSpace_Array(MyArray);
}

int main()
{
	test();

	getchar();
	return 0;
}