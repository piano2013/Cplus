#pragma once
#include "Employee.h"

using namespace std;

class Technician : public Employee
{
public:
	Technician();
	~Technician();

	//提供员工薪资的计算方法
	virtual void getPay();

	//显示员工信息
	virtual void displayStatus();

	//升级的方法
	virtual void uplevel(int level);

private:
	//一个月的工时
	int workHour;
	//每小时薪资
	double perHourMoney;
};

