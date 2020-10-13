//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <queue>
//using namespace std;
//priority_queue<int, vector<int>, less<int> > p;
//priority_queue<int, vector<int>, greater<int> > q;
//void Insert(int num){
//	if (p.empty() || num <= p.top()) p.push(num);
//	else q.push(num);
//	if (p.size() == q.size() + 2) q.push(p.top()), p.pop();
//	if (p.size() + 1 == q.size()) p.push(q.top()), q.pop();
//}
//double GetMedian(){
//	return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		Insert(num);
//	}
//	cout << GetMedian();
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.empty()) return 0;
	int sum = array[0], tempsum = array[0]; //注意初始值 不能设为0 防止只有负数
	for (int i = 1; i < array.size(); i++)  //从1开始 因为0的情况在初始化时完成了
	{
		tempsum = (tempsum < 0) ? array[i] : tempsum + array[i];
		sum = (tempsum > sum) ? tempsum : sum;
	}
	return sum;
}
int main()
{
	int num;
	vector<int> v;
	while (true)
	{
		cin >> num;
		v.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	cout << FindGreatestSumOfSubArray(v);
	system("pause");
	return 0;
}