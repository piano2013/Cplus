#include <iostream>
#include <time.h>
#include <set>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	set<int> s;
	while (s.size()<10)
	{
		s.insert(rand() % (100 - 1) + 1);
	}
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}