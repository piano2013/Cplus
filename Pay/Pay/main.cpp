#include <iostream>
#include "Employee.h"
#include "Technician.h"

using namespace std;

int main()
{
	Employee *em1 = new Technician;

	em1->getPay();
	em1->uplevel(1);
	em1->displayStatus();

	delete em1;

	system("pause");
	return 0;
}