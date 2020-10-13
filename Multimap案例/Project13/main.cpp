#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门

//multimap案例
//公司今年招聘了5个员工，5名员工进入公司之后，需要指派员工在哪个部门工作
//人员信息有：姓名、年龄、电话、工资等
//通过multimap进行信息的插入、保存、显示
//分部门显示员工信息，显示全部员工信息

class Worker
{
public:
	Worker() {}
	~Worker() {}
public:
	string mName;
	string mTele;
	int mAge;
	int mSalary;
};

void Creat_worker(vector<Worker>& vWorker)
{
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Worker worker;
		worker.mName = "员工";
		worker.mName += seedName[i];

		worker.mAge = rand() % 10 + 20;
		worker.mTele = "010-8888888";
		worker.mSalary = rand() % 10000 + 10000;

		//保存员工信息
		vWorker.push_back(worker);
	}
}

void WorkbyGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup)
{
	
	//把员工随机分配到不同部门
	srand(time(NULL));
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		int departID = rand() % 3 + 1;
		switch (departID)
		{
		case SALE_DEPATMENT:
			workerGroup.insert(make_pair(SALE_DEPATMENT, *it));
			break;
		case DEVELOP_DEPATMENT:
			workerGroup.insert(make_pair(DEVELOP_DEPATMENT, *it));
			break;
		case FINACIAL_DEPATMENT:
			workerGroup.insert(make_pair(FINACIAL_DEPATMENT, *it));
			break;
		default:
			break;
		}
	}
}

void ShowGroupWorkers(multimap<int, Worker>& workerGroup, int DepartID)
{
	multimap<int, Worker>::iterator it = workerGroup.find(DepartID);
	//当前部门的总人数
	int DepartCount = workerGroup.count(DepartID);

	int num = 0;
	for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; pos++, num++)
	{
		cout << "姓名：" << pos->second.mName << " 年龄：" << pos->second.mAge << " 电话：" << pos->second.mTele << " 工资：" << pos->second.mSalary << endl;
	}
}

void PrintWorkerbyGroup(multimap<int, Worker>& workerGroup)
{
	//显示销售部门
	cout << "销售部门：" << endl;
	ShowGroupWorkers(workerGroup, SALE_DEPATMENT);
	//显示研发部门
	cout << "研发部门：" << endl;
	ShowGroupWorkers(workerGroup, DEVELOP_DEPATMENT);
	//显示财务部门
	cout << "财务部门：" << endl;
	ShowGroupWorkers(workerGroup, FINACIAL_DEPATMENT);
}

int main()
{
	//存放新员工信息
	vector<Worker> vWorker;

	//multimap保存分组信息
	multimap<int, Worker> workerGroup;

	//创建员工
	Creat_worker(vWorker);

	//员工分组
	WorkbyGroup(vWorker, workerGroup);

	//打印每一部门的员工信息
	PrintWorkerbyGroup(workerGroup);

	system("pause");
	return 0;
}