#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define SALE_DEPATMENT 1 //���۲���
#define DEVELOP_DEPATMENT 2 //�з�����
#define FINACIAL_DEPATMENT 3 //������

//multimap����
//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����ĸ����Ź���
//��Ա��Ϣ�У����������䡢�绰�����ʵ�
//ͨ��multimap������Ϣ�Ĳ��롢���桢��ʾ
//�ֲ�����ʾԱ����Ϣ����ʾȫ��Ա����Ϣ

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
		worker.mName = "Ա��";
		worker.mName += seedName[i];

		worker.mAge = rand() % 10 + 20;
		worker.mTele = "010-8888888";
		worker.mSalary = rand() % 10000 + 10000;

		//����Ա����Ϣ
		vWorker.push_back(worker);
	}
}

void WorkbyGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup)
{
	
	//��Ա��������䵽��ͬ����
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
	//��ǰ���ŵ�������
	int DepartCount = workerGroup.count(DepartID);

	int num = 0;
	for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; pos++, num++)
	{
		cout << "������" << pos->second.mName << " ���䣺" << pos->second.mAge << " �绰��" << pos->second.mTele << " ���ʣ�" << pos->second.mSalary << endl;
	}
}

void PrintWorkerbyGroup(multimap<int, Worker>& workerGroup)
{
	//��ʾ���۲���
	cout << "���۲��ţ�" << endl;
	ShowGroupWorkers(workerGroup, SALE_DEPATMENT);
	//��ʾ�з�����
	cout << "�з����ţ�" << endl;
	ShowGroupWorkers(workerGroup, DEVELOP_DEPATMENT);
	//��ʾ������
	cout << "�����ţ�" << endl;
	ShowGroupWorkers(workerGroup, FINACIAL_DEPATMENT);
}

int main()
{
	//�����Ա����Ϣ
	vector<Worker> vWorker;

	//multimap���������Ϣ
	multimap<int, Worker> workerGroup;

	//����Ա��
	Creat_worker(vWorker);

	//Ա������
	WorkbyGroup(vWorker, workerGroup);

	//��ӡÿһ���ŵ�Ա����Ϣ
	PrintWorkerbyGroup(workerGroup);

	system("pause");
	return 0;
}