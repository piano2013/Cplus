#ifndef CIRCLELINKLIST
#define CIRCLELINKLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����С���
typedef struct CIRCLELINKNODE
{
	struct CIRCLELINKNODE* next;
}CircleLinkNode;

//����ṹ��
typedef struct CIRCLELINKLIST
{
	CircleLinkNode head;
	int size;
}CircleLinkList;

//��д�������ṹ�������API����

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//�Ƚϻص�
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);
//��ӡ�ص�
typedef void(*PRINTNODE)(CircleLinkNode*);

//��ʼ������
CircleLinkList* Init_CircleLinkList();
//���뺯��
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);
//��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);
//����ֵɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);
//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist);
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist);
//����
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);
//��ӡ���
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);
//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist);

#endif