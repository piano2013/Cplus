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

//��������
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

//��ӡ����
void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�ϲ�
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//��ʾ�����ռ��ж���Ԫ��
	int length = 0;

	//�ϲ�������������
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
	//i�������
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j�������
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}

	//�����ռ����ݸ��ǵ�ԭ�ռ�
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//�鲢����
void MergeSort(int arr[], int start, int end, int* temp)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;
	//����
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);

	//�ϲ�
	Merge(arr, start, end, mid, temp);
}

//�������� ��С����
void QuickSort(int arr[], int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];//��׼��
	if (i < j)
	{
		while (i < j)
		{
			//�������� �ұȻ�׼��С��Ԫ��
			while (i < j&&arr[j] >= temp)
			{
				j--;
			}
			//���
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}

			//�������� �ұȻ�׼�����Ԫ��
			while (i < j&&arr[i] < temp)
			{
				i++;
			}
			//���
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		//�ѻ�׼���ŵ�i��λ��
		arr[i] = temp;
		//����벿�ֽ��п�������
		QuickSort(arr, start, i - 1);
		//���Ұ벿�ֽ��п�������
		QuickSort(arr, i + 1, end);
	}
}

//ϣ������(��С����)
void ShellSort(int arr[], int length)
{
	int increasement = length;
	int i = 0, j = 0, k = 0;
	do
	{
		//ȷ�����������
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

	//�鲢����
	//�����ռ�
	int* temp = (int*)malloc(sizeof(int)*MAX);
	long t1_start = GetSystemTime();
	MergeSort(arr1, 0, MAX - 1, temp);
	long t1_end = GetSystemTime();
	//PrintArray(myArr, MAX);
	printf("�鲢����%d��Ԫ������ʱ��:%ld ms\n", MAX, t1_end - t1_start);
	//�ͷſռ�
	free(temp);
	//free(myArr);

	//��������
	long t2_start = GetSystemTime();
	QuickSort(arr2, 0, MAX - 1);
	long t2_end = GetSystemTime();
	printf("��������%d��Ԫ������ʱ��:%ld ms\n", MAX, t2_end - t2_start);

	//ϣ������
	long t3_start = GetSystemTime();
	ShellSort(arr3, MAX);
	long t3_end = GetSystemTime();
	printf("ϣ������%d��Ԫ������ʱ��:%ld ms\n", MAX, t3_end - t3_start);

	system("pause");
	return 0;
}