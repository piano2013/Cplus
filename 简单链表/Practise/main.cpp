#include<iostream>

struct student
{
	long num;
	float score;
	struct student *next;
};

void main()
{
	struct student a, b, c, *head;

	a.num = 10101;
	a.score = 89.5;
	b.num = 10103;
	b.score = 90;
	c.num = 10107;
	c.score = 85;

	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	do
	{
		printf("%1d %5.1f\n", head->num, head->score);
		head = head->next;
	} while (head);
	system("pause");
}