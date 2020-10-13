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

//ð������(��С����)
void BubbleSort(int arr[], int length)
{
	for (int i = 0; i < length; i++)//�Ƚϴ���
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

//��ӡ����
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

	//printf("����ǰ��");
	//PrintArray(array, MAX);
	long t_start = GetSystemTime();
	BubbleSort(array, MAX);
	long t_end = GetSystemTime();
	//printf("�����");
	//PrintArray(array, MAX);
	printf("ð������%d��Ԫ������ʱ�䣺%ld ms\n", MAX, t_end - t_start);

	system("pause");
	return 0;
}