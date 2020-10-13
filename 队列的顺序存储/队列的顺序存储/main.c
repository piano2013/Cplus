#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SeqQueue.h"

typedef struct PERSON
{
	char name[64];
	int age;
}Person;

int main()
{
	//��������
	SeqQueue* queue = Init_SeqQueue();

	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",20 };
	Person p3 = { "ccc",30 };
	Person p4 = { "ddd",40 };
	Person p5 = { "eee",50 };

	//���������
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);

	//�����βԪ��
	Person* back_person = (Person*)Back_SeqQueue(queue);
	printf("Name:%s, Age:%d\n", back_person->name, back_person->age);
	
	printf("----------------\n");

	//���
	while (Size_SeqQueue(queue) > 0)
	{
		Person* p = (Person*)Front_SeqQueue(queue);
		printf("Name:%s, Age:%d\n", p->name, p->age);
		Pop_SeqQueue(queue);
	}

	//�ͷ��ڴ�
	FreeSpace_SeqQueue(queue);

	system("pause");
	return 0;
}