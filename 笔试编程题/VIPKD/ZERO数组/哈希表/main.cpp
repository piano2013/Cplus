#include <iostream>
#include <vector>
using namespace std;

int arrPartition(vector<int> arr, int low, int high)
{
	int pivotValue = arr[low];
	while (low<high)
	{
		while (low<high && arr[high] >= pivotValue)
			high--;
		swap(arr[low], arr[high]);
		while (low<high && arr[low] <= pivotValue)
			low++;
		swap(arr[low], arr[high]);
	}
	return low;
}

void quickSort(vector<int> arr, int low, int high)
{
	if (low<high)
	{
		int pivotIndex = arrPartition(arr, low, high);
		quickSort(arr, low, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, high);
	}
}

void dualSum(vector<int> arr, int len, int sum)
{
	int low = 0;
	int high = len - 1;
	int count = 0;
	while (low<high)
	{


		if (arr[low] + arr[high]>sum)
			high--;
		else if (arr[low] + arr[high]<sum)
			low++;
		else
		{
			//cout << arr[low] << " + " << arr[high] << " = " << sum << endl;
			count++;

			high--; low++;
		}
	}
	cout << count << endl;
}

int main()
{
	int x, b;
	vector<int> v1;
	while (true)
	{

		cin >> x;
		v1.push_back(x);
		if (cin.get() == '\n')
			break;
	}
	int len = v1.size();
	quickSort(v1, 0, len);
	// for(int i=0;i<len;i++)
	//     cout << v1[i] << " ";
	// cout << endl;
	// dualSum(arr2,5,28);
	dualSum(v1, len, 0);

	return 0;
}