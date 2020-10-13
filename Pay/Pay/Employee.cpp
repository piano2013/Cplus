#include "Employee.h"

int Employee::startNum = 1000;


Employee::Employee()
{
	cout << "Employee()..." << endl;
	id = startNum++;
	level = 1;
	salary = 0.0;
}


Employee::~Employee()
{
	cout << "~Employee()..." << endl;
}
