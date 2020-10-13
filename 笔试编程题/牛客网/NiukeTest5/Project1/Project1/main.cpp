#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <functional>
# include <vector>
# include <algorithm>
# include <string>
# include <queue>
# include <set>
using namespace std;

void printVec(vector<int> nums)
{
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
}
//int main(void)
//{
//	int nums_temp[] = { 8, 3, 4, 8, 9, 2, 3, 4, 10 };
//	vector<int> nums(nums_temp, nums_temp + 9);
//	cout << "make_heap֮ǰ: ";
//	printVec(nums);
//
//	cout << "(Ĭ��(less))make_heap: ";
//	make_heap(nums.begin(), nums.end());
//	printVec(nums);
//
//	cout << "(less)make_heap: ";
//	make_heap(nums.begin(), nums.end(), less<int>());
//	printVec(nums);
//
//	cout << "(greater)make_heap: ";
//	make_heap(nums.begin(), nums.end(), greater<int>());
//	printVec(nums);
//
//	cout << "��ʱ��numsΪС���� greater" << endl;
//	cout << "push_back(3)" << endl;
//	nums.push_back(3);
//	//cout << "Ĭ��(less)push_heap ��ʱpush_heapʧ��: ";
//	//push_heap(nums.begin(), nums.end());
//	printVec(nums);
//	cout << "push_heapΪgreater ��make_heapһ�£���ʱpush_heap�ɹ�: ";
//	push_heap(nums.begin(), nums.end(), greater<int>());
//	printVec(nums);
//	cout << "(greater,��Ȼ��ʧ��)pop_heap: ";
//	pop_heap(nums.begin(), nums.end(), greater<int>());
//	printVec(nums);
//	cout << "pop_back(): ";
//	nums.pop_back();
//	printVec(nums);
//	system("pause");
//	return 0;
//}
int main(){
	priority_queue <int, vector<int>, less<int> > q;
	multiset<int, less<int>> m;
	for (int i = 1; i < 7; i++){
		q.push(i);
		m.insert(i);
	}
	for (int i = 0; i < 6; i++){
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
	for (int i = 0; i < 6; i++){
		cout << *m.begin() << ' ';
		m.erase(m.begin());
	}
	system("pause");
	return 0;
}