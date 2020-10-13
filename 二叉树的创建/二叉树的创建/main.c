#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

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

BinaryNode* CreatBinaryTree()
{
	fflush(stdin);
	char ch;
	scanf("%c", &ch);

	BinaryNode* node;

	if (ch == '#')
	{
		node = NULL;
	}
	else
	{
		node = (BinaryNode*)malloc(sizeof(BinaryNode));
		node->ch = ch;
		node->lchild = CreatBinaryTree();
		node->rchild = CreatBinaryTree();
	}

	return node;
}

int main()
{
	BinaryNode* root = CreatBinaryTree();
	Recursion(root);

	system("pause");
	return 0;
}