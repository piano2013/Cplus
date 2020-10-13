//еп╤о╩ьнда╢╠М
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	vector<int> v;
	//bool flag = false;
	while (true)
	{
		int num;
		cin >> num;
		v.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	int len = v.size();
	int mid = len / 2;
	stack<int> s;
	int i;
	for (i = 0; i < mid; i++)
	{
		s.push(v[i]);
	}
	for (; i < len; i++)
	{
		if (v[i] == s.top())
			s.pop();
	}
	/*while (!s.empty())
	{
		int temp = v.back();
		if (s.empty() && !flag)
		{
			flag = true;
			s.push(temp);
		}		
		else if (temp == s.top())
			s.pop();
		else if (temp != s.top())
			s.push(temp);
		v.pop_back();
	}*/
	if (s.empty())
		cout << "True" << endl;		
	else
		cout << "False" << endl;
	system("pause");
	return 0;
}