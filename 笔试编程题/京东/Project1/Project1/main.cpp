#include <iostream>
#include <vector>
//�ϳ��ӵ�N��ѧ��վ��һ���Ҵ����ұ��Ϊ1��N��
//���б��Ϊi��ѧ�����ΪHi��
//���ڽ���Щѧ���ֳ������飨ͬһ���ѧ�������������
//����ÿ��ѧ�������Ұ���ߴӵ͵��߽������У�
//ʹ���������ѧ��ͬ�������������ߴӵ͵��ߣ��м�λ�ÿ��Եȸߣ�����ô����ܽ���Щѧ���ֳɶ����飿
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