#pragma once
#include<iostream>
#include<string>

using namespace std;

//�����Ա��
class Employee
{
public:
	Employee();
	virtual ~Employee();

	//�ṩԱ��н�ʵļ��㷽��
	virtual void getPay() = 0;

	//��ʾԱ����Ϣ
	virtual void displayStatus() = 0;

	//�ṩ�޸�Ա������ķ���
	virtual void uplevel(int level) = 0;

protected:
	string name;
	int id;
	int level;
	double salary;

	//Ա���ı�Ż���ֵ
	static int startNum;
};

