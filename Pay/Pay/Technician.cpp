#include "Technician.h"


Technician::Technician()
{
	cout << "Technician()..." << endl;
	cout << "输入员工姓名：" << endl;
	cin >> name;
	perHourMoney = 100;//默认员工每小时薪资100元
}


Technician::~Technician()
{
	cout << "~Technician()..." << endl;
}

//提供员工薪资的计算方法
void Technician::getPay()
{
	cout << "请输入该员工工作时长：" << endl;

	cin >> workHour;

	this->salary = this->perHourMoney * this->workHour;
}

//显示员工信息
void Technician::displayStatus()
{
	cout << "员工姓名：" << this->name << endl;
	cout << "员工的级别：" << this->level << endl;
	cout << "员工的月薪：" << this->salary << endl;
	cout << "员工的ID：" << this->id << endl;
}

void Technician::uplevel(int level)
{
	this->level += level;

}