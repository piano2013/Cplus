#include <iostream>
#include <vector>
#include <algorithm>
//�����һ������������n��m���ֱ��ʾ��n��������n��Ů������m�����ѹ�ϵ��
//(1 <= n <= 500, 1 <= m <= 100000)
//������m�У�ÿ��������������x��y����ʾ��x�������͵�y��Ů�������ѡ������ı�ž�Ϊ[1, n]��Ů���ı��Ϊ[n + 1, 2n]��

//�����һ�а���һ������a����ʾ������Ҫ������ҵ�������
//����ڶ�����a����������a����Ҫ������ҵ��˵ı�ţ�Ҫ���������٣����ֵ�����С��

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