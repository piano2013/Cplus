#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		map<char, int> m;
		map<char, bool> mj;
		int num = 0;
		//char* ch = const_cast<char*>(str.c_str());
		for (int i = 0; i < str.length(); i++)
		{
			m[str[i]]++;		
		}
		int size = m.size();
		for (int i = 0; i < str.length(); i++)
		{
			map<char, int>::iterator ret = m.find(str[i]);
			if (mj[str[i]] != true)
			{
				num++;
				mj[str[i]] = true;				
				if (num == size)
					cout << ret->first << ":" << ret->second << endl;
				else
					cout << ret->first << ":" << ret->second << ",";					
			}
		}
	}
	system("pause");
	return 0;
}