#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//找出数组中重复的数字

void Print(int v)
{
	cout << v << " ";
	cout << endl;
}

void find_thesame(int arr[], int len, vector<int>& v)
{
	if (len <= 0 || arr == NULL)
	{
		return; 
	}

	for (int i = 0; i < len; i++)
	{
		if (arr[i]<0 || arr[i]>len - 1)
		{
			return;
		}
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				v.push_back(arr[i]);
				break;
			}
			int temp = arr[arr[i]];
			arr[arr[i]] = arr[i];
			arr[i] = temp;
		}
	}
}

int main()
{	
	int arr[] = { 2, 3, 1, 0, 2, 5, 3 }; 
	int len = sizeof(arr) / sizeof(int);
	vector<int> v;
	find_thesame(arr, len, v);
	for_each(v.begin(), v.end(), Print);
	system("pause");
	return 0;
}