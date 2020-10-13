#include <iostream>
#include <string>
using namespace std;
int index;
bool IsNum(char ch)
{
	if (ch >= '0'&&ch <= '9')
		return true;
	return false;
}
bool IsChar(char ch)
{
	if (ch >= 'a'&&ch <= 'z'|| ch >= 'A'&&ch <= 'Z')
		return true;
	return false;
}
bool IsLeft(char ch)
{
	if (ch =='[')
		return true;
	return false;
}
bool IsRight(char ch)
{
	if (ch == ']')
		return true;
	return false;
}
string func(string str, int times)
{
	string s;
	int time = 0;
	while (index < str.length())
	{
		if (IsNum(str[index]))
			time = time * 10 + (str[index] - '0');			
		else if (IsChar(str[index]))
			s += str[index];
		else if (IsLeft(str[index]))
		{
			index++;
			s += func(str, time);
			time = 0;
		}
		else if (IsRight(str[index]))
		{
			string ss = s;
			for (int j = 0; j < times-1; j++)
			{
				s += ss;
			}
			return s;
		}
		index++;
	}
	return s;
}
int main()
{
	string str;
	while (cin >> str)
	{
		string out;
		int cnt = 0;
		index = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '[')
				cnt++;
			else if (str[i] == ']')
				cnt--;
		}
		if (cnt != 0)
		{
			int j = 0;
			while(str[j]!='['&&str[j]!=']')
			{
				out += str[j];
				j++;
			}
		}
		else
			out += func(str, 0);
		cout << out << endl;
	}
	system("pause");
	return 0;
}