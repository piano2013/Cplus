#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	int k;
	while (cin >> n >> k)
	{
		string s;
		cin >> s;
		if (s.length() != n)
			return 0;
		int i = 0;
		int j = 1;
		while (j < s.size()) {
			if (s[i] == s[j]) {
				j++;
				i++;
			}
			else if (s[i] != s[j]) {
				if (i != 0){
					i = 0;
				}
				else{
					j++;
				}
				
			}
		}
		string a;
		a.assign(s.begin() + i, s.end());
		string res;
		while (k>1){
			res += a;
			k--;
		}
		cout << s + res << endl;
	}	
	system("pause");
	return 0;
}