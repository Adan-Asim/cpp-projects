#include<iostream>
#include<string>
#include"CharString.h"
using namespace std;


void Display(CharString o)                //Global Function only created for checking purpose; not required
{
	cout << "String: ";
	o.print();
	cout << "\nSize: " << o.getSize();
	cout << endl << endl;
}

int main()
{
	CharString obj;                                             
	Display(obj);                                                //Checks Default Constructor        

	char sample[] = { 'a','b','c','d','e','f','g','s','s' ,'\0' };
	CharString obj2(sample);                                     //Checks Char Array arguments Constructor
	Display(obj2); 

	CharString obj3;
	obj3.reset();                                                //Checks Reset Function
	Display(obj3);

	CharString obj4("test");                                     //Checks String arguments Constructor
	string test = "lmnopq";
	Display(obj4);

	CharString obj5(obj4);                                       //Checks CharString argument Constructor
	Display(obj5);

	obj5.reset();                                                //to reset object for reuse
	Display(obj5);

	obj5 = sample;                                               //Checks String Assignement operator
	Display(obj5);

	char temp[] = { 'v','w','x','y','z','\0' };
	obj5.copyFrom(temp, 6,2);                                    //Checks Copyfrom func for char arguments 
	Display(obj5);

	obj3.copyFrom(obj5, 5, 2);                                   //Checks Copyfrom func for CharString arguments
	Display(obj3);

	obj2 = obj5;                                                 //Checks CharString assignment operator
	Display(obj2);

	obj5.clear();                                                //Checks Clear Function
	Display(obj5);

	obj5 = test;                                                  
	Display(obj5);

	obj5.copyFrom(test, 2, 1);                                    //Checks Copyfrom for String arguments
	Display(obj5);

	char someString[] = "+Concatenated";
	CharString obj6("Char is");
	obj6.concat(someString);                                     //Checks Concat func for Char Array arguments
	Display(obj6);

	string something = "+Concatenated Successfully";
	obj3.concat(something);                                       //Checks Concat func for String arguments
	Display(obj3);

	obj5.concat(obj3);                                            //Checks Concat func for CharString obj argument
	Display(obj5);

	char c[] = "Checking operator + overloaded for char";
	CharString obj8 = obj6 + c;                                  //Checks overloaded + for Char Array argument
	Display(obj8);
	
	string s = "Checking operator + overloaded for string";
	obj8 = obj6 + s;                                             //Checks overloaded + for String argument
	Display(obj8);

	obj6 = "Checking Operator + ";
	obj8.clear();
	obj8 = "For CharString";
	CharString obj9 = obj6 + obj8;                               //Checks overloaded + for CharString Argument
	Display(obj9);

	char cc[]= "Checking Equality";
	obj8 =     "Checking Equality" ;                            
	if (obj8 == cc)                                               //Checks overloaded == for Char Array
		cout << "\nYes, given Array and obj are Equal\n";
	else
		cout << "\nNo, given Array and obj are not Equal\n";

	string ss = "Checking Not Equality";
	if (obj8 == ss)                                               //Checks overloaded == for String
		cout << "\nYes, given String and obj are Equal\n\n";
	else
		cout << "\nNo, given String and obj are not Equal\n\n";

	obj3 = "Checking Equality";
	if (obj8 == obj3)                                             //Checks overloaded == for CharString
		cout << "\nYes, given obj and other obj are Equal\n\n";
	else
		cout << "\nNo, given obj and other obj are not Equal\n\n";

	obj8 = "desreveR";
	CharString obj10 = obj8.Reverse();                            //Checks Reverse Function
	Display(obj10);

	obj10 = obj3.Substring(5, 15);                                //Checks Substring Function
	Display(obj10);

	char get;
	get = obj3.At(9);                                             //Checks At Function
	cout << "Chracter: " << get<<endl;
	return 0;
}
