//现在有一盒薯片，小米和大米两个人想要吃薯片。每次只能从薯片盒两端拿出一片薯片吃掉，每次拿取薯片吃掉可以获得快乐值a[i], 
//i代表薯片在盒子中的位置。小米先拿，然后大米再从剩余薯片的两端再次取出一片薯片吃掉，····，依次类推直至薯片盒空掉。
//最终快乐值最大的人获胜。给定一个表示薯片快乐值的数组，预测小米是否会成为赢家（两人快乐值相同时小米赢），假设小米和大米都足够聪明。

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
bool func(vector<int>& nums)
{
	int size = nums.size();
	vector<vector<int>> dp(size, vector<int>(size));
	vector<int> sum(size);
	for (int i = 0; i < size; i++)
		dp[i][i] = nums[i];
	sum[0] = nums[0];
	for (int i = 0; i < size - 1; i++)
		sum[i + 1] = sum[i] + nums[i + 1];
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; i + j < size; j++)
		{
			dp[j][i + j] = max(sum[i + j] - sum[j] + nums[j] - dp[j + 1][i + j], sum[i + j] - sum[j] + nums[j] - dp[j][i + j - 1]);
		}
	}
	return 2 * dp[0][size - 1] >= sum[size - 1];
}
int main()
{
	vector<int> v;
	bool flag = false;
	int temp;
	while (cin >> temp)
	{
		v.push_back(temp);
	}
	flag = func(v);
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}