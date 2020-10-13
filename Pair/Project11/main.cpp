#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void test()
{
	pair<int, int> pair1(10, 20);
	cout << pair1.first << " " << pair1.second << endl;

	pair<int, string> pair2 = make_pair(10, "aaa");
	cout << pair2.first << " " << pair2.second << endl;

	pair<int, string> pair3 = pair2;
	cout << pair3.first << " " << pair3.second << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}