#include <iostream>
using namespace std;
int gcd(int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	int z = n;
	while (m%n)
	{
		z = m%n;
		m = n;
		n = z;
	}
	return z;
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int result;
		if (m>n)
			result = gcd(m, n);
		else
			result = gcd(n, m);
		cout << result << endl;
	}
	system("pause");
	return 0;
}