#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct MYCHAR
{
	LinkNode node;
	char* pAddres;
	int index;
}MyChar;

int IsLeft(char c)
{
	return c == '(';
}

int IsRight(char c)
{
	return c == ')';
}

MyChar* CreatMyChar(char* p, int index)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->pAddres = p;
	mychar->index = index;

	return mychar;
}

void ShowError(char* str, int pos)
{
	printf("%s\n", str);
	for (int i = 0; i < pos; i++)
	{
		printf(" ");
	}
	printf("*");
}

int main()
{
	char* str = "1+2+6(dsf)df)sflp(sdfs)";
	
	//创建栈
	LinkStack* stack = Init_LinkStack();

	char* p = str;
	int index = 0;
	while (*p != '\0')
	{
		//如果是左括号，直接进栈
		if (IsLeft(*p))
		{
			Push_LinkStack(stack, (LinkNode*)CreatMyChar(p, index));
		}

		//如果是右括号，从栈顶弹出元素，判断是不是左括号
		if (IsRight(*p))
		{
			if (Size_LinkStack(stack) > 0)
			{
				MyChar* mychar = (MyChar*)Front_LinkStack(stack);
				if (IsLeft(*(mychar->pAddres)))
				{
					Pop_LinkStack(stack);
					free(mychar);
				}
			}
			else
			{
				printf("右括号没有匹配的左括号：\n");
				ShowError(str, index);
				break;
			}
		}

		p++;
		index++;
	}

	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Front_LinkStack(stack);
		printf("左括号没有匹配的右括号：\n");
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		free(mychar);
	}

	printf("\n");

	system("pause");
	return 0;
}