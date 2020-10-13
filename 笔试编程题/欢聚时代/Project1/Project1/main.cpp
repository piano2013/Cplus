//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//struct mycompare
//{
//	bool operator()(int key1, int key2)
//	{
//		return key1 > key2;
//	}
//};
//int sum_vec(vector<int>& v)
//{
//	int sum = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		sum += v[i];
//	}
//	return sum;
//}
//int main()
//{
//	int M, N;
//	while (cin >> M >> N)
//	{
//		int Mi, Ni;
//		vector<int> v1;
//		vector<int> v2;
//		multimap<int, int, mycompare> m;
//		for (int i = 0; i < N; i++)
//		{
//			cin >> Mi;
//			v1.push_back(Mi);
//		}
//		for (int i = 0; i < N; i++)
//		{
//			cin >> Ni;
//			v2.push_back(Ni);
//		}
//		for (int i = 0; i < N; i++)
//		{
//			m.insert(make_pair(v2[i], v1[i]));
//		}
//		multimap<int, int, mycompare>::iterator it = m.begin();
//		vector<int> weight;
//		vector<int> like;
//		for (multimap<int, int, mycompare>::iterator it = m.begin(); it != m.end(); it++)
//		{
//			if ((sum_vec(weight)+it->second) > M)
//				continue;
//			like.push_back(it->first);
//			weight.push_back(it->second);
//		}
//		cout << sum_vec(like) << endl;
//	}
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int M;
	int N;
	cin >> M >> N;
	vector<int> Mi(N);
	vector<int> Vi(N);
	for (int i = 0; i < N; i++) {
		cin >> Mi[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> Vi[i];
	}
	if (N == 0) {
		return 0;
	}
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j<Mi[i - 1])//包装不进
			{
				dp[i][j] = dp[i - 1][j];
			}
			else//能装
			{
				if (dp[i - 1][j]>dp[i - 1][j - Mi[i - 1]] + Vi[i - 1])//不装价值大
				{
					dp[i][j] = dp[i - 1][j];
				}
				else//前i-1个物品的最优解与第i个物品的价值之和更大
				{
					dp[i][j] = dp[i - 1][j - Mi[i - 1]] + Vi[i - 1];
				}
			}
		}
	}
	cout << dp[N][M];
	system("pause");
	return 0;
}