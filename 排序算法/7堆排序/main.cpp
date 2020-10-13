#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

//��ӡ����
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
	@param myArr ������������
	@param index �������Ľ����±�
	@param len   ����ĳ���
*/
void HeapAdjust(int arr[], int index, int len)
{
	//�ȱ��浱ǰ�����±�
	int max = index;
	//�������������������±�
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
		//�����������
		MySwap(arr, max, index);
		HeapAdjust(arr, max, len);
	}
}

//������
void HeapSort(int arr[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(arr, i, len);
	}
	//cout << arr[0] << endl;

	//�����Ѷ�Ԫ�غ�ĩβԪ��
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
	printf("����ǰ:");
	PrintArray(myArr, len);
	HeapSort(myArr, len);
	printf("�����:");
	PrintArray(myArr, len);
	system("pause");
	return 0;
}