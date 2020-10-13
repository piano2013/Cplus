#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
bool calculate(string str) {
	stack<char> st;
	vector<char> output;
	//后缀表达式
	for (unsigned int i = 0; i<str.length(); i++) {
		char ch = str[i];
		if (ch == '0' || ch == '1') {
			output.push_back(ch);
		}
		else {
			switch (ch) {
				case '!':
					st.push(ch);
					break;
				case '(':
					st.push(ch);
					break;
				case ')':
					while (st.top() != '(') {  //顶部去除
						output.push_back(st.top());
						st.pop();
					}
					st.pop();
					break;
				case '&':
					while (!st.empty() && (st.top() == '!' || st.top() == '&')) {
						output.push_back(st.top());
						st.pop();
					}
					st.push(ch);
					break;
				case '|':
					while (!st.empty() && (st.top() == '!' || st.top() == '&' || st.top() == '|')) {
						output.push_back(st.top());
						st.pop();
					}
					st.push(ch);
					break;
				default:
					break;
			}
		}
	}
	while (st.size()>0) {
		output.push_back(st.top());
		st.pop();
	}
	//后缀表达式求解
	stack<bool> ss;
	for (unsigned int i = 0; i<output.size(); i++) {
		char ch = output[i];
		bool tmp;
		bool tmp1;
		bool tmp2;
		if (ch == '1' || ch == '0') {
			ss.push(ch - '0');
		}
		else {
			switch (ch) {
				case '!':
					if (!ss.empty()){
						tmp = ss.top();
						ss.pop();
						tmp = !tmp;
						ss.push(tmp);
					}										
					break;
				case '&':
					if (!ss.empty()){
						tmp1 = ss.top();//右操作数
						ss.pop();
					}
					if (!ss.empty()){
						tmp2 = ss.top();//左操作数
						ss.pop();
						ss.push((tmp2&tmp1));
					}					 
					break;
				case '|':
					if (!ss.empty()){
						tmp1 = ss.top();//右操作数
						ss.pop();
					}
					if (!ss.empty()){
						tmp2 = ss.top();//左操作数
						ss.pop();
						ss.push((tmp2 | tmp1));
					}
					break;
				default:
					break;
			}
		}
	}
	return ss.top();
}
int main() {
	//string expr = "!0&(0|!1)|!0";
	//string expr = "!1";
	string expr;
	cin >> expr;
	cout << calculate(expr) << endl;
	system("pause");
	return 0;
}