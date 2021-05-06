#pragma once
#include<iostream>
#include<string>
#include"Cabin.h"
using namespace std;

class Employee
{
	int empID;
	string empName;
	Cabin* empCabin;
public:
	Employee(int ID=0, string name="");
	void setEmpID(int ID);
	void setEmpName(string name);
	void setEmpCabin(Cabin* cabin);  //alocates a cabin to an employee
	int getEmpID();
	string getEmpName();
	Cabin* getEmpCabin();
	bool allocateCabin(Cabin* cabin);
	void print();
	~Employee();
};

