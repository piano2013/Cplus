#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
int Core(int q, int siz) {
	int res;
	if (q * 2 + 1 <= siz) {
		q = q * 2 + 1;
		while (q * 2 <= siz)
			q = q * 2;
		res = q;
		return res;
	}
	int r = q / 2;
	while (q / 2 != 0) {
		r = q / 2;
		if (q == r * 2) {
			res = r;
			return res;
		}
		q = r;
	}
	return -1;
}
int main() {
	vector<int> v;
	while (true) {
		int a;
		cin >> a;
		v.push_back(a);
		if (cin.get() == '\n')
			break;
	}
	int n;
	cin >> n;
	int q = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != n)
			q++;
		else 
			break;
	}
	int siz = v.size();
	cout << Core(q, siz);
}