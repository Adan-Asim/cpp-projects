#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>

using namespace std;
void first();
void second();
void third();
void fourth();
void fifth();
void sixth();
void seventh();
void eight();


struct account
{
   int code;
   string name;
   char type;
   int amount;	
};

void intro()
{
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t ================================\n\n";
	cout<<"\t\t\t    BANK\n\n";
	cout<<"\t\t\t MANAGEMENT\n\n";
	cout<<"\t\t\t   SYSTEM\n";
	cout<<"\n\t\t =================================";
	getch();
}

void mainPage()
{
	system("cls");
	cout<<"\n\n\n\n";
	cout<<"\t    MAIN MENU\n";
	cout<<"\t   -----------\n\n";
	string s[10]={"New Account", "Deposit Amount", "Withdraw Amount", "Balance Inquiry", "All Account Holders Details", "Close an Account", "Modify an Account", "Exit"};
	for(int i=0;i<8;i++)
	   cout<<"\t"<<i+1<<". "<<s[i]<<endl<<endl;
}





int main()
{
	try
	{
		int op;
		intro();
		jump:
		mainPage();
		cout<<"\n\tSelect an Option <1-8>: ";
		cin>>op;
		switch(op)
		 {
		  case 1:	
		    first();
		    break;
		  case 2:
		    second();
		    break;
		  case 3:
		    third();
		    break;
		  case 4:
		    fourth();
		    break;
		  case 5:
		    fifth();
		    break;
		  case 6:
		    sixth();
	    	break;
		  case 7:
		    seventh();
	    	break;
		  case 8:
	    	goto end;
		  break;
      	  }
        goto jump;
		end:
		cout<<"\n\n";	
		return 0;
    }
    catch(exception e)
    {
    	cout<<"\n\n\n\t\tWRONG INPUT";
    	return 0;
	}    
}



void first()
{
	system("cls");
	cout<<"\n\n\t\t\t\t ~~~ NEW ACCOUNT ~~~\n";
	account temp;
	cout<<"\n\n\n\t\t Enter Account Number: ";
	cin>>temp.code;
	cout<<"\n\t\t Enter the Name of Account Holder: ";
	cin>>temp.name;
	cout<<"\n\t\t Enter Account Type (C/S): ";
	cin>>temp.type;
	cout<<"\n\t\t Enter Intial Amount: ";
	cin>>temp.amount;
	cout<<"\n\n\n\t\t Your Account Created Sucessfully";
	
	ofstream file("data.txt",ios::app);
	file<<endl;
	file<<setw(4)<<temp.code<<" ";
	file<<setw(10)<<temp.name<<" ";
	file<<setw(1)<<temp.type<<" ";
	file<<setw(8)<<temp.amount;
	file.close();
	getch();
}



void second()
{
	system("cls");
	cout<<"\n\n\t\t\t\t ~~~ DEPOSIT AMOUNT ~~~\n";
	int n,deposit;
	account temp;
	cout<<"\n\n\n\t\t Enter Account Number: ";
	cin>>n;
	
	fstream file("data.txt");
	for(int i=0;!file.eof();i++)
	{
	 file>>temp.code;
	 file>>temp.name;
	 file>>temp.type;
	 file>>temp.amount;
	 if(temp.code==n)
	   {
	   	cout<<"\n\n\t\t         ACCOUNT STATUS";
	   	cout<<"\n\n\t\t Account Number: "<<temp.code;
	   	cout<<"\n\n\t\t Account Holder Name: "<<temp.name;
	   	cout<<"\n\n\t\t Account Type: "<<temp.type;
	   	cout<<"\n\n\t\t Amount Present: "<<temp.amount;
	   	
	   	cout<<"\n\n\n\n\t\t Enter Amount To Deposit: ";
	   	cin>>deposit;
	   	file.seekg(-8,ios::cur);
	   	file<<setw(5)<<(temp.amount+deposit)<<endl;
	   	cout<<"\n\n\t\t Your Amount Deposited Sucessfully";
	    break;
	   } 
      }
      file.close();
	 getch();	    
}



void third()
{
	system("cls");
	cout<<"\n\n\t\t\t\t ~~~ WITHDRAW AMOUNT ~~~\n";
	int n,with;
	account temp;
	cout<<"\n\n\n\t\t Enter Account Number: ";
	cin>>n;
	
	fstream file("data.txt");
	for(int i=0;!file.eof();i++)
	{
	 file>>temp.code;
	 file>>temp.name;
	 file>>temp.type;
	 file>>temp.amount;
	 if(temp.code==n)
	   {
	   	cout<<"\n\n\t\t         ACCOUNT STATUS";
	   	cout<<"\n\n\t\t Account Number: "<<temp.code;
	   	cout<<"\n\n\t\t Account Holder Name: "<<temp.name;
	   	cout<<"\n\n\t\t Account Type: "<<temp.type;
	   	cout<<"\n\n\t\t Amount Present: "<<temp.amount;
	   	
	   	cout<<"\n\n\n\n\t\t Enter Amount To Withdraw: ";
	   	cin>>with;
	   	if(temp.amount>=with)
	   	{
	   		file.seekg(-8,ios::cur);
	   		file<<setw(5)<<(temp.amount-with)<<endl;
	   		cout<<"\n\n\t\t Your Amount Withdrawn Sucessfully";
	    	break;
		}
		else
		{
			cout<<"\n\n\n\n\t\tACCOUNT HAS INSUFFICIENT AMOUNT";
			break;
		}
	   } 
      }
      file.close();
	 getch();
}



