#include <iostream>
#include <vector>
#include <algorithm>
//����һ������ΪN - 1��ֻ����0��1������A1��AN - 1�����һ��1��N������P1��PN�������1��i<N��
//��Ai = 0ʱPi<Pi + 1����Ai = 1ʱPi>Pi + 1����Ƹ����з���Ҫ����ô�ж��ٸ�����Ҫ������У�
//��һ�а���һ������N��1<N��1000��
//�ڶ��а���N - 1���ո����������A1��AN - 1��0��Ai��1
//�������Ҫ������и�����10^9+7ȡģ��Ľ����
//4
//1 1 0
//3
//����Ҫ�������Ϊ{3 2 1 4}��{4 2 1 3}��{4 3 1 2}
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