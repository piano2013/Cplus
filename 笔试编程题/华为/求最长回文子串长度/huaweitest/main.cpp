#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int Manacher(string oriStr) {
	string newStr;
	int len = oriStr.size();
	for (int i = 0; i < len; i++) {//��������
		newStr += '#';
		newStr += oriStr[i];
	}
	newStr += '#';
	len = 2 * len + 1;             //�´����ȣ���Ϊ����
	int maxRight = 0;              //��ǰ���ʵ������л����Ӵ��У����ܴ���������һ���ַ���λ��
	int pos = 0;                   //maxRight��Ӧ�Ļ����Ӵ��Գ����λ��
	int*RL = new int[len];         //RL[i]��¼��iΪ�Գ����������Ӵ��뾶���ȣ��Գ��ᵽ��������ҵľ��룩
	int maxLength = 0;             //��¼������Ӵ�����
	for (int i = 0; i < len; i++) {
		if (i < maxRight) {        //�����������i��maxRight��ߺ��ұ�
			RL[i] = min(RL[2 * pos - i], maxRight - i);
		}
		else RL[i] = 1;
		while (i - RL[i] >= 0 && RL[i] + i < len && newStr[i - RL[i]] == newStr[i + RL[i]])
			RL[i]++;               //��iΪ���ģ����ϲ��Ļ�������չ��ֱ������߽�������ַ������
		if (maxRight < RL[i] + i - 1) {//����maxRight��pos
			maxRight = RL[i] + i - 1;
			pos = i;
		}
		maxLength = max(maxLength, RL[i] - 1);//����iΪ���ĵĻ����Ӵ���ԭ���ܵĳ��ȼ�ΪRL[i] - 1
		//֤�����´��л����Ӵ�����Ϊ2*RL[i]-1������RL[i]��
		//�����ַ�����ʣ�µ�RL[i]-1��Ϊԭ�ַ�
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