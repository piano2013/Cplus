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
	//��׺���ʽ
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
			//�ȴ�ջ�е����Ҳ�����
			MyNum* right = (MyNum*)Front_LinkStack(stack);
			int rightNum = right->val;
			//printf("%d\n", rightNum);
			Pop_LinkStack(stack);
			free(right);
			//�ٵ����������
			MyNum* left = (MyNum*)Front_LinkStack(stack);
			int leftNum = left->val;
			//printf("%d\n", leftNum);
			Pop_LinkStack(stack);
			free(left);
			//����
			MyNum* value = (MyNum*)malloc(sizeof(MyNum));
			value->val = Calculate(leftNum, rightNum, *p);
			//�����ջ
			Push_LinkStack(stack, (LinkNode*)value);
		}
		p++;
	}

	if (Size_LinkStack(stack) == 1)
	{
		MyNum* result = (MyNum*)Front_LinkStack(stack);
		printf("�������ǣ�%d\n", result->val);
		Pop_LinkStack(stack);
		free(result);
	}

	//�ͷ�ջ
	FreeSpace_LinkStack(stack);

	system("pause");
	return 0;
}
