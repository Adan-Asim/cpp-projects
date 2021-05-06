#include<iostream>
#include<queue>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

struct processInfo
{
	string processName;
	int executionTime;
	int arrivalTime;
};

void oneTimeUnit()
{
	for (int i = 0; i < 10000; i++);
}

int ArrivalTimeGlobal = 0;

int readFile(queue<processInfo>& dummy)
{
	int added = 0;
	ifstream input("readylist.txt");
	if (!input)
	{
		cout << "File not Found\n ";
		exit(1);
	}
	cout << "\n\nThe Contents of Ready Queue are: \n";
	while (!input.eof())
	{
		
		string s;
		int n;
		processInfo temp;

		input >> s;
		input >> n;
		if (n > 0 && n < 10000000)   //To check, if it is not a garbage value then it should proceed
		{
			temp.processName = s;
			temp.executionTime = n;
			temp.arrivalTime = ArrivalTimeGlobal;
			dummy.push(temp);
			added++;
		}
	}
	queue<processInfo> t=dummy;
	for (int i = 0; i < dummy.size(); i++)
	{
		cout <<"-> "<<t.front().processName << " "  <<t.front().executionTime << endl;
		t.pop();
	}
	input.close();
	ofstream output("readylist.txt");
	output.close();

	return added;
}

int main()
{
	cout << "\t\t\t\t\t***WELCOME TO SIMULATED CPU SCHEDULER***\n";

	queue<processInfo> readyQueue;
	readFile(readyQueue);
	cout << "\n(Now Executing Processes)\n";

	int waitingTime=0;
	int turnaroundTime = 0;
	int noOfElements = readyQueue.size();
	
	int sumofWaitingTime = 0;
	int sumofTurnaroundTime = 0;
	int noOfTimeUnitsExecuted=0;

	for (int i = 0; i < noOfElements ; i++)
	{ 
		for (int j = 0; j < readyQueue.front().executionTime; j++)
		{
			oneTimeUnit();
			noOfTimeUnitsExecuted++;
	        if ((noOfTimeUnitsExecuted % 20)==0)
		    {
				ArrivalTimeGlobal+=20;
				cout << endl;
				system("pause");
			    noOfElements += readFile(readyQueue);
		     }
		}
        
		cout << "\n\nFollowing process has Finished Execution\n";
		turnaroundTime += readyQueue.front().executionTime;

		cout << readyQueue.front().processName << " " << readyQueue.front().executionTime;
		cout<<" "<<waitingTime - readyQueue.front().arrivalTime<<" "<<turnaroundTime - readyQueue.front().arrivalTime;
		sumofWaitingTime += waitingTime - readyQueue.front().arrivalTime;
		sumofTurnaroundTime += turnaroundTime - readyQueue.front().arrivalTime;
		waitingTime += readyQueue.front().executionTime;
		readyQueue.pop();
	}

	cout << "\n\nAll Processes Ended\n";
	cout << "\nAverage Waiting Time: " << (sumofWaitingTime / (double)noOfElements);
	cout << "\nAverage Turnaround Time: " << (sumofTurnaroundTime / (double)noOfElements);
	cout << endl;
	return 0;
}
