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

//遍历二叉树
void Recursion(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

//拷贝二叉树
BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//拷贝左子树
	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	//拷贝右子树
	BinaryNode* rchild = CopyBinaryTree(root->rchild);

	//创建结点
	BinaryNode* newNode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newNode->ch = root->ch;
	newNode->lchild = lchild;
	newNode->rchild = rchild;

	return newNode;
}

//释放二叉树内存
void FreeSpaceBinaryTree(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//释放左子树
	FreeSpaceBinaryTree(root->lchild);
	//释放右子树
	FreeSpaceBinaryTree(root->rchild);

	//释放当前结点
	free(root);
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

	BinaryNode* root = CopyBinaryTree(&node1);

	Recursion(root);

	FreeSpaceBinaryTree(root);
}

int main()
{
	CreatBinaryTree();


	system("pause");
	return 0;
}