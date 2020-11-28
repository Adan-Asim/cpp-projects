#include<iostream>
#include<iomanip>
using namespace std;

void print(char c[],int s)
{
	system("cls");
	cout<<"\n\t\tTIC TAC TOE"<<endl;
	cout<<"\tPlayer 1(X)  -  Player 2(O)"<<endl<<endl;
	for(int i=0;i<s;i++)
	    {
	     for(int j=0;j<s;j++)
	       {
		    cout<<"\t"<<setw(4)<<c[i*s+j];
	        cout<<"|";
	       }
	     cout<<endl;
		 if(i+1!=s)
		    cout<<"\t ___|_______|_______|_";
		 cout<<endl;
	    }	       
}

void fill(char c[],char n, int s, char type)
{
	for(int i=0;i<s;i++)
	    if(c[i]==n)
	      c[i]=type; 
	
}

bool check(char c[],int s,char type)
{
	for(int i=0;i<s;i+=3)
	   {
	    if(c[i]==type && c[i+1]==type && c[i+2]==type)
            return true;
	    else if(c[i]==type && c[i+3]==type && c[6+i]==type)
            return true;
        }
        
        if(c[0]==type && c[4]==type && c[8]==type)
            return true;
        else if(c[2]==type && c[4]==type  && c[6]==type) 
	          return true;
	return false;	 
}


int main()
{
	char n;
	char c[9]={'1','2','3','4','5','6','7','8','9'};
	for(int i=0;;i++)
	   {
	    print(c,3);
		cout<<" Player 1, Enter a Number: ";
	    cin>>n;
	    fill(c,n,9,'X');
	    
	    print(c,3);
	    if(check(c,9,'X'))
	        {
	        	cout<<"Player 1 Won";
	        	break;
			}
	    
		cout<<" Player 2, Enter a Number: ";
	    cin>>n;
	    fill(c,n,9,'O');
	    
	    print(c,3);
	    if(check(c,9,'O'))
	        {
	        	cout<<"Player 2 Won";
	        	break;
			}
		if(!check(c,9,'X') && !check(c,9,'O'))
		        cout<<"Game Drawn";	
		 
	   }
	return 0;   	   

}
