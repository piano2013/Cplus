#include <iostream>
#include <vector>
#include <algorithm>
//给定一个长度为N - 1且只包含0和1的序列A1到AN - 1，如果一个1到N的排列P1到PN满足对于1≤i<N，
//当Ai = 0时Pi<Pi + 1，当Ai = 1时Pi>Pi + 1，则称该排列符合要求，那么有多少个符合要求的排列？
//第一行包含一个整数N，1<N≤1000。
//第二行包含N - 1个空格隔开的整数A1到AN - 1，0≤Ai≤1
//输出符合要求的排列个数对10^9+7取模后的结果。
//4
//1 1 0
//3
//符合要求的排列为{3 2 1 4}、{4 2 1 3}和{4 3 1 2}
using namespace std;
bool func(vector<int>& v1, vector<int>& v2)
{
	for (int i = 0; i < v1.size();i++)
	{
		if (v1[i]==1 && v2[i] > v2[i + 1] || v1[i]==0 && v2[i] < v2[i + 1])
			continue;
		else
			return false;
	}
	return true;
}
int main()
{
	int N;
	while (cin >> N)
	{
		vector<int> v1;
		vector<int> v2;
		int a[1000];
		int cnt = 0;
		for (int i = 1; i < N; i++)
		{
			int num;
			cin >> num;
			v1.push_back(num);
		}
		for (int i = 0; i < N; i++)
			a[i] = i + 1;
		do{
			for (int i = 0; i < N; i++)
				v2.push_back(a[i]);
			if (func(v1, v2))
				cnt++;
			v2.clear();
		} while (next_permutation(a, a + N));
		cout << cnt << endl;
	}
	system("pause");
	return 0;
}