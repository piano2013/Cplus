#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class People
{
public:

	People() {};
	People(string name, int score) :name(name), score(score) {};

	~People() {};
public:
	int score;
	string name;
};

//创建选手
void CreatPeople(vector<People>& p)
{
	string nameSeed =  "ABCDE" ;
	for (int i = 0; i < 5; i++)
	{
		People pp;
		pp.name = "选手";
		pp.name += nameSeed[i];
		pp.score = 0;

		p.push_back(pp);
	}
}
void Printscore(int val)
{
	cout << val << " ";
}
//打分
void Set_Score(vector<People>& p)
{
	//打分
	for (vector<People>::iterator it = p.begin(); it != p.end(); it++)
	{
		deque<int> dscore;
		for (int index = 0; index < 10; index++)
		{
			int score = rand() % 41 + 60;
			dscore.push_back(score);
		}
		//排序
		sort(dscore.begin(), dscore.end());
		/*for_each(dscore.begin(), dscore.end(), Printscore);
		cout << endl;*/
		dscore.pop_back();
		dscore.pop_front();
		//求平均分
		int totalscore = 0;
		for (deque<int>::iterator dit = dscore.begin(); dit != dscore.end(); dit++)
		{
			totalscore += (*dit);
		}
		(*it).score = totalscore / dscore.size();
	}
}
	
bool compare(People& p1,People& p2)
{
	return p1.score < p2.score;
}

//排名
void People_Rank(vector<People>& p)
{
	sort(p.begin(), p.end(), compare);
	for (vector<People>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "姓名：" << (*it).name << " 得分：" << (*it).score << endl;
	}
}

int main()
{
	vector<People> plist;
	CreatPeople(plist);
	Set_Score(plist);
	People_Rank(plist);

	system("pause");
	return 0;
}