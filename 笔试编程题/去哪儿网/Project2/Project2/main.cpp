#include <iostream>
#include <vector>
#include <string>
using namespace std;
//给出一个二叉树的中序遍历和后序遍历结果，求前序遍历结果输出
struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* recon(string s1, int start1, int end1, string s2, int start2, int end2)
{
	if (s1.empty() || s2.empty())
		return nullptr;
	if (start1 > end1 || start2 > end2)
		return nullptr;
	char rootch = s2[end2];
	TreeNode* root = new TreeNode();
	root->val = rootch;
	root->left = nullptr;
	root->right = nullptr;
	if (start1 == end1)
	{
		if (start2 == end2&&s1[start1] == s2[start2])
			return root;
	}	
	int p = start1;
	while (p <= end1&&s1[p] != rootch)
		p++;
	if (p == end1&&s1[p] != rootch)
		return nullptr;
	int leftlen = p - start1;
	if (leftlen > 0)
		root->left = recon(s1, start1, p - 1, s2, start2, start2 + leftlen - 1);
	if (leftlen < end2 - start2)
		root->right = recon(s1, p + 1, end1, s2, start2 + leftlen, end2 - 1);
	return root;
}
void bianli(TreeNode* root, vector<char>& v)
{
	if (root == nullptr)
		return;
	v.push_back(root->val);
	bianli(root->left, v);
	bianli(root->right, v);	
}
vector<char> func(string s1, string s2)
{
	vector<char> v;
	if (s1.empty() || s2.empty())
		return v;
	TreeNode* root =  recon(s1, 0, s1.size() - 1, s2, 0, s2.size() - 1);
	bianli(root, v);
	return v;
}
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		vector<char> vout;
		vout = func(str1, str2);
		for (int i = 0; i < vout.size(); i++)
			cout << vout[i];
		cout << endl;
	}
	system("pause");
	return 0;
}