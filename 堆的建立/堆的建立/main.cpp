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
	int length; //数组当前长度
}MinHeap;

//对数组进行元素的输入
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

//最小堆的初始化
Status Init_MinHeap(MinHeap* M)
{
	int Number;
	M->length = 0;
	printf("请输入数组的元素个数：\n");
	scanf("%d", &Number);
	printf("请输入%d个数据：\n", Number);
	Init_heapArray(M, Number);
	return OK;
}

int MinHeap_Leftchild(int pos)  //返回左孩子的下标
{
	return 2 * pos + 1;
}

int MinHeap_Rightchild(int pos) //返回右孩子的下标
{
	return 2 * pos + 2;
}

int MinHeap_Parent(int pos) //返回双亲的下标
{
	return (pos - 1) / 2;
}

void MinHeap_SiftDown(MinHeap* M, int left) //从left开始向下筛选
{
	int i = left; //标识父结点
	int j = MinHeap_Leftchild(i); //用于记录关键值较小的子结点
	ElemType temp = M->heapArray[i];  //保存父结点
	while (j<M->length)  //过筛
	{
		if ((j<M->length - 1) && (M->heapArray[j]>M->heapArray[j + 1]))    //若有右子结点，且小于左子结点
		{
			j++;    //j指向右子结点
		}
		if (temp>M->heapArray[j])    //如果父结点大于子结点的值则交换位置
		{
			M->heapArray[i] = M->heapArray[j];
			i = j;
			j = MinHeap_Leftchild(j);
		}
		else    //堆序性满足时则跳出
		{
			break;
		}
	}
	M->heapArray[i] = temp;
}

//建立最小堆
void Create_MinHeap(MinHeap* M)
{
	for (int i = M->length / 2 - 1; i >= 0; i--)
	{
		MinHeap_SiftDown(M, i);
	}
}

//输出元素
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
	printf("输出先前元素：\n");
	Print(&M);
	Create_MinHeap(&M);
	printf("输出最小堆的元素：\n");
	Print(&M);
	system("pause");
	return 0;
}