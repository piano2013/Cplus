#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool IsChar(char c)
{
	if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z')
		return true;
	return false;
}
bool IsLeft(char c)
{
	if (c == '(')
		return true;
	return false;
}
bool IsRight(char c)
{
	if (c == ')')
		return true;
	return false;
}
bool IsDel(char c)
{
	if (c == '<')
		return true;
	return false;
}
int main()
{
	string str;
	while (cin >> str)
	{
		stack<char> s;
		string ss;
		int leftcnt = 0;
		if (str.size() <= 0)
			return 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (IsChar(str[i]) && leftcnt == 0)
				s.push(str[i]);
			else if (IsLeft(str[i]))
				leftcnt++;
			else if (IsRight(str[i]))
				leftcnt--;
			else if (IsDel(str[i]) && leftcnt == 0)
			{
				if (!s.empty())
					s.pop();
			}
		}
		while (!s.empty())
		{
			ss += s.top();
			s.pop();
		}
		for (int i = ss.size() - 1; i >= 0; i--)
			cout << ss[i];
		cout << endl;
	}
	system("pause");
	return 0;
}