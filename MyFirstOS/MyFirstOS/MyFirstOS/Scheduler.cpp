#include <iostream>
#include "Scheduler.h"
#include "Process.h"

	int n;
	int Bu[20];
	double Twt;//Total wait time
	double Awt;//Average wait time
	double A[20];
	double Wt[20];
	double w;

Scheduler::Scheduler(Process (&myArray)[100])
{
}

void Scheduler::getdata()
{
	int i;
	cout << "Enter the no of processes: ";
	cin >> n;

	for (i=1;i<=n;i++)
	{
		cout <<" Enter The BurstTime for Process p "<< i << "= ";
		cin >> Bu[i];
	}
}


void Scheduler::fcfs()
{
	int i;
	int B[10];
	Twt = 0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for process p"<<i<<"=	";
		cout<<B[i];
	}
	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}

	//Calculating Average Weighting Time
	for(i = 1; i <= n; i++)
		Twt = Twt + Wt[i];
	Awt = Twt/n;
	cout<< "Total Weighting Time = " <<Twt << endl;
	cout<< "Average Weighting Time = " << Awt << " ";
	cout << endl;

}

void Scheduler::sjf()
{
	int i;
	int j;
	int temp;
	int B[10];

	Twt=0.0;

	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for process p "<<i<< "= ";
		cout<<B[i];
	}

		for(i=n;i>=1;i--)
		{
			for(j=1;j<=n;j++)
			{
				if(B[j-1]>B[j])
				{
					temp = B[j-1];
					B[j-1] = B[j];
					B[j] = temp;
				}
			}
		}

	Wt[1] = 0;

	for (i = 2; i<=n; i++)
	{
		Wt[i] = B[i-1] + Wt[i-1];
	}
	//calculating Average Weighting Time

	for ( i = 1; i<=n; i++)
		Twt = Twt + Wt[i];
	Awt = Twt/n;
	cout<<" Total Weighting Time = "<<Twt;
	cout<<"Average Weighting Time = "<< Awt<<" ";
	cout << endl;
}

void Scheduler::roundrobin()
{

}

void Scheduler::priority()
{
	int i;
	int B[10];
	int P[10];
	int j;

	w=0.0;
	int max;
	Twt=0.0;
	max=1;

	for ( i = 1; i <= n; i++)
	{
		B[i] = Bu[i];
		cout<<" Burst time for process p" << i <<" = ";
		cout<<B[i];
		cout<<" Enter the priority for process P "<< i << "=";
		cin>> P[i];
		if (max<P[i])
			max=P[i];
	}
	j=1;

	while ( j <= max)
	{
		i = 1;
		while(i<=n)
		{
			if (P[i] == j)
			{
				Wt[i] = w;
				w = w + B[i];
			}
			i++;
		}
		j++;
	}

	//calculating average weighting Time
	for ( i = 1; i <= n; i++)
		Twt = Twt + Wt[i];
	Awt = Twt/n;
	cout << "Total Weighting Time = " << Twt << " " << endl;
	cout << "Average Weighting Time = " << Awt << " ";
	cout << endl;
}

using namespace std;

int main ()
{
	int ch,cho;
	Scheduler c;
	do
	{
		cout<<"				 MENU " << endl;
		cout<<"1.Getting BurstTime " << endl;
		cout<<"2.FirstComeFirstServed " << endl;
		cout<<"3.ShortestJobFirst " << endl;
		cout<<"4.RoundRobin " << endl;
		cout<<"5.Priority " << endl;
		cout<<"6.EXIT " << endl;
		cout<<"Enter your choice " << endl;

		cin>>ch;
		switch(ch)
		{
		case 1:
			c.getdata();
			break;
		case 2:
			cout<<"FIRST COME FIRST SERVED SCHEDULING ";
			c.fcfs();
			break;
		case 3:
			cout<<"SHORTEST JOB FIRST SCHEDULING ";
			do
			{
				cout<<"1.SJF-Normel ";
				cout<<"Enter your choice";
				cin>>cho;
				switch(cho)
				{
				case 1:
					c.sjf();
					break;

				}
			} while(cho<=3);
			break;
		case 4:
			cout<<"ROUND ROBIN SCHEDULING ";
			c.roundrobin();
			break;
		case 5:
			cout<<"PRIORITY SCHEDULING ";
			c.priority();
			break;
		case 6:
			break;
		}
	}while(ch<=5);
}