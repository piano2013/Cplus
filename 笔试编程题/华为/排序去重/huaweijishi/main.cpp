#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> func(vector<int> in)
{
	vector<int> out;
	if (in.empty())
		return out;
	sort(in.begin(), in.end());
	int i = 0;
	while (i<in.size())
	{
		if (out.empty())
		{
			out.push_back(in[i]);
			i++;
		}
		else if (in[i] != out.back())
		{
			out.push_back(in[i]);
			i++;
		}
		else
			i++;
	}
	return out;
}
int main()
{
	int N, num;
	vector<int> v;
	while (cin >> N)
	{
		while (N--&&cin >> num)
		{
			v.push_back(num);
		}
		vector<int> output = func(v);
		for (int i = 0; i<output.size(); i++)
		{
			cout << output[i] << endl;
		}
		v.clear();
	}
	system("pause");
	return 0;
}