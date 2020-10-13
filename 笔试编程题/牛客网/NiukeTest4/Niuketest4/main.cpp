#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool NotCorrect = false;
double power(double base, int exponent)
{
	double result = 1.0;
	if (fabs(base - 0.0) < 1e-6 && exponent == 0)
	{
		NotCorrect = true;
		return 0.0;
	}		
	if (exponent >= 0)
	{
		for (int i = 0; i < exponent; i++)
		{
			result = result*base;
		}
	}
	else
	{
		double tmp = 1.0;
		for (int j = 0; j < (-exponent); j++)
		{
			tmp = tmp*base;
		}
		if (fabs(tmp - 0.0) < 1e-6)
		{
			NotCorrect = true;
			return 0.0;
		}		
		else
			result = result / tmp;		
	}
	return result;
}
int main()
{
	double a = 0.0;
	int b = 0;
	double result = power(a, b);
	printf("%.2f\n", result);
	cout << NotCorrect << endl;
	system("pause");
	return 0;
}