#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

int IsNumber(char c)
{
	return c >= '0'&&c <= '9';
}

typedef struct MYNUM
{
	LinkNode node;
	int val;
}MyNum;

int Calculate(int leftNum,int rightNum,char c)
{
	int ret = 0;
	switch (c)
	{
	case '+':
		ret = leftNum + rightNum;
		break;
	case '-':
		ret = leftNum - rightNum;
		break;
	case '*':
		ret = leftNum*rightNum;
		break;
	case '/':
		ret = leftNum / rightNum;
		break;
	default:
		break;
	}
	return ret;
}

int main()
{
	//后缀表达式
	char* str = "831-5*+";

	char* p = str;
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0')
	{
		if (IsNumber(*p))
		{
			MyNum* num = (MyNum*)malloc(sizeof(MyNum));
			num->val = *p - '0';
			//printf("%d\n", num->val);
			Push_LinkStack(stack, (LinkNode*)num);
		}
		else
		{
			//先从栈中弹出右操作数
			MyNum* right = (MyNum*)Front_LinkStack(stack);
			int rightNum = right->val;
			//printf("%d\n", rightNum);
			Pop_LinkStack(stack);
			free(right);
			//再弹出左操作数
			MyNum* left = (MyNum*)Front_LinkStack(stack);
			int leftNum = left->val;
			//printf("%d\n", leftNum);
			Pop_LinkStack(stack);
			free(left);
			//计算
			MyNum* value = (MyNum*)malloc(sizeof(MyNum));
			value->val = Calculate(leftNum, rightNum, *p);
			//结果入栈
			Push_LinkStack(stack, (LinkNode*)value);
		}
		p++;
	}

	if (Size_LinkStack(stack) == 1)
	{
		MyNum* result = (MyNum*)Front_LinkStack(stack);
		printf("运算结果是：%d\n", result->val);
		Pop_LinkStack(stack);
		free(result);
	}

	//释放栈
	FreeSpace_LinkStack(stack);

	system("pause");
	return 0;
}
