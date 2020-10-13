#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int time;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> time;
			v.push_back(time);
		}
		int max = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (max < v[i])
			{
				max = v[i];
			}
		}
		int sum = 0;
		int index = 0;
		vector<vector<int>> vv;
		while (index < v.size())
		{
			vector<int> in;
			for (int i = index; i < v.size(); i++)
			{
				sum += v[i];
				in.push_back(v[i]);
				if (sum > max)
				{
					index = i+1;
					max = sum;
					break;
				}
			}
		}		
	}
}