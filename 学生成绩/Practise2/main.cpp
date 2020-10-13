#include<iostream>

#define LEN sizeof(struct student)

struct student *creat();
void myprint(struct student *head);

struct student
{
	long num;
	float score;
	struct student *next;
};

int n;

void main()
{
	struct student *stu;
	stu = creat();
	myprint(stu);
	system("pause");
}

/*struct student *creat()
{
	struct student *p1, *p2, *head;
	n = 0;
	head = NULL;
	p2 = p1 = (struct student *)malloc(LEN);
	while (p1->num != 0)
	{		
		printf("Please input xuehao:");
		scanf_s("%d", &p1->num);
		printf("Please input chengji:");
		scanf_s("%f", &p1->score);
		printf("\n\n");
		n++;
		if (n == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
	}
	p2->next = NULL;
	return head;
}
*/
struct student *creat()
{
	struct student *head;
	struct student *p1, *p2;

	p1 = p2 = (struct student *)malloc(LEN);  // LEN是student结构的大小

	printf("Please enter the num :");
	scanf_s("%d", &p1->num);
	printf("Please enter the score :");
	scanf_s("%f", &p1->score);

	head = NULL;
	n = 0;

	while (0 != p1->num)
	{
		n++;
		if (1 == n)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}

		p2 = p1;

		p1 = (struct student *)malloc(LEN);

		printf("\nPlease enter the num :");
		scanf_s("%d", &p1->num);
		printf("Please enter the score :");
		scanf_s("%f", &p1->score);
	}

	p2->next = NULL;

	return head;
}
void myprint(struct student *head)
{
	struct student *p;
	printf("\nThere are %d records!\n\n", n);

	p = head;
	if (NULL != head)
	{
		do
		{
			printf("学号为 %d 的成绩是: %f\n", p->num, p->score);
			p = p->next;
		} while (NULL != p);
	}
}