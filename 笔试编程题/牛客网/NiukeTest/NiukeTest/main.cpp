#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归遍历
void Recursion1(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	//先序遍历
	//先访问根结点
	printf("%d", root->val);
	//再遍历左子树
	Recursion1(root->left);
	//再遍历右子树
	Recursion1(root->right);
}

TreeNode* ConstructBinaryTree(vector<int>::iterator startpre, vector<int>::iterator endpre, vector<int>::iterator startvin, vector<int>::iterator endvin)
{
	if (startpre>endpre || startvin>endvin){
		return nullptr;
	}
	int rootvalue = *startpre;
	TreeNode* root = new TreeNode(rootvalue);
	if (startpre == endpre){
		if (startvin == endvin && *startpre == *startvin){
			return root;
		}
		else{
			return nullptr;
		}
	}
	vector<int>::iterator indexvin = startvin;
	while (*indexvin != rootvalue && indexvin <= endvin){
		indexvin++;
	}
	if (*indexvin != rootvalue && indexvin == endvin){
		return nullptr;
	}
	int leftlength = indexvin - startvin;
	if (leftlength > 0){
		root->left = ConstructBinaryTree(startpre + 1, startpre + leftlength, startvin, indexvin - 1);
	}
	if (leftlength < endpre - startpre){
		root->right = ConstructBinaryTree(startpre + leftlength + 1, endpre, indexvin + 1, endvin);
	}
	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	vector<int>::iterator startpre = pre.begin();
	vector<int>::iterator endpre = startpre + pre.size() - 1;
	vector<int>::iterator startvin = vin.begin();
	vector<int>::iterator endvin = startvin + vin.size() - 1;
	if (!pre.empty() || !vin.empty())
	{
		return ConstructBinaryTree(startpre, endpre, startvin, endvin);
	}
	return nullptr;
}



int main()
{
	vector<int> vpre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };

	TreeNode* root = reConstructBinaryTree(vpre, vin);
	Recursion1(root);

	system("pause");
	return 0;
}