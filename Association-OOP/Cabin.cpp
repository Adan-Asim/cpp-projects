#include "Cabin.h"
#include "Employee.h"

#include <iostream>
using namespace std;

Cabin::Cabin(int ID)
{
	cabinID = ID;
	employee = NULL;
}

void Cabin::setCabinID(int ID)
{
	cabinID = ID;
}
int Cabin::getCabinID()
{
	return cabinID;
}

void Cabin::setEmployee(Employee* emp)
{
	employee = emp;
}
Employee* Cabin::getEmployee()
{
	return employee;
}


void Cabin::print()
{
	cout << "\nCabin# " << cabinID;
	if (employee != NULL)
		cout << " is occupied by employee# " << employee->getEmpID();
	
}

Cabin::~Cabin()
{

}
