#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//������
typedef struct LINKNODE
{
	void* data;//ָ���κ����͵�����
	struct LINKNODE* next;
}LinkNode;

//����ṹ��
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
	//����Ҫ����������Ҫ��ǰ����ռ䣩
}LinkList;

//��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);

//��ʼ������
LinkList* Init_LinkList();
//ָ��λ�ò���
void Insert_LinkList(LinkList* List, int pos, void* data);
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* List, int pos);
//�������ĳ���
int Size_LinkList(LinkList* List);
//����
int Find_LinkList(LinkList* List, void* data);
//��ӡ������
void Print_LinkNode(LinkList* List, PRINTLINKNODE print);
//���ص�һ�����
void* Front_LinkNode(LinkList* List);
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* List);