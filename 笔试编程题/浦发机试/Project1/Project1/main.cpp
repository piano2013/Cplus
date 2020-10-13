#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//abcdbcddE
int main()
{
	string str;
	while (cin >> str)
	{
		unordered_map<char, int> m;
		for (int i = 0; i < str.size(); i++)
		{

			m[str[i]]++;
		}
		unordered_map<char, int>::iterator it = m.begin();
		for (; it != --m.end(); it++)
		{
			cout << it->first << ":" << it->second << ",";
		}
		cout << it->first << ":" << it->second << endl;
	}
	system("pause");
	return 0;
}