#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
	string str = "";
	int num;
	while (cin >> num)
	{
		vector<int> v;
		for (int i = 0; i < num; i++)
		{
			char ch;
			cin >> ch;
			str += ch;
		}
		for (int j = 0; j < 13; j++)
		{
			int n;
			cin >> n;
			v.push_back(n);
		}
		map<char, int> mymap;
		string strN = "ABCDEFGHIJKLM";
		for (int k = 0; k < v.size(); k++)
		{
			mymap.insert(make_pair(strN[k], v[k]));
		}
		for (int m = 0; m < str.length(); m++)
		{
			map<char, int>::iterator ret = mymap.find(str[m]);
			if (ret != mymap.end())
				mymap.erase(ret++);
		}
		int max = 0;
		char re;
		for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		{
			if (it->second > max)
			{
				max = it->second;
				re = it->first;
			}
				
		}
		cout << re << endl;
	}
	system("pause");
	return 0;
}