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

int CountDeepthNum(BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int Depth = 0;
	//
	int Depth_left = CountDeepthNum(root->lchild);
	int Depth_right = CountDeepthNum(root->rchild);

	Depth = (Depth_left > Depth_right) ? Depth_left + 1 : Depth_right + 1;

	return Depth;
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

	int Max = CountDeepthNum(&node1);
	printf("%d\n", Max);

}

int main()
{
	CreatBinaryTree();


	system("pause");
	return 0;
}