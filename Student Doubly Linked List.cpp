#include<iostream>
#include<string>
using namespace std;

class Student
{
	friend class StudentList;
private:
	int id; //id of a student.
	string name; //name of a student.
	float cgpa; //cgpa of a student.
	Student* next; //address of the next available listect.
	Student* prev; //address of the previous available listect.
public:
	Student(int id, string name, float cgpa, Student* next, Student* prev) //constructor
	{
		this->id=id; 
		this->name=name; 
		this->cgpa=cgpa; 
		this->next=next; 
		this->prev=prev;
	}

	void show()
	{
		cout <<"Id: "<< id << endl;
		cout << "Name: "<<name << endl;
		cout << "cgpa: "<< cgpa << endl;
		cout << endl;
	}
};


class StudentList
{
private:
	Student* head; //start of the list
	Student* cursor; //current item of the list
	Student* last; //last item of the list
public:
	StudentList() //default constructor
	{
		head = NULL;
		cursor = NULL;
		last = NULL;
	}

	~StudentList() //destructor
	{
		if (head == NULL && last == NULL && cursor == NULL)
		{
			delete head;
			delete last;
			delete cursor;
		}
		
		else if(head==last)
		{
			delete head;
		}

		else
		{
			Student *current = head;
			while (current != NULL)
			{
				cursor = current;
				current = current->next;
				delete cursor;
			}
			if(current!=NULL)
			delete current;
		}
	}

	void insert(const Student& newStd)
	{
		if (head == NULL)
		{
			Student* temp = new Student(newStd.id, newStd.name, newStd.cgpa, NULL, NULL);
			head = temp;
			cursor = temp;
			last = temp;
		}
		else
		{
			Student* temp = new Student(newStd.id, newStd.name, newStd.cgpa, cursor->next, cursor);
			if (cursor != last)
				cursor->next->prev = temp;
			cursor->next = temp;
			if (cursor == last)
				last = temp;
			cursor = temp;

		}
	}

	void remove(int id)
	{
		Student* current = head;
		while (current->id != id && current!=last)
			current = current->next;
		
		if (current->id != id)
			cout << "\nGIVEN ID NOT FOUND\n";
		else
		{
			if (current == head && current == last)
			{
				head = NULL;
				last = NULL;
				cursor = NULL;
			}
			else
			{
				if (current != head)
					current->prev->next = current->next;
				if (current != last)
					current->next->prev = current->prev;
				if (current == head)
					head = current->next;
				else if (current == last)
					last = current->prev;
			}
			

			if (cursor == current)
			{
				if (cursor != last)
					gotoNext();
				else
					gotoBeginning();
			}

			delete current;
		}
	}

	void search(float cgpa)
	{
		Student* current = head;
		while (current->cgpa != cgpa && current != last)
			current = current->next;

		if (current->cgpa != cgpa)
			cout << "\nNOBODY HAS OBTAINED GIVEN CGPA\n";
		else
			current->show();
	}

	void replace(const Student& newStd)
	{
		
		Student* current = head;
		while (current->id != newStd.id && current != last)
			current = current->next;

		if (current->id != newStd.id)
		{
			cursor = last;
			insert(newStd);
		}
		else
		{
			cursor = current;
			insert(newStd);
			remove(newStd.id);
		}
	}

	bool isEmpty() const
	{
		if (head == NULL)
			return true;
		return false;
	}

	void gotoBeginning()
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return;
		}
		cursor = head;
	}

	void gotoEnd()
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return;
		}
		cursor = last;
	}

	bool gotoNext()
	{

		if (isEmpty())
		{
			cout << "List is Empty\n";
			return false;
		}
		else if (cursor != last)
		{
			cursor = cursor->next;
			return true; 
		}
		return false;
	}

	bool gotoPrior()
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return false;
		}
		else if (cursor != head)
		{
			cursor = cursor->prev;
			return true;
		}
		return false;
	}

	Student getCursor()
	{
		if (!isEmpty())
			return *cursor;
	}
		
	void showStructureForward() const
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return;
		}
		else
		{
			Student* current = head;
			while (current != NULL)
			{
				current->show();
				current = current->next;
			}
		}
	}

	void showStructureReverse() const
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return;
		}
		else
		{
			Student* current = last;
			while (current!=NULL)
			{
				current->show();
				current = current->prev;
			}
		}
	}
};

int main()
{
	StudentList list;
	Student one(1, "Ali", 3, NULL, NULL);
	Student two(2, "Ahmad", 3.5, NULL, NULL);
	Student three(3, "Farhan", 2.8, NULL, NULL);
	Student four(4, "Hafeez", 3.3, NULL, NULL);
	Student five(3, "Taha", 3.6, NULL, NULL);
	Student six(5, "Abid", 3.4, NULL, NULL);

	cout << "INSERTING RECORD AT END\n";
	list.insert(one);
	list.insert(two);
	list.insert(three);
	list.showStructureForward();

	cout << "\nINSERTING RECORD AFTER SECOND RECORD\n";
	list.gotoPrior();
	list.insert(four);
	list.showStructureForward();

	cout << "\nREMOVING NODE HAVING ID=3 \n";
	list.remove(3);
	list.showStructureForward();

	cout << "\nAGAIN INSERTING RECORD AT END\n";
	list.gotoEnd();
	list.insert(three);
	list.showStructureForward();

	cout << "\nDISPLAYING RECORD IN REVERSE\n";
	list.showStructureReverse();

	cout << "\nSEARCHING FOR RECORD HAVING 3.5 CGPA\n";
	list.search(3.5);

	cout << "\nCHECKING MOVEMENT OF CURSORS\n";
	cout << "Current Position of Cursor\n";
	cout << "Cursor is at: \n";
	list.getCursor().show();
	cout << "Testing gotoBeginning function\n";
	list.gotoBeginning();
	cout << "Now Cursor is at: \n";
	list.getCursor().show();
	cout << "Testing gotoEnd function\n";
	list.gotoEnd();
	cout << "Now Cursor is at: \n";
	list.getCursor().show();
	cout << "Testing gotoPrior function\n";
	list.gotoPrior();
	cout << "Now Cursor is at: \n";
	list.getCursor().show();
	cout << "Testing gotoNext function\n";
	list.gotoNext();
	cout << "Now Cursor is at: \n";
	list.getCursor().show();

	cout << "\nCHECKING REPLACE FUNCTION\n";
	cout << "List Before Replacing:\n";
	list.showStructureForward();
	cout << "List After Replacing student three with five i.e id = 3\n";
	list.replace(five);
	list.showStructureForward();
	cout << "List After Replacing a student with having a new id i.e not present in list\n";
	list.replace(six);
	list.showStructureForward();

	cout << "\nCHECKING REMOVE FUNCTION\n";
	cout << "Removing id = 1, 2, 3\n";
	list.remove(1);
	list.remove(2);
	list.remove(3);
	list.showStructureForward();
	cout << "Inserting id = 3 again for testing\n";
	list.insert(three);
	list.showStructureForward();
	cout << "Again Replacing three with five i.e id = 3 for testing\n";
	list.replace(five);
	list.showStructureForward();
	cout << "Removing id = 3 for testing\n";
	list.remove(3);
	list.showStructureForward();

	cout << "\nRemoving remaining nodes too\n";
	list.remove(4);
	list.remove(5);
	list.showStructureForward();
	cout << "PROGRAM TERMINATED SUCCESSFULLY\n";
}
