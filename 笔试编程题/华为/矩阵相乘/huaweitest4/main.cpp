#include<iostream>
#include<vector>
using namespace std;
//int main(){
//	int x, y, z;
//	while (cin >> x >> y >> z){
//		vector<vector<int>> arr1(x, vector<int>(y, 0));
//		vector<vector<int>> arr2(y, vector<int>(z, 0));
//		vector<vector<int>> arr3(x, vector<int>(z, 0));
//		for (int i = 0; i < x; ++i){
//			for (int j = 0; j < y; ++j)
//				cin >> arr1[i][j];
//		}
//		for (int i = 0; i < y; ++i){
//			for (int j = 0; j < z; ++j)
//				cin >> arr2[i][j];
//		}
//		for (int i = 0; i < x; ++i){
//			for (int j = 0; j < y; ++j)
//				for (int k = 0; k < z; ++k)
//					arr3[i][k] += arr1[i][j] * arr2[j][k];
//		}
//		for (int i = 0; i < x; ++i){
//			for (int j = 0; j < z - 1; ++j)
//				cout << arr3[i][j] << " ";
//			cout << arr3[i][z - 1] << endl;
//		}
//	}
//	return 0;
//}

int main()
{
	int rows, cof, cols;
	int x1, x2;
	vector<int> v1, v2;
	vector<vector<int>> vv1, vv2;
	while (cin >> rows >> cof >> cols)
	{
		for (int i = 0; i<rows; i++)
		{
			for (int j = 0; j<cof; j++)
			{
				cin >> x1;
				v1.push_back(x1);
			}
			vv1.push_back(v1);
			v1.clear();
		}
		for (int i = 0; i<cof; i++)
		{
			for (int j = 0; j<cols; j++)
			{
				cin >> x2;
				v2.push_back(x2);
			}
			vv2.push_back(v2);
			v2.clear();
		}
		vector<vector<int>> out(rows, vector<int>(cols, 0));
		for (int i = 0; i<rows; i++)
		{
			for (int j = 0; j<cols; j++)
			{
				int value = 0;
				for (int k = 0; k<vv2.size(); k++)
				{
					value += vv1[i][k] * vv2[k][j];
				}
				out[i][j] = value;
			}
		}
		for (int p = 0; p<rows; p++)
		{
			for (int q = 0; q<cols - 1; q++)
			{
				cout << out[p][q] << " ";
			}
			cout << out[p][cols - 1] << endl;
		}
		vv1.clear();
		vv2.clear();
	}
	system("pause");
	return 0;
}