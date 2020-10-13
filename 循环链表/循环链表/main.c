#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CircleLinkList.h"

typedef struct PERSON
{
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(CircleLinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s,Age:%d,Score:%d\n", p->name, p->age, p->score);
}

int MyCompare(CircleLinkNode* pCurrent, CircleLinkNode* data)
{
	Person* p1 = (Person*)pCurrent;
	Person* p2 = (Person*)data;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

int main()
{
	//����ѭ������
	CircleLinkList* clist = Init_CircleLinkList();

	//��������
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;

	p1.score = 50;
	p2.score = 55;
	p3.score = 60;
	p4.score = 65;
	p5.score = 70;

	//β�巨
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p5);

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);

	printf("------------------------\n");

	//ɾ��
	Person pDel;
	strcpy(pDel.name, "ccc");
	pDel.age = 30;
	pDel.score = 60;

	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&pDel, MyCompare);

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);

	//�ͷ��ڴ�
	FreeSpace_CircleLinkList(clist);

	system("pause");
	return 0;
}