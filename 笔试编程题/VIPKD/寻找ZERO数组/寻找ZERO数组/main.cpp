#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int num;
	vector<int> nums;
	while (true)
	{
		cin >> num;
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	int cnt = 0;
	map<int, int> hash;
	for (int i = 0; i < nums.size(); ++i)
	{
		hash.insert(make_pair(nums[i], 1));
	}
	map<int, int>::iterator it = hash.begin();
	for (int i = 0; i < nums.size(); ++i)
	{
		int another = 0 - nums[i];
		if (hash.count(another))
		{
			cnt++;
			break;
		}

	}
	cout << cnt << endl;
	return 0;
}