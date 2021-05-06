#include "Employee.h"


Employee::Employee(int ID, string name)
{
	empID = ID;
	empName = name;
	empCabin = NULL;
}


void Employee::setEmpID(int ID)
{
	empID = ID;
}
void Employee::setEmpName(string name)
{
	empName = name;
}
void Employee::setEmpCabin(Cabin* cabin)  //alocates a cabin to an employee
{
	empCabin = cabin;
}

int Employee::getEmpID()
{
	return empID;
}
string Employee::getEmpName()
{
	return empName;
}
Cabin* Employee::getEmpCabin()
{
	return empCabin;
}

 void Employee::print()
{
	 cout << "\nEmployee#" << empID << " " << empName;
	 if (empCabin != NULL)
	 {
		 cout << " is allocated cabin# "<<empCabin->getCabinID();
	 }


}

Employee::~Employee()
{

}


bool Employee::allocateCabin(Cabin* cabin)
{
	if(this->empCabin == NULL)
	{
		if(cabin->getEmployee()==NULL)
		{
			empCabin = cabin;
			cabin->setEmployee(this);
			return true;
		}
		else
		{
			cout<<"\nCabin is already reserved\n";
			return false;
		}
	}
	else
	{
		cout<<"Already has a cabin";
		return false;
	}
}