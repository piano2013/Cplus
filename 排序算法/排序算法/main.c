#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 20000

long GetSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//交换函数
void Swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

//冒泡排序(从小到大)
void BubbleSort(int arr[], int length)
{
	for (int i = 0; i < length; i++)//比较次数
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//打印函数
void PrintArray(int arr[],int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int array[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		array[i] = rand() % MAX;
	}

	//printf("排序前：");
	//PrintArray(array, MAX);
	long t_start = GetSystemTime();
	BubbleSort(array, MAX);
	long t_end = GetSystemTime();
	//printf("排序后：");
	//PrintArray(array, MAX);
	printf("冒泡排序%d个元素所需时间：%ld ms\n", MAX, t_end - t_start);

	system("pause");
	return 0;
}