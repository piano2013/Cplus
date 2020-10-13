#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int> arr, int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//��ʾ�����ռ��ж���Ԫ��
	int length = 0;

	//�ϲ�������������
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
	//i�������
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j�������
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}

	//�����ռ����ݸ��ǵ�ԭ�ռ�
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//�鲢����
void MergeSort(vector<int> arr, int start, int end, int* temp)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;
	//����
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);

	//�ϲ�
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