void fourth()
{
	system("cls");
	cout<<"\n\n\t\t\t\t ~~~ BALANCE INQUIRY ~~~\n";
	int n,deposit;
	account temp;
	cout<<"\n\n\n\t\t Enter Account Number: ";
	cin>>n;
	
	fstream file("data.txt");
	for(int i=0;!file.eof();i++)
	{
	 file>>temp.code;
	 file>>temp.name;
	 file>>temp.type;
	 file>>temp.amount;
	 if(temp.code==n)
	   {
	   	cout<<"\n\n\t\t         ACCOUNT STATUS";
	   	cout<<"\n\n\t\t Account Number: "<<temp.code;
	   	cout<<"\n\n\t\t Account Holder Name: "<<temp.name;
	   	cout<<"\n\n\t\t Account Type: "<<temp.type;
	   	cout<<"\n\n\t\t Amount Present: "<<temp.amount;
	   	break;
	   }
    }
    file.close();
    getch();
}



void fifth()
{
	system("cls");
	account temp;
	cout<<"\n\n\t\t\t ~~~ ALL ACCOUNT HOLDER DETAILS ~~~\n\n";
	cout<<"     *****************************************************************************\n";
	cout<<"         A\C No.\t\t  NAME \t\t\t TYPE\t\t BALANCE\n";
	cout<<"     ******************************************************************************\n";
	
	fstream file("data.txt");
	for(int i=0;!file.eof();i++)
	{	
	 file>>temp.code;
	 file>>temp.name;
	 file>>temp.type;
	 file>>temp.amount;
	 
	 cout<<" \t "<< temp.code<<"\t\t "<<temp.name<<"\t\t\t "<<temp.type<<"\t\t "<<temp.amount<<endl;
	}
	file.close();
	cout<<"\n\n\t Press any key to go back";
	getch();
}



void sixth()
{
  	system("cls");
	cout<<"\n\n\t\t\t\t ~~~  DELETE AN ACCOUNT  ~~~\n";
	int n;
	account temp;
	cout<<"\n\n\n\t\t Enter Account Number: ";
	cin>>n;	
	
	ifstream file("data.txt");
	ofstream temporary("t.txt");
	for(int i=0;!file.eof();i++)
	{
	 file>>temp.code;
	 file>>temp.name;
	 file>>temp.type;
	 file>>temp.amount;
	 
	 if(temp.code==n)
	    continue;
	 temporary<<endl;
	 temporary<<setw(4)<<temp.code<<" ";
	 temporary<<setw(10)<<temp.name<<" ";
	 temporary<<setw(1)<<temp.type<<" ";
	 temporary<<setw(8)<<temp.amount;
    }
    file.close();
    temporary.close();
    cout<<"\n\n\t\t Account Deleted Sucessfully";
    system("del data.txt");
    system("ren t.txt data.txt");
	getch();	
}



void seventh()
{
  	system("cls");
	cout<<"\n\n\t\t\t\t ~~~  MODIFY ACCOUNT  ~~~\n";
	int n;
	account temp1, temp2;
	cout<<"\n\n\n\t\t Enter Account Number: ";
	cin>>n;
	
	fstream file("data.txt");
	for(int i=0;!file.eof();i++)
	{
	 file>>temp1.code;
	 file>>temp1.name;
	 file>>temp1.type;
	 file>>temp1.amount;
	 if(temp1.code==n)
	   {
	   	cout<<"\n\n\t\t         ACCOUNT CURRENT STATUS";
	   	cout<<"\n\n\t\t Account Number: "<<temp1.code;
	   	cout<<"\n\n\t\t Account Holder Name: "<<temp1.name;
	   	cout<<"\n\n\t\t Account Type: "<<temp1.type;
	   	cout<<"\n\n\t\t Amount Present: "<<temp1.amount;
	   	
	   	
	   	
	   	cout<<"\n\n\t\t         ENTER NEW DETAILS";
	   	cout<<"\n\n\t\t Account Number: ";
		cin>>temp2.code;
	   	cout<<"\n\t\t Account Holder Name: ";
		cin>>temp2.name;
	   	cout<<"\n\t\t Account Type: ";
		cin>>temp2.type;
	   	cout<<"\n\t\t Amount Present: ";
	    cin>>temp2.amount;
	    
	    file.seekg(-27,ios::cur);
	    file<<endl;
	   	file<<setw(4)<<temp2.code<<" ";
	    file<<setw(10)<<temp2.name<<" ";
	    file<<setw(1)<<temp2.type<<" ";
	    file<<setw(8)<<temp2.amount;
	    file.close();
	   	
	   	cout<<"\n\n\t\t Your Amount Updated Sucessfully";
	    break;
	   } 
      }
     file.close();
	 getch();
	
}


//   End of Code

