#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
//static bool flag = false;
//bool occupied(map<char,int>& m)
//{
//	int count = 0;
//	for (map<char, int>::iterator oit = m.begin(); oit != m.end(); oit++){
//		if ((*oit).second != 0){
//			count++;
//		}
//	}
//	if (count > 0)
//		return true;
//	return false;
//}
bool Isthelast(map<char, int>::iterator oit, map<char, int>& m){
	oit++;
	if (oit == m.end()){
		return true;
	}
	return false;
}
map<char, int> calculate(string str){
	map<char, int> output;
	map<char, int> occupy;
	vector<char> in;
	vector<char> ocin;
	vector<int> num;
	vector<int> ocnum;
	int i = 0;
	if (str.length() < 4)
		return output;
	while (str[i] != '@'){
		char ch = str[i];
		if (ch >= 'A'&&ch <= 'Z' || ch >= 'a'&&ch <= 'z'){
			in.push_back(ch);
			i++;
			continue;
		}
		if (ch == ':'){
			int result = 0;
			i++;
			while (str[i] != ','&&str[i] != '@'){
				int num1 = str[i] - '0';
				result = result * 10 + num1;
				i++;
			}
			num.push_back(result);
			if (str[i] == ','){
				i++;
				continue;
			}
		}
	}
	i++;
	while (str[i] != '\0'){
		char ch = str[i];
		if (ch >= 'A'&&ch <= 'Z' || ch >= 'a'&&ch <= 'z'){
			ocin.push_back(ch);
			i++;
			continue;
		}
		if (ch == ':'){
			int result = 0;
			i++;
			while (str[i] != ','&&str[i] != '\0'){
				int num1 = str[i] - '0';
				result = result * 10 + num1;
				i++;
			}
			ocnum.push_back(result);
			if (str[i] == ','){
				i++;
				continue;
			}
		}
	}
	if (in.empty() || num.empty())
		return output;	 	
	vector<char>::iterator cit = in.begin();
	vector<int>::iterator it = num.begin();
	while (cit != in.end()&&it != num.end()){
		output.insert(make_pair((*cit), (*it)));
		cit++;
		it++;
	}
	if (ocin.empty() || ocnum.empty())
		return output;
	vector<char>::iterator ocit = ocin.begin();
	vector<int>::iterator oit = ocnum.begin();
	while (ocit != ocin.end() && oit != ocnum.end()){
		occupy.insert(make_pair((*ocit), (*oit)));
		ocit++;
		oit++;
	}
	//flag = occupied(occupy);
	/*for (map<char, int>::iterator it = output.begin(); it != output.end();){
		for (map<char, int>::iterator oit = occupy.begin(); oit != occupy.end(); oit++){
			if ((*oit).first == (*it).first){
				(*it).second = (*it).second - (*oit).second;
				if ((*it).second <= 0)
					output.erase(it++);
				else
					++it;
				break;
			}
		}
	}*/
	for (map<char, int>::iterator it = occupy.begin(); it != occupy.end(); it++){
		map<char, int>::iterator ret = output.find((*it).first);
		if (ret != output.end()){
			ret->second = ret->second - (*it).second;
			if (ret->second <= 0)
				output.erase(ret);
		}
	}
	return output;
}
int main(){
	string s;
	cin >> s;
	//s = "a:30,b:5,c:2@";
	map<char, int> mymap;
	mymap = calculate(s);
	map<char, int>::iterator it = mymap.begin();
	while(it!=mymap.end()){
		if (Isthelast(it, mymap)){
			cout << (*it).first << ":" << (*it).second << endl;
			/*if (flag == false)
				cout << (*it).first << ":" << (*it).second << "@" << endl;
			else
				cout << (*it).first << ":" << (*it).second << endl;*/
		}
		else
			cout << (*it).first << ":" << (*it).second << ",";
		it++;
	}
	system("pause");
	return 0;
}