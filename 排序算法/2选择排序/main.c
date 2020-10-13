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

//打印函数
void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//选择排序(从小到大)
void SelectSort(int arr[], int length)
{	
	for (int i = 0; i < length; i++)
	{
		int min = i;
		for (int j = i; j < length; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			Swap(&arr[min], &arr[i]);
		}
	}
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
	SelectSort(array, MAX);
	long t_end = GetSystemTime();
	//printf("排序后：");
	//PrintArray(array, MAX);
	printf("选择排序%d个元素所需时间：%ld ms\n", MAX, t_end - t_start);

	system("pause");
	return 0;
}