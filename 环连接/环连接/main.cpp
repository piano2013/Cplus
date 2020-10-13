#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int cnt = 0;
bool compare(int a1, int a2, int a3)
{
	int result = a1 + a2 - a3;
	if (result > 0)
		return true;
	return false;
}
void perm(int k, int n, int a[])
{
	if (k >= n)
	{
		if (!compare(a[1], a[n-1], a[n]))
			return;
		else
		{
			cnt++;
		}
	}
	else
	{
		for (int i = k; i <= n; i++)
		{
			swap(a[k], a[i]); // 第一层的交换是自己交换自己本身
			if (!compare(a[k - 1], a[k + 1], a[k]))
			{
				perm(k + 1, n, a);//交换后递归下一层
			}
			swap(a[k], a[i]);
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[] = { 1,2,4 };
	perm(1, n, a);
	if (cnt > 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}