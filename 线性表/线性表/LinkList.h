#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//链表结点
typedef struct LINKNODE
{
	void* data;//指向任何类型的数据
	struct LINKNODE* next;
}LinkNode;

//链表结构体
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
	//不需要容量（不需要提前申请空间）
}LinkList;

//打印函数指针
typedef void(*PRINTLINKNODE)(void*);

//初始化链表
LinkList* Init_LinkList();
//指定位置插入
void Insert_LinkList(LinkList* List, int pos, void* data);
//删除指定位置的值
void RemoveByPos_LinkList(LinkList* List, int pos);
//获得链表的长度
int Size_LinkList(LinkList* List);
//查找
int Find_LinkList(LinkList* List, void* data);
//打印链表结点
void Print_LinkNode(LinkList* List, PRINTLINKNODE print);
//返回第一个结点
void* Front_LinkNode(LinkList* List);
//释放链表内存
void FreeSpace_LinkList(LinkList* List);