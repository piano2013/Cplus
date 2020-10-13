#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

//�Զ������������
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

//��ӡ����
void MyPrint(void* data)
{
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}

int main()
{
	//��������
	LinkList* List = Init_LinkList();

	//��������
	Person p1 = { "aaa",18,100 };
	Person p2 = { "bbb",19,99 };
	Person p3 = { "ccc",20,101 };
	Person p4 = { "ddd",17,97 };
	Person p5 = { "eee",16,59 };

	//���ݲ�������
	Insert_LinkList(List, 0, &p1);
	Insert_LinkList(List, 0, &p2);
	Insert_LinkList(List, 0, &p3);
	Insert_LinkList(List, 0, &p4);
	Insert_LinkList(List, 0, &p5);

	//��ӡ
	Print_LinkNode(List, MyPrint);

	printf("-------------------------\n");

	//ɾ��3
	RemoveByPos_LinkList(List, 3);

	//��ӡ
	Print_LinkNode(List, MyPrint);

	//���ص�һ�����
	printf("--------���ҽ��---------\n");
	Person* ret = (Person*)Front_LinkNode(List);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);

	//��������
	FreeSpace_LinkList(List);

	system("pause");
	return 0;
}