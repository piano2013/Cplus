#include "CircleLinkList.h"

//��ʼ������
CircleLinkList* Init_CircleLinkList()
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;
	
	return clist;
}

//���뺯��
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data)
{
	if (clist == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	if (pos<0 || pos>clist->size)
	{
		pos = clist->size;
	}

	//����λ�ò��ҽ��
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����ݲ�������
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
}

//��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist)
{
	return clist->head.next;
}

//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}

	if (pos<0 || pos>=clist->size)
	{
		return;
	}

	//����pos�ҽ��
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//���浱ǰ������һ�����
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;

	clist->size--;
}

//����ֵɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = pPrev->next;
	int i = 0;
	for (i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent,data) == CIRCLELINKLIST_TRUE)
		{
			pPrev->next = pCurrent->next;
			clist->size--;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}

//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist)
{
	if (clist->size == 0)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

//����
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return -1;
	}

	if (data == NULL)
	{
		return -1;
	}

	CircleLinkNode* pCurrent = clist->head.next;
	int flag = -1;
	int i = 0;
	for (i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE)
		{
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}
	return flag;
}

//��ӡ���
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print)
{
	if (clist == NULL)
	{
		return;
	}

	//����ָ�����
	CircleLinkNode* pCurrent = clist->head.next;
	int i = 0;
	for (i = 0; i < clist->size * 2; i++)
	{
		if (pCurrent == &(clist->head))
		{
			pCurrent = pCurrent->next;
			printf("------------------------\n");
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}

//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist)
{
	if (clist == NULL)
	{
		return;
	}

	free(clist);
}