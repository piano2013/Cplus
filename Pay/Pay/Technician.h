#pragma once
#include "Employee.h"

using namespace std;

class Technician : public Employee
{
public:
	Technician();
	~Technician();

	//�ṩԱ��н�ʵļ��㷽��
	virtual void getPay();

	//��ʾԱ����Ϣ
	virtual void displayStatus();

	//�����ķ���
	virtual void uplevel(int level);

private:
	//һ���µĹ�ʱ
	int workHour;
	//ÿСʱн��
	double perHourMoney;
};

