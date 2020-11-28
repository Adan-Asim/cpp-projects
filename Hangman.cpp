#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
bool checkAndReplace(char c, char *w,string word);

void mainPage()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t    *****************************************\n";
	cout<<"\t\t\t\t    *                                       *\n";
	cout<<"\t\t\t\t    *               HANGMAN                 *\n";
	cout<<"\t\t\t\t    *                                       *\n";
	cout<<"\t\t\t\t    *****************************************\n";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	getch();
}

void header()
{
	system("cls");
	cout<<"\n\t\t\t\t\t\t ***HANGMAN***";
}

void stateShow(char *w)
{
	cout<<"\n\n\n\t\t\t\t |----------------------------------------------|\n";
	cout<<"\t\t\t\t\t\t";
	for(int i=0;w[i]!='\0';i++)
	cout<<w[i]<<" ";
	cout<<"\t\t\t\n";
	cout<<"\t\t\t\t |----------------------------------------------|\n";	
}

void figure(int n)
{
	cout<<"\n\t\t\t\t\t\t   ___";
	for(int i=1;i<=n+1;i++)
	   switch(i)
	   {
	   	case 1:
	   		cout<<"\n\t\t\t\t\t\t  |";
	   		break;
	   	case 2:
	   	    cout<<"\n\t\t\t\t\t\t  O";
	   	    break;
	   	case 3:
	   		cout<<"\n\t\t\t\t\t\t__";
	   		break;	   	    
		case 4:
		    cout<<"|";
	   		break;	
	   	case 5:
	   		cout<<"__";
	   		break;	
	   	case 6:
	   		cout<<"\n\t\t\t\t\t\t  |";
	   		break;	
		case 7:
	   		cout<<"\n\t\t\t\t\t\t /";
	   		break;   		
	   	case 8:
	   		cout<<" \\";
	   		break;	   		
	   }
}

char *inputWord(string &word)
{
	header();
	cout<<"\n\n\n\n\n\t\t Enter Word to be Guessed : ";
	cin>>word;
	int lenght=0;
	for(int i=0;word[i]!='\0';i++)
	   lenght++;
    char *w=new char[lenght];
    
	for(int i=0;i<lenght;i++)
	    w[i]='_';
    return w;
}

void inputChar(int n, char *w,string word)
{
	header();
	stateShow(w);
	char c;
	cout<<"\n\n\t\t\t\t\t   <You have "<<8-n<<" Chances left>";
	cout<<"\n\n\t\t Guess the Chracter: ";
	cin>>c;
	if(checkAndReplace(c,w,word))
	   cout<<"\n\n\n\t\t Right Guess ";
	else
	   cout<<"\n\n\n\t\t Wrong Guess ";
	figure(n);      
	
}

bool checkAndReplace(char c, char *w,string word)
{
	bool test=0;
	for(int i=0;w[i]!='\0';i++)
		if(word[i]==c && w[i]!=c)
		    {
			 w[i]=c;
			 test=1;
		    }
    return test;	
}


int main()
{
	mainPage();
	
	string word;
	char *w;
	w=inputWord(word);
	
	for(int i=0;i<8;i++)
	   {
	    inputChar(i,w,word);
		getch();	
        if(w==word)
            break;   
	   }
       
    if(w==word)
        {
		 cout<<"\n\n\n\t\t\t\tCONGRATULATIONS: You WON the Game";
	     cout<<"(WORD: "<<word<<")";
	    }
	else	   	     
        {
		 cout<<"\n\n\n\t\t\t\t\tYou LOST the Game";
         cout<<"(WORD: "<<word<<")";
        }
	cout<<"\n\n\n\n";
    return 0;
}


// End Of Code

