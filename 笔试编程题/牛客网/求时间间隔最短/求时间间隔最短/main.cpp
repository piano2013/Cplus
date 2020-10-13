//第一道是在24h制下，给定时间字符串数组，求间隔最短时间。
//要求不能用自带的排序等功能
//比如〔“12：00”，“12：03”，“15：03”〕
//输出就是3
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void choosesort(vector<int> v)
{
	if (v.empty())
		return;
	for (int i = 0; i < v.size(); i++)
	{
		int min = i;
		for (int j = i; j < v.size(); j++)
		{
			if (v[j] < v[min])
				min = j;
		}
		if (min != i)
		{
			int tmp = v[i];
			v[i] = v[min];
			v[min] = tmp;
		}
	}
}
int func(vector<string> v)
{
	if (v.empty() || v.size() == 1)
		return -1;
	vector<int> time;
	for (int i = 0; i < v.size(); i++)
	{
		string s = v[i];
		int j = 1;
		int hour = 0;
		while (s[j] != ':')
		{
			hour = hour * 10 + (s[j] - '0');
			j++;
		}
		j++;
		int min = 0;
		while (s[j] != '"')
		{
			min = min * 10 + (s[j] - '0');
			j++;
		}
		time.push_back(hour * 60 + min);
	}
	choosesort(time);
	int min = time[1] - time[0];
	for (int i = 1; i < time.size(); i++)
	{
		if (abs(time[i] - time[i - 1]) < min)
			min = abs(time[i] - time[i - 1]);
	}
	return min;
}
int main()
{
	vector<string> v;
	while (true)
	{
		string str;
		cin >> str;
		v.push_back(str);
		if (cin.get() == '\n')
			break;
	}
	int result = func(v);
	cout << result << "min" << endl;
	system("pause");
	return 0;
}