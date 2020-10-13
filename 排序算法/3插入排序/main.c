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

//��������
void Swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

//��ӡ����
void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��������(��С����)
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
	int array[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		array[i] = rand() % MAX;
	}

	//printf("����ǰ��");
	//PrintArray(array, MAX);
	long t_start = GetSystemTime();
	InsertSort(array, MAX);
	long t_end = GetSystemTime();
	//printf("�����");
	//PrintArray(array, MAX);
	printf("��������%d��Ԫ������ʱ�䣺%ld ms\n", MAX, t_end - t_start);

	system("pause");
	return 0;
}