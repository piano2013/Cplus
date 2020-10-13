#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

typedef struct PERSON
{
	LinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(LinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s Age:%d\n", p->name, p->age);
}

int MyCompare(LinkNode* list, LinkNode* data)
{
	Person* p1 = (Person*)list;
	Person* p2 = (Person*)data;

	int flag = -1;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		flag = 0;
	}

	return flag;
}

int main()

{
	LinkList* list = Init_LinkList();
	
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

	//将结点插入链表
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

	//打印
	Print_LinkList(list, MyPrint);

	printf("---------------\n");

	//删除结点
	Remove_LinkList(list, 1);

	//打印
	Print_LinkList(list, MyPrint);

	//查找
	Person findP;
	strcpy(findP.name, "ddd");
	findP.age = 40;
	int i = Find_LinkList(list, (LinkNode*)&findP, MyCompare);
	printf("----查找结果----\n");
	if (i != -1)
	{
		LinkNode* l = At_LinkList(list, i);
		Person* p = (Person*)l;
		printf("list[%d]->age=%d\nlist[%d]->name=%s\n", i, p->age, i, p->name);
	}
	else 
	{
		printf("Error!\n");
	}

	system("pause");
	return 0;
}