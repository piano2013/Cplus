#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

//打印数组
void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void MySwap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

/*
	@param myArr 待调整的数组
	@param index 待调整的结点的下标
	@param len   数组的长度
*/
void HeapAdjust(int arr[], int index, int len)
{
	//先保存当前结点的下标
	int max = index;
	//保存左右子树的数组下标
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;

	if (lchild<len&&arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<len&&arr[rchild]>arr[max])
	{
		max = rchild;
	}

	if (max != index)
	{
		//交换两个结点
		MySwap(arr, max, index);
		HeapAdjust(arr, max, len);
	}
}

//堆排序
void HeapSort(int arr[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(arr, i, len);
	}
	//cout << arr[0] << endl;

	//交换堆顶元素和末尾元素
	for (int i = len - 1; i >= 0; i--)
	{
		MySwap(arr, 0, i);
		HeapAdjust(arr, 0, i);
	}
}

int main()
{
	int myArr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(myArr) / sizeof(int);
	printf("排序前:");
	PrintArray(myArr, len);
	HeapSort(myArr, len);
	printf("排序后:");
	PrintArray(myArr, len);
	system("pause");
	return 0;
}