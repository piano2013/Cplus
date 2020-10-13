#include <iostream>
#include <vector>
using namespace std;
int main()
{
	bool bflag = false;
	vector<int>v;
	int low = 0, high = 0;
	while(cin >> low >> high)
	{
		for (int i = low; i < high; i++)
		{
			bflag = false;
			for (int j = 2; j < i; j++)
			{
				if (i%j == 0)
				{
					bflag = true;
					break;
				}
			}
			if (bflag == false)
			{
				v.push_back(i);
			}
		}
		int sum_ge = 0, sum_shi = 0;
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			sum_ge += *it % 10;
			int temp = *it / 10;
			sum_shi += temp % 10;
		}
		int result = (sum_ge>sum_shi) ? sum_shi : sum_ge;
		cout << result << endl;
	}	
	system("pause");
	return 0;
}