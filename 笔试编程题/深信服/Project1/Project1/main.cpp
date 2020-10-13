#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* rebuild(queue<char>& q)
{
	TreeNode* root = new TreeNode();
	if (q.empty())
		return root;
	root->val = q.front();
	q.pop();
	if (root->val != '#'&&!q.empty())
	{
		root->left = rebuild(q);
		root->right = rebuild(q);
	}
	return root;
}
void bianli(TreeNode* root)
{
	if (root == nullptr)
		return;
	printf("%c\n", root->val);
	bianli(root->left);
	bianli(root->right);
}
int main()
{
	int N;
	while (cin >> N)
	{
		queue<char> q;
		for (int i = 0; i < N; i++)
		{
			char ch;
			cin >> ch;
			q.push(ch);
		}
		TreeNode* root = rebuild(q);
		bianli(root);
	}
	//system("pause");
	return 0;
}