#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	string array1[] = { "a","b" };

	cout << sizeof(array1) << endl;
	cout << sizeof(string) << endl;
	cout << sizeof(array1) / sizeof(string) << endl;
	array<double, 4> array2 = { 1, 2, 3, 4 };
	cout << "array2: "<< sizeof(array2) << endl;
	system("pause");
	return 0;
}
