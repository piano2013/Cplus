#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���������
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

//�ݹ����
void Recursion1(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	
	//�������
	//�ȷ��ʸ����
	printf("%c", root->ch);
	//�ٱ���������
	Recursion1(root->lchild);
	//�ٱ���������
	Recursion1(root->rchild);	
}

void Recursion2(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//�������
	//�ȱ���������
	Recursion2(root->lchild);
	//�ٷ��ʸ����
	printf("%c", root->ch);
	//�ٱ���������
	Recursion2(root->rchild);
}

void Recursion3(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//�������
	//�ȱ���������
	Recursion3(root->lchild);
	//�ٱ���������
	Recursion3(root->rchild);
	//�ٷ��ʸ����
	printf("%c", root->ch);
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

	//�ݹ����
	printf("������������\n");
	Recursion1(&node1);
	printf("\n");

	printf("������������\n");
	Recursion2(&node1);
	printf("\n");

	printf("������������\n");
	Recursion3(&node1);
	printf("\n");
}

int main()
{
	CreatBinaryTree();

	system("pause");
	return 0;
}