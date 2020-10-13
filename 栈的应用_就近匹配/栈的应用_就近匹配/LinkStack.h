#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINKSTACK_TRUE 1
#define LINKSTACK_FALSE 0

//��ʽջ�Ľ��
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

typedef struct LINKSTACK
{
	LinkNode head;
	int size;
}LinkStack;

//��ʼ������
LinkStack* Init_LinkStack();
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//����ջ��Ԫ��
LinkNode* Front_LinkStack(LinkStack* stack);
//��ջ
void Pop_LinkStack(LinkStack* stack);
//�ж��Ƿ�Ϊ��
int IsEmpty_LinkStack(LinkStack* stack);
//����ջ��Ԫ�صĸ���
int Size_LinkStack(LinkStack* stack);
//���ջ
void Clear_LinkStack(LinkStack* stack);
//����
void FreeSpace_LinkStack(LinkStack* stack);