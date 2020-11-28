#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cmath>
using namespace std;

void mainPage()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t    ***********************************************\n";
	cout<<"\t\t\t\t    *                                             *\n";                     
	cout<<"\t\t\t\t    *                  PUCIT                      *\n";
	cout<<"\t\t\t\t    *                                             *\n";
	cout<<"\t\t\t\t    *                   GPA                       *\n";
	cout<<"\t\t\t\t    *                                             *\n";
	cout<<"\t\t\t\t    *                CALCULATOR                   *\n";
	cout<<"\t\t\t\t    *                                             *\n";
	cout<<"\t\t\t\t    ***********************************************\n";
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	getch();
}

void header()
{
	system("cls");
	cout<<"\n\t\t\t\t\t     ~~~PUCIT GPA CALCULATOR~~~ ";
}

double calculateGpa(int n,double *gp,int *c)
{
	double sum_marks=0,sum_hours=0;
	for(int i=0;i<n;i++)
	   {
	  	sum_marks+=(gp[i]*c[i]);
	  	sum_hours+=c[i];
	   }   
	return sum_marks/sum_hours;   
	  
}

void convertIntoGP(double &gp,int marks)
{
	if (marks>=85)
	   gp=4;
	else if (marks>=80)
	   gp=3.7;
	else if (marks>=75)
	   gp=3.3;
	else if (marks>=70)
	   gp=3;
	else if (marks>=65)
	   gp=2.7;
	else if (marks>=61)
	   gp=2.3;
	else if (marks>=58)
	   gp=2;
	else if (marks>=55)
	   gp=1.7;
	else if (marks>=50)
	   gp=1;  
	else 
	   gp=0;             		               
}

int main()
{
	mainPage();
	
	header();
	int n,marks,*credit_hours;
	double *grade_points;
    cout<<"\n\n\t\t Enter Number of Subjects: ";
	cin>>n;
	
	grade_points=new double[n];
	credit_hours=new int[n];
	for(int i=0;i<n;i++)
	   {
	   	cout<<"\n\n\t\t Enter Marks in subject "<<i+1<<": ";
	   	cin>>marks;
	   	convertIntoGP(grade_points[i],marks);
	   	
	   	cout<<"\t\t Enter Credit Hours of subject "<<i+1<<": ";
	   	cin>>credit_hours[i];
	   }
	
	header();
	float gpa;
	gpa=calculateGpa(n, grade_points, credit_hours);
	cout<<"\n\n\n\t\t Your GPA in this Semester is: ";
	printf("%1.2f",gpa); 
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  
	
	return 0;
}

// End of Code
