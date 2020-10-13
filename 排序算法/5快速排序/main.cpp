#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

#define MAX 50000

long GetSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//打印函数
void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//快速排序 从小到大
void QuickSort(int arr[], int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];//基准数
	if (i < j)
	{
		while (i < j)
		{
			//从右向左 找比基准数小的元素
			while (i < j&&arr[j] >= temp)
			{
				j--;
			}
			//填坑
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}

			//从左向右 找比基准数大的元素
			while (i < j&&arr[i] < temp)
			{
				i++;
			}
			//填坑
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		//把基准数放到i的位置
		arr[i] = temp;
		//对左半部分进行快速排序
		QuickSort(arr, start, i - 1);
		//对右半部分进行快速排序
		QuickSort(arr, i + 1, end);
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
	//int len = sizeof(array) / sizeof(int);
	//printf("排序前：\n");
	//printf("Array:");
	//PrintArray(array, len);

	long t_start = GetSystemTime();
	QuickSort(array, 0, MAX - 1);
	long t_end = GetSystemTime();
	//printf("排序后：\n");
	//printf("Array:");
	//PrintArray(array, len);
	printf("快速排序%d个元素所需的时间为：%ld ms\n", MAX, t_end - t_start);

	system("pause");
	return 0;
}