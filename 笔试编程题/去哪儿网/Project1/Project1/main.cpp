#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	vector<vector<int>> dp(n, vector < int >(n));
	vector<vector<int>> dp2(n, vector < int >(n));
	vector<vector<int>> dp3(n, vector < int >(n,0));
	for (int i = 0; i < n; i++)
	{
		dp[i][0] = v[i][0];
		dp2[0][i] = v[0][i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = max(v[i][j], v[i][j] + dp[i][j - 1]);
	for (int j = 0; j < n; j++)
		for (int i = 1; i < n; i++)
			dp2[i][j] = max(v[i][j], v[i][j] + dp2[i - 1][j]);
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			dp3[i][j] = max(dp[i][j], dp[i - 1][j] + dp[i][j]);
	int m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m = max(dp[i][j], m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m = max(dp2[i][j], m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m = max(dp3[i][j], m);
	cout << m << endl;
	system("pause");
	return 0;
}