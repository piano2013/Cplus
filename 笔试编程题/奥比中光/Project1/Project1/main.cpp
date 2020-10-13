#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int> arr, int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//表示辅助空间有多少元素
	int length = 0;

	//合并两个有序序列
	while (i_start <= i_end&&j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	//i这个序列
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j这个序列
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}

	//辅助空间数据覆盖到原空间
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//归并排序
void MergeSort(vector<int> arr, int start, int end, int* temp)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;
	//分组
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);

	//合并
	Merge(arr, start, end, mid, temp);
}
int main()
{
	int m;
	int* temp;
	vector<int> v;
	vector<int> v2;
	while (true)
	{
		cin >> m;
		v.push_back(m);
		if (cin.get() == '\n')
			break;
	}

	while (true)
	{
		cin >> m;
		v2.push_back(m);
		if (cin.get() == '\n')
			break;
	}
	for (int i = 0; i < v2.size(); i++)
	{
		v.push_back(v2[i]);
	}
	MergeSort(v, 0, v.size() - 1, temp);
	system("pause");
	return 0;
}