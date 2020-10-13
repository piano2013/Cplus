#include <iostream>
#include <list>
#include <string>
using namespace std;
bool IsChar(char ch)
{
	return ch >= 'A'&&ch <= 'Z' || ch >= 'a'&&ch <= 'z';
}
bool IsNum(char ch)
{
	return ch >= '0'&&ch <= '9';
}
bool IsSpec(char ch)
{
	return ch >= '!'&&ch <= '*' || ch == '^';
}

void str_operate(string str)
{
	// statement 0: begin; 1: number; 2: string begin; 3: input "; 4: string; 5: error
	int len = str.length();
	int status = 0;
	int str_index = 0;
	list<string> strlist;
	string tmp;
	for (int i = 0; i < len; i++)
	{
		switch (status)
		{
		case 0:
			if (str[i] == ',')
			{
				status = 0;
				strlist.push_back(string("--"));
				tmp = string();
			}
			else if(IsNum(str[i])){
				status = 1;
				tmp.push_back(str[i]);
			}
			else if (IsChar(str[i])){
				status = 4;
				tmp.push_back(str[i]);
			}
			else if (str[i] == '\"'){
				status = 2;
			}
			else{
				cout << "ERROR" << endl;
				return;
			}
			break;
		case 1:
			if (IsNum(str[i])){
				status = 1;
				tmp.push_back(str[i]);
			}
			else if (str[i] == ','){
				status = 0;
				strlist.push_back(tmp);
				tmp = string();
			}
			else{
				cout << "ERROE" << endl;
				return;
			}
			break;
		case 2:
			if (str[i] == '"'){
				status = 3;
			}
			else if (IsNum(str[i])||IsChar(str[i])||str[i]==','||str[i]=='^'){
				status = 2;
				tmp.push_back(str[i]);
			}
			else{
				cout << "ERROR" << endl;
				return;
			}
			break;
		case 3:
			if (str[i] == '"'){
				status = 2;
				tmp.push_back(str[i]);
			}
			else if (str[i] == ','){
				status = 0;
				strlist.push_back(tmp);
				tmp = string();
			}
			else{
				cout << "ERROR" << endl;
				return;
			}
			break;
		case 4:
			if (str[i] == ','){
				status = 0;
				strlist.push_back(tmp);
				tmp = string();
			}
			else if (IsChar(str[i])){
				tmp.push_back(str[i]);
			}
			else{
				cout << "ERROR" << endl;
				return;
			}
			break;
		default:
			break;
		}
	}
	strlist.push_back(tmp);
	cout << strlist.size() << endl;
	for (list<string>::iterator it = strlist.begin(); it != strlist.end();it++)
	{
		cout << *it << endl;
	}
}
int main()
{
	string str;
	getline(cin, str);
	str_operate(str);
	/*list<char> l;
	for (int i = 0; i < str.length(); i++)
	{
		l.push_back(str[i]);
	}
	int cnt = 1;
	list<char>::iterator it = l.begin();
	while (l.size()>1)
	{		
		if (it == l.end())
			it = l.begin();
		if (cnt == 3)
		{
			l.erase(it++);
			cnt = 1;
		}			
		else
		{
			++it;
			cnt++;
		}			
	}
	it--;
	cout << *it << endl;*/
	system("pause");
	return 0;
}