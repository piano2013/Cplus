#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 50000

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

//希尔排序(从小到大)
void ShellSort(int arr[], int length)
{
	int increasement = length;
	int i = 0, j = 0, k = 0;
	do
	{
		//确定分组的增量
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++)
		{
			for (j = i + increasement; j < length; j += increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);
}

//插入排序(从小到大)
void InsertSort(int arr[], int length)
{
	int j = 0;
	for (int i = 1; i < length; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			int temp = arr[i];
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

int main()
{
	int array1[MAX];
	int array2[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int RandNum = rand() % MAX;
		array1[i] = RandNum;
		array2[i] = RandNum;
	}

	/*printf("排序前：\n");
	printf("Array1:");
	PrintArray(array1, MAX);
	printf("Array2:");
	PrintArray(array2, MAX);*/
	long t1_start = GetSystemTime();
	InsertSort(array1, MAX);
	long t1_end = GetSystemTime();
	/*printf("排序后：\n");
	printf("Array1:");
	PrintArray(array1, MAX);*/
	printf("插入排序%d个元素所需时间：%ld ms\n", MAX, t1_end - t1_start);
	long t2_start = GetSystemTime();
	ShellSort(array2, MAX);
	long t2_end = GetSystemTime();
	/*printf("Array2:");
	PrintArray(array2, MAX);*/
	printf("希尔排序%d个元素所需时间：%ld ms\n", MAX, t2_end - t2_start);

	system("pause");
	return 0;
}