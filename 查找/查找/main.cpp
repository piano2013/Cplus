#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//≤È’“
bool Find(int* arr, int row, int col, int num)
{
	if (arr == NULL || row <= 0 || col <= 0)
	{
		return false;
	}

	int i = 0; 
	int j = col - 1;
	while (i < row - 1 && j>=0)
	{
		if (arr[i*col + j] == num)
		{
			return true;
		}
		else if (arr[i*col + j] > num)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return false;
}

int main()
{
	int arr[] = { 1, 2, 4, 5,
		3, 5, 6, 7,
		6, 7, 8, 9 };
	bool flag = Find(arr, 3, 4, 1);

	if (flag == true)
	{
		cout << "Find!" << endl;
	}
	else
	{
		cout << "Not find!" << endl;
	}

	system("pause");
	return 0;
}