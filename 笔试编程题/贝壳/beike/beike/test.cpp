#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	double n;
	int m;
	while (cin >> n >> m)
	{
		double sum = 0.0;
		for (; m>0; m--, n = sqrt(n))
			sum += n;
		printf("%.2lf\n", sum);
	}
	system("pause");
	return 0;
}
//#include<iostream>
//#include<cmath>
//#include<string>
//#include<vector>
//#include<iomanip>
//using namespace std;
//
//double n_sum(int n, int m)
//{
//	double sum = n, front = n;
//
//	for (int i = 2; i <= m; i++)
//	{
//		front = pow(front, 0.5);
//		sum += front;
//	}
//	return sum;
//}
//
//
//int main()
//{
//	int number;
//	vector<int> seq;
//	while (cin >> number)
//	{
//		seq.push_back(number);
//	}
//	//cout << "111" << endl;
//	for (size_t i = 0; i < seq.size();)
//	{
//		int n = seq[i++];
//		int m = seq[i++];
//		if (n >= 10000 || m >= 1000)
//		{
//			break;
//		}
//		double ret;
//		ret = n_sum(n, m);
//		cout << fixed << setprecision(2) << ret << endl;
//	}
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//int main()
//{
//	int m, n, count = 0;
//	cin >> m >> n;
//	if (n<m || n<100 || m<100)
//		return 0;
//	int num[3] = { 0 };
//	vector<int> v;
//	for (int i = m; i <= n; i++)
//	{
//		int now = i;
//		for (int j = 0; j<3; j++)
//		{
//			num[j] = now % 10;
//			now = now / 10;
//		}
//		if (num[0] * num[0] * num[0] + num[1] * num[1] * num[1] + num[2] * num[2] * num[2] == i)
//		{
//			count++;
//			v.push_back(i);
//		}
//	}
//	if (count == 0)
//		cout << "no" << endl;
//	else{
//		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//		{
//			cout << *it << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}