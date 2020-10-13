#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

#define MY_FALSE 0
#define MY_TRUE 1

//���������
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

typedef struct BITREESTACKNODE
{
	LinkNode node;
	BinaryNode* root;
	int flag;
}BiTreeStackNode;

//����ջ�еĽ��
BiTreeStackNode* CreatBiTreeStackNode(BinaryNode* node, int flag)
{
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;

	return newnode;
}

//�������ķǵݹ����
void NonRecursion(BinaryNode* root)
{
	//����ջ
	LinkStack* stack = Init_LinkStack();
	//�Ѹ������ջ
	Push_LinkStack(stack, (LinkNode*)CreatBiTreeStackNode(root, MY_FALSE));

	while (Size_LinkStack(stack) > 0)
	{
		//�ȵ���ջ��Ԫ��
		BiTreeStackNode* node = (BiTreeStackNode*)Front_LinkStack(stack);
		Pop_LinkStack(stack);

		//�ж��Ƿ�Ϊ��
		if (node->root == NULL)
		{
			continue;
		}

		if (node->flag == MY_TRUE)
		{
			printf("%c", node->root->ch);
		}
		else
		{
			//��ǰ�����ҽ����ջ
			Push_LinkStack(stack, (LinkNode*)CreatBiTreeStackNode(node->root->rchild, MY_FALSE));
			//��ǰ����������ջ
			Push_LinkStack(stack, (LinkNode*)CreatBiTreeStackNode(node->root->lchild, MY_FALSE));
			//��ǰ�����ջ
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
		}
	}

}


void CreatBinaryTree()
{
	//�������
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	//��������ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;

	node2.rchild = &node3;

	node3.lchild = &node4;
	node3.rchild = &node5;

	node6.rchild = &node7;

	node7.lchild = &node8;

	//�������ķǵݹ����
	NonRecursion(&node1);
}
int main()
{
	CreatBinaryTree();

	system("pause");
	return 0;
}