#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
void map_insert(map<string, unsigned int>& m2, map<string, unsigned int>& m, string str, unsigned int n, int size, queue<string>& q)
{
	
	if (m.size() < size)
		m.insert(make_pair(str, n));
	else
	{
		if (m.find(str)!=m.end())
			m[str] = n;
		else
		{
			map<string, unsigned int>::iterator ret = m.find(q.front());
			m2.insert(make_pair(ret->first, ret->second));
			m.erase(ret++);
			q.pop();
		}	
	}
}
int main()
{
	int size;
	cin >> size;
	map<string, unsigned int> m1;
	map<string, unsigned int> m2;
	queue<string> q;
	while(true)
	{
		string str;
		unsigned int n;
		cin >> str >> n;
		q.push(str);
		map_insert(m2, m1, str, n, size, q);
		for (map<string, unsigned int>::iterator it = m2.begin(); it != m2.end(); it++)
		{
			cout << it->first << " " << it->second << endl;
		}
	}		
	//system("pause");
	return 0;
}