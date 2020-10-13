#include "LinkList.h"

//��ʼ������
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;

	//ͷ��� ������������Ϣ
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

//ָ��λ�ò���
void Insert_LinkList(LinkList* List, int pos, void* data)
{
	if (List == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//posԽ��
	if (pos<0 || pos>List->size)
	{
		pos = List->size;
	}

	//�����µĽ��
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//�ҽ��
	//����ָ�����
	LinkNode* pCurrent = List->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�½��������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	List->size++;
}

//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* List, int pos)
{
	if (List == NULL)
	{
		return;
	}
	if (pos < 0 || pos>=List->size)
	{
		return;
	}

	//����ɾ������ǰһ�����
	LinkNode* pCurrent = List->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//����ɾ���Ľ��
	LinkNode* pNext;
	pNext = pCurrent->next;
	pCurrent->next = pNext->next;
	
	//�ͷ�ɾ�������ڴ�
	free(pNext);

	List->size--;
}

//�������ĳ���
int Size_LinkList(LinkList* List)
{
	return List->size;
}

//����
int Find_LinkList(LinkList* List, void* data)
{
	if (List == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}

	//��������
	LinkNode* pCurrent = List->head->next;
	int i = 0;
	while (pCurrent != NULL)
	{
		if (pCurrent->data == data)
		{
			break;
		}
		i++;
		pCurrent = pCurrent->next;
	}
	return i;
}

//��ӡ������
void Print_LinkNode(LinkList* List, PRINTLINKNODE print)
{
	if (List == NULL)
	{
		return;
	}
	//����ָ�����
	LinkNode* pCurrent = List->head->next;
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//���ص�һ�����
void* Front_LinkNode(LinkList* List)
{
	return List->head->next->data;
}

//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* List)
{
	if (List == NULL)
	{
		return;
	}

	//����ָ�����
	LinkNode* pCurrent = List->head;
	while (pCurrent != NULL)
	{
		//������һ������ַ
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	//�ͷ������ڴ�
	List->size = 0;
	free(List);
}