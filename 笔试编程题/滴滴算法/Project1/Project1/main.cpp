#include <iostream>
#include <vector>
#include <string>
using namespace std;
//给出一个仅包含加减乘除四种运算符的算式(不含括号)，如1+2*3/4，在保持运算符顺序不变的情况下，
//现在你可以进行若干次如下操作：如果交换相邻的两个数，表达式值不变，那么你就可以交换这两个数。
//现在你可以进行任意次操作，使得算式的数字序列字典序最小，然后输出结果，数字之间的字典序定义为若a<b则a的字典序小于b。
//第一行包含一个整数n，表示算式的长度，即包含n个数字和n-1个运算符。(1≤n≤100000)。
//第二行包含一个含有n个非0整数和n - 1个运算符的算式，整数与运算符用空格隔开，运算符包括“ + ， - ，*， / ”，整数的绝对值不超过1000。
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