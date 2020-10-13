#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "DynamicArray.h"

void test()
{
	//初始化动态数组
	Dynamic_Array* MyArray = Init_Array();
	//打印容量
	printf("数组容量:%d\n", Capacity_Array(MyArray));
	printf("数组大小:%d\n", Size_Array(MyArray));
	//插入元素
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(MyArray, i);
	}
	printf("数组容量:%d\n", Capacity_Array(MyArray));
	printf("数组大小:%d\n", Size_Array(MyArray));
	//打印
	Print_Array(MyArray);
	//删除
	RemoveByPos_Array(MyArray, 0);
	RemoveByValue_Array(MyArray, 2);
	//打印
	Print_Array(MyArray);
	//查找
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
	//销毁
	FreeSpace_Array(MyArray);
}

int main()
{
	test();

	getchar();
	return 0;
}