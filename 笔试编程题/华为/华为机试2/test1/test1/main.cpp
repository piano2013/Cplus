#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int num;
	int cnt = 0;
	int index;
	bool flag = false;
	vector<int> v;
	cin >> num;
	while (num)
	{
		v.push_back(num % 2);
		num = num / 2;
	}
	if (v.empty())
	{
		cout << 0 << " " << -1 << endl;
		return 0;
	}
	for (int i = 0; i < v.size() - 2; i++)
	{
		if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
		{
			cnt++;
			if (!flag)
			{
				index = i;
				flag = true;
			}
		}
	}
	if (cnt<1)
	{
		cout << 0 << " " << -1 << endl;
		return 0;
	}
	cout << cnt << " " << index << endl;
	return 0;
}