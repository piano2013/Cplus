#pragma once
#include<iostream>
#include<string>

using namespace std;

//抽象的员工
class Employee
{
public:
	Employee();
	virtual ~Employee();

	//提供员工薪资的计算方法
	virtual void getPay() = 0;

	//显示员工信息
	virtual void displayStatus() = 0;

	//提供修改员工级别的方法
	virtual void uplevel(int level) = 0;

protected:
	string name;
	int id;
	int level;
	double salary;

	//员工的编号基础值
	static int startNum;
};

