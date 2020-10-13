#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType heapArray[MAXSIZE];
	int length; //���鵱ǰ����
}MinHeap;

//���������Ԫ�ص�����
Status Init_heapArray(MinHeap* M, int Number)
{
	ElemType data;
	for (int i = 0; i<Number; i++)
	{
		scanf("%d", &data);
		M->heapArray[i] = data;
		M->length++;
	}
	return OK;
}

//��С�ѵĳ�ʼ��
Status Init_MinHeap(MinHeap* M)
{
	int Number;
	M->length = 0;
	printf("�����������Ԫ�ظ�����\n");
	scanf("%d", &Number);
	printf("������%d�����ݣ�\n", Number);
	Init_heapArray(M, Number);
	return OK;
}

int MinHeap_Leftchild(int pos)  //�������ӵ��±�
{
	return 2 * pos + 1;
}

int MinHeap_Rightchild(int pos) //�����Һ��ӵ��±�
{
	return 2 * pos + 2;
}

int MinHeap_Parent(int pos) //����˫�׵��±�
{
	return (pos - 1) / 2;
}

void MinHeap_SiftDown(MinHeap* M, int left) //��left��ʼ����ɸѡ
{
	int i = left; //��ʶ�����
	int j = MinHeap_Leftchild(i); //���ڼ�¼�ؼ�ֵ��С���ӽ��
	ElemType temp = M->heapArray[i];  //���游���
	while (j<M->length)  //��ɸ
	{
		if ((j<M->length - 1) && (M->heapArray[j]>M->heapArray[j + 1]))    //�������ӽ�㣬��С�����ӽ��
		{
			j++;    //jָ�����ӽ��
		}
		if (temp>M->heapArray[j])    //������������ӽ���ֵ�򽻻�λ��
		{
			M->heapArray[i] = M->heapArray[j];
			i = j;
			j = MinHeap_Leftchild(j);
		}
		else    //����������ʱ������
		{
			break;
		}
	}
	M->heapArray[i] = temp;
}

//������С��
void Create_MinHeap(MinHeap* M)
{
	for (int i = M->length / 2 - 1; i >= 0; i--)
	{
		MinHeap_SiftDown(M, i);
	}
}

//���Ԫ��
void Print(MinHeap* M)
{
	for (int i = 0; i<M->length; i++)
	{
		printf("%d ", M->heapArray[i]);
	}
	printf("\n");
}

int main()
{
	MinHeap M;
	Init_MinHeap(&M);
	printf("�����ǰԪ�أ�\n");
	Print(&M);
	Create_MinHeap(&M);
	printf("�����С�ѵ�Ԫ�أ�\n");
	Print(&M);
	system("pause");
	return 0;
}