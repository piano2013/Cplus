#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

#define MY_FALSE 0
#define MY_TRUE 1

//二叉树结点
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

//创建栈中的结点
BiTreeStackNode* CreatBiTreeStackNode(BinaryNode* node, int flag)
{
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;

	return newnode;
}

//二叉树的非递归遍历
void NonRecursion(BinaryNode* root)
{
	//创建栈
	LinkStack* stack = Init_LinkStack();
	//把根结点入栈
	Push_LinkStack(stack, (LinkNode*)CreatBiTreeStackNode(root, MY_FALSE));

	while (Size_LinkStack(stack) > 0)
	{
		//先弹出栈顶元素
		BiTreeStackNode* node = (BiTreeStackNode*)Front_LinkStack(stack);
		Pop_LinkStack(stack);

		//判断是否为空
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
			//当前结点的右结点入栈
			Push_LinkStack(stack, (LinkNode*)CreatBiTreeStackNode(node->root->rchild, MY_FALSE));
			//当前结点的左结点入栈
			Push_LinkStack(stack, (LinkNode*)CreatBiTreeStackNode(node->root->lchild, MY_FALSE));
			//当前结点入栈
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
		}
	}

}


void CreatBinaryTree()
{
	//创建结点
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;

	node2.rchild = &node3;

	node3.lchild = &node4;
	node3.rchild = &node5;

	node6.rchild = &node7;

	node7.lchild = &node8;

	//二叉树的非递归遍历
	NonRecursion(&node1);
}
int main()
{
	CreatBinaryTree();

	system("pause");
	return 0;
}