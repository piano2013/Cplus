#include "Technician.h"


Technician::Technician()
{
	cout << "Technician()..." << endl;
	cout << "����Ա��������" << endl;
	cin >> name;
	perHourMoney = 100;//Ĭ��Ա��ÿСʱн��100Ԫ
}


Technician::~Technician()
{
	cout << "~Technician()..." << endl;
}

//�ṩԱ��н�ʵļ��㷽��
void Technician::getPay()
{
	cout << "�������Ա������ʱ����" << endl;

	cin >> workHour;

	this->salary = this->perHourMoney * this->workHour;
}

//��ʾԱ����Ϣ
void Technician::displayStatus()
{
	cout << "Ա��������" << this->name << endl;
	cout << "Ա���ļ���" << this->level << endl;
	cout << "Ա������н��" << this->salary << endl;
	cout << "Ա����ID��" << this->id << endl;
}

void Technician::uplevel(int level)
{
	this->level += level;

}