#include <iostream>
#include <vector>
#include <algorithm>
//输入第一行有两个整数n和m，分别表示有n个男生和n个女生，有m个朋友关系。
//(1 <= n <= 500, 1 <= m <= 100000)
//接下来m行，每行有两个整数，x和y，表示第x号男生和第y号女生是朋友。男生的编号均为[1, n]，女生的编号为[n + 1, 2n]。

//输出第一行包含一个整数a，表示最少需要搬出教室的人数。
//输出第二行有a个整数，即a个需要搬出教室的人的编号，要求人数最少，且字典序最小。

//2 2 
//1 3
//1 4

//1
//1
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v1;
		vector<int> v2;
		for (int i = 0; i<m; i++)
		{
			int num1, num2;
			cin >> num1 >> num2;
			v1.push_back(num1);
			v2.push_back(num2);				
		}
		int cnt = 0;
		vector<int> vv;
		for (int i = 0; i < v1.size()-1; i++)
		{
			for (int j = i + 1; j < v1.size(); j++)
			{
				if (v1[i] == v1[j])
				{
					cnt++;
					vv.push_back(v1[i]);
					break;
				}
			}
		}
		for (int i = 0; i < v2.size() - 1; i++)
		{
			for (int j = i + 1; j < v2.size(); j++)
			{
				if (v2[i] == v2[j])
				{
					cnt++;
					vv.push_back(v2[i]);
					break;
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < vv.size(); i++)
		{
			cout << vv[i] << " ";
		}
	}
	system("pause");
	return 0;
}