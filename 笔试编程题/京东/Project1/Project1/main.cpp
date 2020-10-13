#include <iostream>
#include <vector>
//合唱队的N名学生站成一排且从左到右编号为1到N，
//其中编号为i的学生身高为Hi。
//现在将这些学生分成若干组（同一组的学生编号连续），
//并让每组学生从左到右按身高从低到高进行排列，
//使得最后所有学生同样满足从左到右身高从低到高（中间位置可以等高），那么最多能将这些学生分成多少组？
//4
//2 1 3 2
//2
vector<int> func(vector<long long> v)
{
	int index = 1;
	int max = v[0];
	vector<int> maxv;
	maxv.push_back(0);
	if (v.empty())
		return maxv;
	while (index < v.size())
	{
		if (v[index] >= max)
		{
			max = v[index];
			maxv.push_back(index);
		}
		index++;
	}
	return maxv;
}
int main()
{
	int num;
	long long in;
	while (cin >> num)
	{
		vector<long long> v;
		for (int i = 0; i < num; i++)
		{
			cin >> in;
			v.push_back(in);
		}
		vector<int> out = func(v);
		cout << out.size() << endl;
	}
	system("pause");
	return 0;
}