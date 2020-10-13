#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool IstheSame(vector<string>& v, int len, int startx, int starty, int beginx, int beginy)
{
	if (startx + len - 1 > v.size() || beginx + len - 1 > v.size() 
		|| starty + len - 1 > v[0].size() || beginy + len - 1 > v[0].size())
		return false;
	for (int i = 0; i < len; i++)
	{
		if (v[startx + i][starty + len - 1] != v[beginx + i][beginy + len - 1])
			return false;
	}
	for (int j = 0; j < len; j++)
	{		
		if (v[startx + len - 1][starty + j] != v[beginx + len - 1][beginy + j])
			return false;
	}
	return true;
}
int main()
{
	int m, n;
	while (cin >> n >> m)
	{
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}
		int maxlen = 0;
		int x = 0, y = 0;
		int indexx = 0, indexy = 0;
		for (int i = 0; i < n; i++)
		{			
			for (int j = 0; j < m; j++)
			{
				for (int p = 0; p < n; p++)
				{
					for (int q = 0; q < m; q++)
					{
						if (p == i&&q == j)
							continue;
						int len = 1;
						if (IstheSame(v, len, i, j, p, q))
						{
							while (IstheSame(v, len, i, j, p, q))
								len++;
							len--;
							if (maxlen < len)
							{
								maxlen = len;
								x = i + 1; 
								y = j + 1;
								indexx = p + 1; 
								indexy = q + 1;
							}
						}
					}
				}				
			}
			cout << maxlen << endl;
			cout << x << " " << y << endl;
			cout << indexx << " " << indexy << endl;		
		}	
	}
	//system("pause");
	return 0;
}
/*
5 10
mklghiegbt
jtegkltjzf
qhmkljkmhq
fzjtebgetj
moqhmlglkm
*/

void deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	auto p = pHead, pn = p->next, pnn = p;
	while (p != nullptr&&pn != nullptr&&pn->next!=nullptr)
	{
		pnn = pn->next;
		if ((p->val) == (pn->val))
		{
			p = pnn;
			ListNode* tmp = pnn;
			while (tmp->val == pnn->val&&tmp!=nullptr)
				tmp = tmp->next;
			p->next = tmp;
		}
		p = p->next;
		pn = p->next;
	}
}