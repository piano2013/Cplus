#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//int main() {
//	string a;
//	vector<string> s;
//	while (true) {
//		cin >> a;
//		s.push_back(a);
//		if (cin.get() == '\n')
//			break;
//	}
//	for (int i = 0; i < s.size(); i++) {
//		for (int j = 0; j < s[i].size(); j++) {
//			if (s[i][j] >= 'A'&&s[i][j] <= 'z') {
//				s[i].erase(s[i].begin() + j);
//			}
//		}
//	}
//
//	for (int i = 0; i < s.size(); i++) {
//		cout << s[i] << endl;
//	}
//}

int main()
{
	//int c;
	//vector<int> a;
	//while (1)
	//{		
	//	cin >> c;
	//	a.push_back(c);
	//	if (cin.get() == '\n')
	//		break;
	//}
	//for (int i = 0; i < a.size(); i++)
	//{
	//	cout << a[i] << endl;
	//}
	//vector<int>::iterator it = a.begin() + a.size() / 2;
	//cout << *it << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl; 
	cout << sizeof(long) << endl;
	cout << sizeof(short) << endl;
	system("pause");
	return 0;
}