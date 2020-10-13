#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> v = {};
	if (matrix.size() == 0 || matrix[0].size() == 0)
	{
		return v;
	}
	int rows = matrix.size();
	int cols = matrix[0].size();
	int i_start = 0, j_start = 0;
	int i_end = rows, j_end = cols;
	while (i_start < i_end && j_start < j_end)
	{
		int i = i_start, j = j_start;
		for (j = j_start; j<j_end; j++)
		{
			v.push_back(matrix[i][j]);
		}
		i_start++;
		j--;
		if (i_start == i_end || j_start == j_end)
			break;
		for (i = i + 1; i<i_end; i++)
		{
			v.push_back(matrix[i][j]);
		}
		j_end--;
		i--;
		if (i_start == i_end || j_start == j_end)
			break;
		for (j = j - 1; j >= j_start; j--)
		{
			v.push_back(matrix[i][j]);
		}
		i_end--;
		j++;
		if (i_start == i_end || j_start == j_end)
			break;
		for (i = i - 1; i >= i_start; i--)
		{
			v.push_back(matrix[i][j]);
		}
		j_start++;
	}
	return v;
}

int main()
{
	vector<int> a = { 1, 2, 3, 4 };
	vector<int> b = { 5, 6, 7, 8 };
	vector<int> c = { 9, 10, 11, 12 };
	vector<int> d = { 13, 14, 15, 16 };
	vector<vector<int>> v;
	v.push_back(a);
	//v.push_back(b);
	//v.push_back(c);
	//v.push_back(d);
	//v.clear();
	vector<int> p = printMatrix(v);
	for (vector<int>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}