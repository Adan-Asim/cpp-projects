#include<iostream>
#include<fstream>
#include<string>
#include"Employee.h"

using namespace std;



int main()
{
	int empCount = 0;   // increment empCount whenever a new employee is created in elist
	int cabinCount = 0;  // increment cabinCount whenever a new cabin is created in clist
	Employee* elist[10];  // Static Array of 10 pointers    
	Cabin* clist[10];
	

	for (int i = 0;; i++)
	{
		int n;
		cout << "Menu:\n1. Create Employee\n2. Create Cabin\n3. Allocate Cabin\n4. Re-Allocate Cabin\n5. Free Cabinn\n6. Print employee's info\n7. Print Cabin's info\n8. Exit";
		cout << "\nEnter your Choice: ";
		cin >> n;

		if (n == 1)
		{
			string name;
			cout << "\nEnter Name of Employee: ";
			cin >> name;
			int id;
			cout << "Enter Id of Employee: ";
			cin >> id;

			elist[empCount] = new Employee(id, name);
			empCount++;
			cout << "\nEmployee Created Succesfully";
		}

		if (n == 2)
		{
			int id;
			cout << "\nEnter Id of Cabin: ";
			cin >> id;

			clist[cabinCount] = new Cabin(id);
			cabinCount++;
			cout << "\nCabin Created Succesfully";
		}

		if (n == 3)
		{
			int indexe, indexc;
			bool state = false;
 		
			int ide;
			cout << "\nEnter Id of Employee: ";
			cin >> ide;
			for(int i=0;i<empCount;i++)
				if (ide == elist[i]->getEmpID())
				{
					indexe = i;
					state = true;
				}
			if (state == false)
			{
				cout << "\nNot Found\n\n";
				continue;
			}
				state = false;
		
		
			int idc;
			cout << "\nEnter Id of Cabin: ";
			cin >> idc;
			for (int i = 0; i < cabinCount; i++)
				if (idc == clist[i]->getCabinID())
				{
					indexc = i;
					state = true;
				}

			if (state == false)
			{
				cout << "\nNot Found\n\n";
				continue;
			}


			if (elist[indexe]->allocateCabin(clist[indexc]))
				cout << "\nCabin Allocated Successfully";
			else 
				cout << "\nCouldn't Allocate Cabin";
		}

		if (n == 4)
		{
			Employee* obj;
			int indexc,indexe;
			bool state = false;

			int idc;
			cout << "\nEnter Id of Cabin: ";
			cin >> idc;
			for (int i = 0; i < cabinCount; i++)
				if (idc == clist[i]->getCabinID())
				{
					indexc = i;
					state = true;
				}
			if (state == false)
			{
				cout << "\nID not Found\n\n";
				continue;
			}


			obj = clist[indexc]->getEmployee();
			if (obj->getEmpCabin() != NULL)
			obj->setEmpCabin(NULL);

			if (clist[indexc]->getEmployee() != NULL)
			clist[indexc]->setEmployee(NULL);
           
			state = false;
			int ide;
			cout << "\nEnter Id of Employee: ";
			cin >> ide;
			for (int i = 0; i < empCount; i++)
				if (ide == elist[i]->getEmpID())
				{
					indexe = i;
					state = true;
				}
			if (state == false)
			{
				cout << "\nNot Found\n\n";
				continue;
			}
			
			if (elist[indexe]->allocateCabin(clist[indexc]))
				cout << "\nCabin Re-Allocated Successfully";
		}


		if (n == 5)
		{
			Employee* obj;
			int indexc;
			bool state = false;

			int idc;
			cout << "\nEnter Id of Cabin: ";
			cin >> idc;
			for (int i = 0; i < cabinCount; i++)
				if (idc == clist[i]->getCabinID())
				{
					indexc = i;
					state = true;
				}
			if (state == false)
			{
				cout << "\nID not Found\n\n";
				continue;
			}


			obj=clist[indexc]->getEmployee();
			if(obj->getEmpCabin()!=NULL)
    			obj->setEmpCabin(NULL);

			if(clist[indexc]->getEmployee()!=NULL)
			    clist[indexc]->setEmployee(NULL);

			cout << "\nCabin is Free Now";
		}


		if (n == 6)
		{
			int indexe;
			bool state = false;


			int ide;
			cout << "\nEnter Id of Employee: ";
			cin >> ide;
			for (int i = 0; i < empCount; i++)
				if (ide == elist[i]->getEmpID())
				{
					indexe = i;
					state = true;
				}
			if (state == false)
			{
				cout << "\nID not Found\n\n";
				continue;
			}


			elist[indexe]->print();
		}

		if (n == 7)
		{
			int indexc;
			bool state = false;

			int idc;
			cout << "\nEnter Id of Cabin: ";
			cin >> idc;
			for (int i = 0; i < cabinCount; i++)
				if (idc == clist[i]->getCabinID())
				{
					indexc = i;
					state = true;
				}
			if (state == false)
			{
				cout << "\nID not Found\n\n";
				continue;
			}

			clist[indexc]->print();
		}

		if (n == 8)
		{
			break;
		}

		cout << endl<<endl;
	}
}