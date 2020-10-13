#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string str;
	vector<string> v;
	while (true)
	{
		cin >> str;
		v.push_back(str);
		if (cin.get() == '\n')
			break;
	}
	multimap<string, string> m;
	for (int i = 0; i < v.size(); i++)
	{
		int index = 0;
		string st1;
		string st2;
		while (v[i][index] != '-')
		{
			st1 += v[i][index];
			index++;
		}		
		index++;
		while (index<v[i].size())
		{
			st2 += v[i][index];
			index++;
		}			
		if (m.empty())
			m.insert(make_pair(st2, st1));
		if (m.find(st2) != m.end())
		{
			multimap<string, string>::iterator ret = m.find(st2);
			if (ret->second != st1)
				m.insert(make_pair(st2, st1));
		}
		else
			m.insert(make_pair(st2, st1));
	}
	map<string, int> mm;
	for (multimap<string, string>::iterator it = m.begin(); it != m.end(); it++)
	{		
		mm[it->first]++;
	}
	for (int i = 0; i < 3; i++)
	{
		int max = 0;
		string ss;
		for (multimap<string, int>::iterator it = mm.begin(); it != mm.end(); it++)
		{
			if (max < it->second)
			{
				max = it->second;
				ss = it->first;
			}
		}
		cout << ss << " " << max << endl;
		mm.erase(ss);
	}
	//system("pause");
	return 0;
}
