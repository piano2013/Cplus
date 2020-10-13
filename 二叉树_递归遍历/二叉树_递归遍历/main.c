#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二叉树结点
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

//递归遍历
void Recursion1(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	
	//先序遍历
	//先访问根结点
	printf("%c", root->ch);
	//再遍历左子树
	Recursion1(root->lchild);
	//再遍历右子树
	Recursion1(root->rchild);	
}

void Recursion2(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//中序遍历
	//先遍历左子树
	Recursion2(root->lchild);
	//再访问根结点
	printf("%c", root->ch);
	//再遍历右子树
	Recursion2(root->rchild);
}

void Recursion3(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//后序遍历
	//先遍历左子树
	Recursion3(root->lchild);
	//再遍历左子树
	Recursion3(root->rchild);
	//再访问根结点
	printf("%c", root->ch);
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

	//递归遍历
	printf("先序遍历结果：\n");
	Recursion1(&node1);
	printf("\n");

	printf("中序遍历结果：\n");
	Recursion2(&node1);
	printf("\n");

	printf("后序遍历结果：\n");
	Recursion3(&node1);
	printf("\n");
}

int main()
{
	CreatBinaryTree();

	system("pause");
	return 0;
}