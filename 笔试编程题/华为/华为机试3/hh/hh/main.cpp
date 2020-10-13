#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int main() {
	vector<string> v;
	string len;
	while (true) {
		string str;
		cin >> str;
		v.push_back(str);
		if (cin.get() == '\n')
			break;
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == "A") {
			v[i] = "12";
			v.insert(v.begin() + i + 1, "34");
		}
		if (v[i] == "B") {
			v[i] = "AB";
			v.insert(v.begin() + i + 1, "CD");
		}
	}
	//cout << setiosflags(ios::uppercase) << hex << v.size() << " ";
	printf("%X ", v.size());
	for (int i = 1; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	system("pause");
	return 0;
}