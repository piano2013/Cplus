#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
double func(double in)
{
	double x = 1.0;
	while (abs(x*x*x - in)>1e-9)
		x = (2.0 / 3.0)*x + in / (3.0*x*x);
	return x;
}
int main()
{
	/*double a;
	cin >> a;
	double result = func(a);
	printf("%.1f\n", result);*/
	string str;
	string s = "abcd";
	for (int i = 0; i < s.length(); i++)
	{
		str += s[i];
	}
	cout << str << endl;
	system("pause");
	return 0;
}
/*int main()
{
	//string a;
	//vector<string> v;
	//while (cin >> a)
	//{
	//	v.push_back(a);
	//	if (cin.get() == '\n')
	//		break;
	//}
	//for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	//sort(v.begin(), v.end());
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	double a;
	cin >> a;
	printf("%.1f\n", a);
	system("pause");
	return 0;
}*/