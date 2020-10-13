#include "LinkStack.h"

//��ʼ������
LinkStack* Init_LinkStack()
{
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next = NULL;
	stack->size = 0;

	return stack;
}

//��ջ(ͷ��)
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	data->next = stack->head.next;
	stack->head.next = data;

	stack->size++;
}

//����ջ��Ԫ��
LinkNode* Front_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	if (stack->size == 0)
	{
		return NULL;
	}

	return stack->head.next;
}

//��ջ
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	if (stack->size == 0)
	{
		return;
	}

	//��һ����Ч���
	LinkNode* pNext = stack->head.next;
	stack->head.next = pNext->next;

	stack->size--;
}

//�ж��Ƿ�Ϊ��
int IsEmpty_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	
	if (stack->size == 0)
	{
		return LINKSTACK_TRUE;
	}
	return LINKSTACK_FALSE;
}

//����ջ��Ԫ�صĸ���
int Size_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	return stack->size;
}

//���ջ
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	stack->head.next = NULL;//��һ������ÿգ��������ÿ�
	stack->size = 0;
}

//����
void FreeSpace_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
}