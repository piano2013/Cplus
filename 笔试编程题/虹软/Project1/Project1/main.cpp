#include <iostream>
using namespace std;
int func(int number)
{
	int result[3] = { 0, 1, 2 };
	if (number<3)
		return result[number];
	int i = 3;
	while (i <= number)
	{
		int temp = result[1] + result[2];
		result[1] = result[2];
		result[2] = temp;
		i++;
	}
	return result[2];
}
int main()
{
	int n;
	while (cin >> n)
	{
		int result = func(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}