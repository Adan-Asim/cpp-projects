#include<iostream>
#include<conio.h>
using namespace std;

class Book
{
	friend class BookList;
private:
	int id; //id of a book.
	string title; //name of a book.
	float price; //price of a book.
	Book* next; //address of the next available object.
public:
	Book(int id, string title, float price, Book* next) //parameterized constructor
	{
		this->id = id;
		this->title = title;
		this->price=price;
		this->next = next;
	}
	void show()
	{
		cout << "\nId: " << id << endl;
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
		cout << endl;
	}
};

class BookList
{
private:
	Book* head; //start of the list
	Book* cursor; //current item of the list
public:
	BookList() //default constructor
	{
		head = NULL;
		cursor = NULL;
	}
	~BookList() //destructor
	{
		if (head == NULL && cursor == NULL)
		{
			delete head;
			delete cursor;
		}
		else
		{
			Book *current=head;
			gotoBeginning();
			while (current != NULL)
			{
				current = cursor->next;
				delete cursor;
				cursor = current;
			}
			delete cursor;
		}
	}

	void insert(const Book& newItem)
	{
		if (isEmpty())
		{
			Book* temp = new Book(newItem.id, newItem.title, newItem.price, NULL);
			head = temp;
			cursor = temp;
		}
		else
		{
			Book* temp = new Book(newItem.id, newItem.title, newItem.price, cursor->next);
			cursor->next = temp;
			cursor = temp;
		}
	}

	bool isEmpty() const
	{
		if (head == NULL)
			return true;
		return false;
	}

	void showStructure() 
	{
		if (isEmpty())
			cout << "List is Empty\n";
		else
		{
			Book *current = head;
			while (current != NULL)
			{
				current->show();
				current = current->next;
			}
		}
	}

	void remove()
	{
		if (isEmpty())
			cout << "List is Empty\n";

		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
			cursor = NULL;
		}

		else if (cursor == head)
		{
			head = head->next;
			delete cursor;
			cursor = head;
		}

		else
		{
			Book *current = head;
			while (current->next!=cursor)
				current = current->next;
			
			current->next = cursor->next;
			delete cursor;
			if (current->next != NULL)
				cursor = current->next;
			else
				cursor = head;
		}
	}

	void search(string title) const
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return;
		}

		Book* current = head;
		while (current->title != title && current->next!=NULL)
			current = current->next;

		if (current->title == title)
		{
			cout << "Found Item: \n";
			current->show();
		}
		else 
			cout << "Item Not Found\n";
	}

	void replace(const Book& newItem)
	{
		if (isEmpty())
			cout << "List is Empty\n";
		else if(head==cursor)
		{
			Book* temp = new Book(newItem);
			temp->next = head->next;
			head = temp;
			delete cursor;
			cursor = head;
		}
		else
		{
			Book* current = head;
			while (current->next != cursor)
				current = current->next;

			Book* temp = new Book(newItem);
			temp->next = cursor->next;
			current->next = temp;
			delete cursor;
			cursor = current->next;
		}
	}

	Book getCursor()
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			Book *temp=NULL;
			return *temp;
		}
		return *cursor;
	}

	void gotoBeginning()
	{
		if (isEmpty())
			cout << "List is Empty\n";
		else
			cursor = head;
	}

	void gotoEnd()
	{
		if (isEmpty())
			cout << "List is Empty\n";
		else
			while (cursor->next != NULL)
				cursor = cursor->next;
	}

	bool gotoNext()
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return false;
		}
		else if (cursor->next == NULL)
			return false;
		else
			cursor = cursor->next;
		return true;
	}

	bool gotoPrior()
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return false;
		}
		else if (cursor->next == head)
			return false;
		else
		{
			Book *current=head;
			while (current->next != cursor)
				current = current->next;
			cursor = current;
		}
		return true;
	}

};



int main()
{
	BookList list;
	Book B1(1, "One", 50, NULL);
	Book B2(2, "Two", 80, NULL);
	Book B3(3, "Three", 60, NULL);
	Book B4(4, "Four", 75, NULL);
	Book B5(5, "Five", 90, NULL);
	Book B6(6, "Six", 55, NULL);
	Book B7(7, "Seven", 65, NULL);
	Book B8(8, "Eight", 80, NULL);

	cout << "CHECKING INSERT FUNCTIONS\n";
	cout << "After Inserting First book\n";
	list.insert(B1);
	list.showStructure();

	cout << "Inserting two Books at last\n";
	list.insert(B2);
	list.insert(B3);
	list.showStructure();

	cout << "Inserting one more Book after Second book\n";
	list.gotoPrior();
	list.insert(B4);
	list.showStructure();


	cout << "\n\nNOW CHECKING REPLACE FUNCTION\n";
	cout << "Replacing First Item in the List\n";
	list.gotoBeginning();
	list.replace(B5);
	list.showStructure();
	cout << "Replacing Last Item in the List\n";
	list.gotoEnd();
	list.replace(B6);
	list.showStructure();
	cout << "Replacing Second Item in the List\n";
	list.gotoPrior();
	list.gotoPrior();
	cout << "\nCursor is at:";
	list.getCursor().show();
	cout << endl;
	list.replace(B7);
	list.showStructure();

	cout << "\nNOW CHECKING SEARCH FUNCTION\n";
	int o = 0;
	do
	{
		cout << "\nEnter the Title of book you want to search: ";
		string str;
		cin >> str;
		list.search(str);
		cout << "\nEnter 1 to search another book and 0 for not: ";
		o=_getche();
	} while (o=='1');


	cout << "\n\nNOW CHECKING MOVEMENT OF CURSOR\n";
	cout << "\nPresent List:\n";
	list.showStructure();
	cout << "\nCurrent Position of Cursor\n";
	cout << "Cursor is at: ";
	list.getCursor().show();

	cout << "Testing gotoEnd function\n";
	list.gotoEnd();
	cout << "Now Cursor is at: ";
	list.getCursor().show();

	cout << "Testing gotoBeginning function\n";
	list.gotoBeginning();
	cout << "Now Cursor is at: ";
	list.getCursor().show();

	cout << "Testing gotoNext function\n";
	list.gotoNext();
	cout << "Now Cursor is at: ";
	list.getCursor().show();

	cout << "Testing gotoPrior function\n";
	list.gotoPrior();
	cout << "Now Cursor is at: ";
	list.getCursor().show();
	

	cout << "NOW CHECKING REMOVE FUNCTION\n";
	cout << "Removing Item at which cursor is present\n";
	cout << "\nCursor is at:";
	list.getCursor().show();
	cout << endl;
	list.remove();
	list.showStructure();

	cout << "Removing Item at End\n";
	list.gotoEnd();
	list.remove();
	list.showStructure();

	cout << "Removing Item at Beginning\n";
	list.gotoBeginning();
	list.remove();
	list.showStructure();

	cout << "\nPROGRAM ENDED SUCCESSFULLY\n";
}