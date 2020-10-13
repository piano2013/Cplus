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

//创建数组
int* CreatArray()
{
	srand((unsigned int)time(NULL));
	int* arr = (int*)malloc(sizeof(int)*MAX);
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	return arr;
}

//打印数组
void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//合并
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//表示辅助空间有多少元素
	int length = 0;

	//合并两个有序序列
	while (i_start <= i_end&&j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	//i这个序列
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j这个序列
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}

	//辅助空间数据覆盖到原空间
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//归并排序
void MergeSort(int arr[], int start, int end, int* temp)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;
	//分组
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);

	//合并
	Merge(arr, start, end, mid, temp);
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

int main()
{
	//int* myArr = CreatArray();
	//PrintArray(myArr, MAX);
	int arr1[MAX];
	int arr2[MAX];
	int arr3[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int RandNum = rand() % MAX;
		arr1[i] = RandNum;
		arr2[i] = RandNum;
		arr3[i] = RandNum;
	}

	//归并排序
	//辅助空间
	int* temp = (int*)malloc(sizeof(int)*MAX);
	long t1_start = GetSystemTime();
	MergeSort(arr1, 0, MAX - 1, temp);
	long t1_end = GetSystemTime();
	//PrintArray(myArr, MAX);
	printf("归并排序%d个元素所需时间:%ld ms\n", MAX, t1_end - t1_start);
	//释放空间
	free(temp);
	//free(myArr);

	//快速排序
	long t2_start = GetSystemTime();
	QuickSort(arr2, 0, MAX - 1);
	long t2_end = GetSystemTime();
	printf("快速排序%d个元素所需时间:%ld ms\n", MAX, t2_end - t2_start);

	//希尔排序
	long t3_start = GetSystemTime();
	ShellSort(arr3, MAX);
	long t3_end = GetSystemTime();
	printf("希尔排序%d个元素所需时间:%ld ms\n", MAX, t3_end - t3_start);

	system("pause");
	return 0;
}