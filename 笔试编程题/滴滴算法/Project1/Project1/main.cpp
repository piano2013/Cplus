#include <iostream>
#include <vector>
#include <string>
using namespace std;
//����һ���������Ӽ��˳��������������ʽ(��������)����1+2*3/4���ڱ��������˳�򲻱������£�
//��������Խ������ɴ����²���������������ڵ������������ʽֵ���䣬��ô��Ϳ��Խ�������������
//��������Խ�������β�����ʹ����ʽ�����������ֵ�����С��Ȼ��������������֮����ֵ�����Ϊ��a<b��a���ֵ���С��b��
//��һ�а���һ������n����ʾ��ʽ�ĳ��ȣ�������n�����ֺ�n-1���������(1��n��100000)��
//�ڶ��а���һ������n����0������n - 1�����������ʽ��������������ÿո����������������� + �� - ��*�� / ���������ľ���ֵ������1000��
//6
//3 + 2 + 1 + -4 * -5 + 1
void sort(vector<int>& v, int begin, int end)
{
	if (begin<0 || end>=v.size())
		return;
	for (int i = begin; i < end; i++)
	{
		for (int j = i + 1; j <= end; j++)
		{
			if (v[i]>v[j])
			{
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}
int main()
{
	char str;
	int n;
	int num;
	while (cin >> n)
	{
		vector<int> v1;
		vector<char> v2;
		vector<int> v3;
 		for (int i = 0; i < n - 1; i++)
		{
			cin >> num;
			v1.push_back(num);
			cin >> str;
			v2.push_back(str);
		}
		cin >> num;
		v1.push_back(num);
		for (int i = 0; i < v2.size() - 1; i++)
		{
			char ch = v2[i];
			char ch2 = v2[i + 1];
			if (ch == '+' && ch2 != '+')
			{
				v3.push_back(i);
				continue;
			}
			if (ch == '-' && ch2 != '-')
			{
				v3.push_back(i);
				continue;
			}
			if (ch == '*' && ch2 != '*')
			{
				v3.push_back(i);
				continue;
			}
			if (ch == '/' && ch2 != '/')
			{
				v3.push_back(i);
				continue;
			}
		}
		int index1 = 0;
		while (v2[index1]!='+'&&v2[index1])
		{
			index1++;
		}
		int index2 = 0;
		while (v2[index2] != '-'&&v2[index2])
		{
			index2++;
		}
		int index3 = 0;
		while (v2[index3] != '*'&&v2[index3])
		{
			index3++;
		}		
		int index4 = 0;
		while (v2[index4] != '/'&&v2[index4])
		{
			index4++;
		}
		vector<int>::iterator it;
		for (it = v3.begin(); it != v3.end(); it++)
		{
			if (v2[*it] == '+')
			{
				if (*it - index1 > 1)
				{
					sort(v1, index1, *it);
					index1 = *it + 1;
				}				
			}	
			if (v2[*it] == '-')
			{
				if (*it - index2 > 1)
				{
					sort(v1, index2+1, *it);
					index2 = *it + 1;
				}
			}
			if (v2[*it] == '*')
			{
				sort(v1, index3, *it + 1);
				index3 = *it + 1;		
			}
			if (v2[*it] == '/')
			{
				if (*it - index4 > 1)
				{
					sort(v1, index4+1, *it);
					index4 = *it + 1;
				}
			}
		}
		int index = (index1 > index2 ? index1 : index2);
		if ((v2.size()-1-index) > 1)
			sort(v1, index, v1.size()-1);
		int i = 0;
		while (i<v2.size())
		{
			cout << v1[i] << " ";
			cout << v2[i] << " ";
			i++;
		}
		cout << v1[i] << endl;
	}
	system("pause");
	return 0;
}