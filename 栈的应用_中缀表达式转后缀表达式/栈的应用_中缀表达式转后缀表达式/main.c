#define _CRE_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct MYCHAR
{
	LinkNode node;
	char* p;
}MyChar;

MyChar* CreatMyChar(char* p)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;

	return mychar;
}

//返回运算符号优先级
int GetPriority(char c)
{
	if (c == '*' || c == '/')
	{
		return 2;
	}

	if (c == '+' || c == '-')
	{
		return 1;
	}

	return 0;
}

//判断是否是数字
int IsNumber(char c)
{
	return c <= '9'&&c >= '0';
}

void NumberOperate(char* c)
{
	printf("%c", *c);
}

//判断是不是左括号
int IsLeft(char c)
{
	return c == '(';
}

void LeftOperate(LinkStack* stack, char* c)
{
	Push_LinkStack(stack, (LinkNode*)CreatMyChar(c));
}

//判断是不是右括号
int IsRight(char c)
{
	return c == ')';
}

void RightOperate(LinkStack* stack)
{
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);

		if (IsLeft(*(mychar->p)))
		{
			Pop_LinkStack(stack);
			return;
		}

		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);

		//释放内存
		free(mychar);
	}
}

//判断是不是运算符号
int IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void OperatorOperate(LinkStack* stack, char* c)
{
	//先取出栈顶元素
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)CreatMyChar(c));
		return;
	}

	//如果栈顶元素优先级低于当前字符的优先级，直接入栈
	if (GetPriority(*(mychar->p)) < GetPriority(*c))
	{
		Push_LinkStack(stack, (LinkNode*)CreatMyChar(c));
		return;
	}
	//如果栈顶元素的优先级不低于当前字符的优先级
	else
	{
		Pop_LinkStack(stack);
		while (Size_LinkStack(stack) > 0)
		{
			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);
			if (GetPriority(*(mychar2->p)) < GetPriority(*c))
			{
				Push_LinkStack(stack, (LinkNode*)CreatMyChar(c));
				break;
			}

			//输出
			printf("%c", *(mychar2->p));
			//弹出
			Pop_LinkStack(stack);
			//释放内存
			free(mychar2);
		}
		Push_LinkStack(stack, (LinkNode*)CreatMyChar(c));
	}
}

int main()
{
	char* str = "8+(3-1)*5";
	
	LinkStack* stack = Init_LinkStack();
	char* p = str;

	while (*p != '\0')
	{
		if (IsNumber(*p))
		{
			NumberOperate(p);
		}

		if (IsLeft(*p))
		{
			LeftOperate(stack, p);
		}

		if (IsRight(*p))
		{
			RightOperate(stack);
		}

		if (IsOperator(*p))
		{
			OperatorOperate(stack, p);
		}
		p++;
	}

	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}
	printf("\n");
	system("pause");
	return 0;
}