#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int Manacher(string oriStr) {
	string newStr;
	int len = oriStr.size();
	for (int i = 0; i < len; i++) {//插入间隔符
		newStr += '#';
		newStr += oriStr[i];
	}
	newStr += '#';
	len = 2 * len + 1;             //新串长度，必为奇数
	int maxRight = 0;              //当前访问到的所有回文子串中，所能触及的最右一个字符的位置
	int pos = 0;                   //maxRight对应的回文子串对称轴的位置
	int*RL = new int[len];         //RL[i]记录以i为对称轴的最长回文子串半径长度（对称轴到最左或最右的距离）
	int maxLength = 0;             //记录最长回文子串长度
	for (int i = 0; i < len; i++) {
		if (i < maxRight) {        //分两种情况，i在maxRight左边和右边
			RL[i] = min(RL[2 * pos - i], maxRight - i);
		}
		else RL[i] = 1;
		while (i - RL[i] >= 0 && RL[i] + i < len && newStr[i - RL[i]] == newStr[i + RL[i]])
			RL[i]++;               //以i为中心，在上步的基础上扩展，直至到达边界或左右字符不相等
		if (maxRight < RL[i] + i - 1) {//更新maxRight和pos
			maxRight = RL[i] + i - 1;
			pos = i;
		}
		maxLength = max(maxLength, RL[i] - 1);//对以i为中心的回文子串在原串总的长度即为RL[i] - 1
		//证明：新串中回文子串长度为2*RL[i]-1，其中RL[i]个
		//插入字符，则剩下的RL[i]-1个为原字符
	}
	return maxLength;
}

int main() {
	string str;
	while (cin >> str) {
		cout << Manacher(str) << endl;
	}
	return 0;
}