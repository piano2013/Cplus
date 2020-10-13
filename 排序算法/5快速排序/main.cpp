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

//��ӡ����
void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
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

int main()
{
	int array[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		array[i] = rand() % MAX;
	}
	//int len = sizeof(array) / sizeof(int);
	//printf("����ǰ��\n");
	//printf("Array:");
	//PrintArray(array, len);

	long t_start = GetSystemTime();
	QuickSort(array, 0, MAX - 1);
	long t_end = GetSystemTime();
	//printf("�����\n");
	//printf("Array:");
	//PrintArray(array, len);
	printf("��������%d��Ԫ�������ʱ��Ϊ��%ld ms\n", MAX, t_end - t_start);

	system("pause");
	return 0;
}