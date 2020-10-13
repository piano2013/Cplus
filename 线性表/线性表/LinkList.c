#include "LinkList.h"

//初始化链表
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;

	//头结点 不保存数据信息
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

//指定位置插入
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

	//pos越界
	if (pos<0 || pos>List->size)
	{
		pos = List->size;
	}

	//创建新的结点
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//找结点
	//辅助指针变量
	LinkNode* pCurrent = List->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//新结点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	List->size++;
}

//删除指定位置的值
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

	//查找删除结点的前一个结点
	LinkNode* pCurrent = List->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//缓存删除的结点
	LinkNode* pNext;
	pNext = pCurrent->next;
	pCurrent->next = pNext->next;
	
	//释放删除结点的内存
	free(pNext);

	List->size--;
}

//获得链表的长度
int Size_LinkList(LinkList* List)
{
	return List->size;
}

//查找
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

	//遍历查找
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

//打印链表结点
void Print_LinkNode(LinkList* List, PRINTLINKNODE print)
{
	if (List == NULL)
	{
		return;
	}
	//辅助指针变量
	LinkNode* pCurrent = List->head->next;
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//返回第一个结点
void* Front_LinkNode(LinkList* List)
{
	return List->head->next->data;
}

//释放链表内存
void FreeSpace_LinkList(LinkList* List)
{
	if (List == NULL)
	{
		return;
	}

	//辅助指针变量
	LinkNode* pCurrent = List->head;
	while (pCurrent != NULL)
	{
		//缓存下一个结点地址
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	//释放链表内存
	List->size = 0;
	free(List);
}