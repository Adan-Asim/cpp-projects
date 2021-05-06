#pragma once

class Employee;                 //Forward Declaration; to Avoid recursive Call

class Cabin
{
	int cabinID;
	Employee* employee;
public:
	Cabin(int ID=0);
	void setCabinID(int ID);
	int getCabinID();
	void setEmployee(Employee* emp);
	Employee* getEmployee();
	void print();
	~Cabin();
};

