//������һ����Ƭ��С�׺ʹ�����������Ҫ����Ƭ��ÿ��ֻ�ܴ���Ƭ�������ó�һƬ��Ƭ�Ե���ÿ����ȡ��Ƭ�Ե����Ի�ÿ���ֵa[i], 
//i������Ƭ�ں����е�λ�á�С�����ã�Ȼ������ٴ�ʣ����Ƭ�������ٴ�ȡ��һƬ��Ƭ�Ե���������������������ֱ����Ƭ�пյ���
//���տ���ֵ�����˻�ʤ������һ����ʾ��Ƭ����ֵ�����飬Ԥ��С���Ƿ���ΪӮ�ң����˿���ֵ��ͬʱС��Ӯ��������С�׺ʹ��׶��㹻������

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