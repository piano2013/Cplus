#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
// ����n����������Ҫ���ҳ��������������в�ľ���ֵ��С��һ�����֣�����в�ľ���ֵ��ͬ�ģ��������ǰ���һ������
// 2< n <= 100������������10 ^ 16��Χ��
// 9
// 1 3 4 7 2 6 5 12 32
// 3 4
int main()
{
	int n;
	int num;
	vector<int> v;
	cin >> n;
	if (n <= 0)
		return 0;
	while (n)
	{
		cin >> num;
		v.push_back(num);
		if (cin.get() == '\n')
			break;
		n--;
	}
	//vector<long long> v = { 1, 3, 4, 7, 2, 6, 5, 12, 32 };
	int p = 0, q = 0;
	long long min = abs(v[1] - v[0]);
	while (p<v.size()-1)
	{
		long long result = abs(v[p] - v[p + 1]);
		if (result < min)
		{
			min = result;
			q = p;
		}
		p++;
	}
	cout << v[q] << " " << v[q+1] << endl;
	system("pause");
	return 0;
}