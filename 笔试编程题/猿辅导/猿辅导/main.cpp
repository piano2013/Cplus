#include <iostream>
#include <vector>
#include <hash_map>
#include <unordered_map>
#include <map>
using namespace std;
//int main()
//{
//	int n, m;
//	long long num;	
//	while (cin >> n >> m)
//	{
//		vector<long long> v;
//		hash_map<long long, int> mymap;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> num;
//			v.push_back(num);
//		}
//		for (int j = 0; j < n; j++)
//		{
//			if (mymap.empty())
//			{
//				mymap.insert(make_pair(v[j], 1));
//				continue;
//			}			
//			hash_map<long long, int>::iterator ret = mymap.find(v[j]);
//			if (ret != mymap.end())
//				ret->second += 1;
//			else
//				mymap.insert(make_pair(v[j], 1));
//		}
//		for (hash_map<long long, int>::iterator it = mymap.begin(); it != mymap.end();)
//		{
//			if (it->second > m)
//				mymap.erase(it++);
//			else
//				++it;
//		}
//		for (hash_map<long long, int>::iterator rit = mymap.begin(); rit != mymap.end(); rit++)
//		{
//			for (int i = 0; i < rit->second;i++)
//				cout << rit->first << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	hash_map<int, int> mymap1;
	unordered_map<int, int> mymap2;
	map<int, int> mymap3;
	mymap1[0] = 1;
	mymap1.insert(mymap1.end(), make_pair(11, 2));
	mymap1.insert(mymap1.end(), make_pair(5, 2));
	mymap1.insert(mymap1.end(), make_pair(9, 2));
	mymap1.insert(mymap1.end(), make_pair(2, 2));
	mymap1.insert(mymap1.end(), make_pair(1, 2));
	//mymap1.insert(mymap1.end(), pair<int, int>(7, 3));
	//mymap1.insert(mymap1.end(), hash_map<int, int>::value_type(3, 3));
	for (hash_map<int, int>::iterator it1 = mymap1.begin(); it1 != mymap1.end(); it1++)
	{
		cout << it1->first << ":" << it1->second << endl;
	}
	mymap2[0] = 1;
	mymap2.insert(mymap2.end(), make_pair(11, 2));
	mymap2.insert(mymap2.end(), make_pair(3, 2));
	mymap2.insert(mymap2.end(), make_pair(7, 2));
	mymap2.insert(mymap2.end(), make_pair(4, 2));
	//mymap2.insert(mymap2.end(), pair<int, int>(7, 3));
	//mymap2.insert(mymap2.end(), unordered_map<int, int>::value_type(3, 3));
	for (unordered_map<int, int>::iterator it2 = mymap2.begin(); it2 != mymap2.end(); it2++)
	{
		cout << it2->first << ":" << it2->second << endl;
	}
	mymap3[0] = 1;
	mymap3.insert(mymap3.end(), make_pair(11, 2));
	mymap3.insert(mymap3.end(), make_pair(3, 2));
	mymap3.insert(mymap3.end(), make_pair(7, 2));
	mymap3.insert(mymap3.end(), make_pair(4, 2));
	//mymap2.insert(mymap2.end(), pair<int, int>(7, 3));
	//mymap2.insert(mymap2.end(), unordered_map<int, int>::value_type(3, 3));
	for (map<int, int>::iterator it3 = mymap3.begin(); it3 != mymap3.end(); it3++)
	{
		cout << it3->first << ":" << it3->second << endl;
	}
	system("pause");
	return 0;
}