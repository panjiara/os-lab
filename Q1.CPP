#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

int at[]={0,3,5,9,10,12,14,16,17,19};
int ct[]={6,2,1,7,5,3,4,5,7,2};
int i=0;

void fcfs();
void sjf();
void srtf();
void rrsa();
int main()
{
	int ch=0;
	while(ch!=5)
	{
		cout<<"\nEnter 1. for FCFS ";
		cout<<"\nEnter 2. for SJF ";
		cout<<"\nEnter 3. for SRTF ";
		cout<<"\nEnter 4. for RRSA ";
		cout<<"\nEnter 5. for Exit ";
		cout<<"\n\nEnter your choice :";
		cin>>ch;
		if(ch==1)
			fcfs();
		if(ch==2)
			sjf();
		if(ch==3)
			srtf();
		if(ch==4)
			rrsa();
		if(ch==5)
			exit(0);
		getch();
	}
		return 0;
}

//////////////////////// FIRST COME FIRST SERVE/////////////////

void fcfs()
{
	int wt[10]={0};
	int tat[10]={0};
	int tcput=0;
	wt[0]=0;
	tat[0]=ct[0];
	tcput=ct[0];
	for(int i=1;i<10;i++)
	{
		wt[i]=tcput-at[i];
		tat[i]=wt[i]+ct[i];
		tcput+=ct[i];
	}
	cout<<"AT \tCPUT  \tWT\t TT\n\n";
	for(i=0;i<10;i++)
		cout<<at[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
	int avgwt=0,avgtat=0;
	for(i=0;i<10;i++)
	{
		avgwt+=wt[i];
		avgtat+=tat[i];
	}
	//avgwt/=10;
	//avgtat/=10;
	cout<<"\n\n Avg. Waiting time = "<<float(avgwt)/10.0;
	cout<<"\n Avg. Turn Around time = "<<float(avgtat)/10;

}



////////////////// Shortest Job First ///////////////////////////


void sjf()
{
	int  c=0;
	int wt[10]={0};
	int tat[10]={0};
	int job[10]={0};
	int tcput=0;
	wt[0]=0;
	tat[0]=ct[0];
	tcput=ct[0];
	job[0]=1;
	for(int i=1;i<10;i++)
	{
		c=0;
		for(int j=1;j<10;j++)
		{
			if(c==0)
			{
				if(job[j]==0)
					c=j;
			}
			else if((ct[j]<ct[c])&&(at[j]<=tcput)&&job[j]==0)
						c=j;
		}


			job[c]=1;
			wt[c]=tcput-at[c];
			tcput+=ct[c];
			tat[c]=wt[c]+ct[c];
	}



	cout<<"AT \tCPUT  \tWT\t TT\n\n";
	for(i=0;i<10;i++)
		cout<<at[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
	int avgwt=0,avgtat=0;
	for(i=0;i<10;i++)
	{
		avgwt+=wt[i];
		avgtat+=tat[i];
	}
	//avgwt/=10;
	//avgtat/=10;
	cout<<"\n\n Avg. Waiting time = "<<float(avgwt)/10.0;
	cout<<"\n Avg. Turn Around time = "<<float(avgtat)/10.0;

}

////////////////////////// Shortest Remaining Time First//////////////////
void srtf()
{
	int ct1[]={6,2,1,7,5,3,4,5,7,2};


	int wt[10]={0};
	int tat[10]={0};
	int job[10]={0};
	int count=0;
	int clock=0;
	int point=0;
	while(count<10)
	{

		clock++;
		ct1[point]=ct1[point]-1;

		if(ct1[point]==0)
		{
			job[point]=1;
			count++;
			tat[point]=clock-at[point];
			wt[point]=tat[point]-ct[point];
			point=0;
			while(job[point]==1)
				point++;

			for(int i=point;i<10;i++)
			{
				if((at[i]<=clock)&& (job[i]==0) && (ct1[i]<ct1[point]))
					point=i;
			}
		}
		for(int j=1;j<10;j++)
		{
			if((clock==at[j])&& (ct[j]<ct1[point]) && (job[j]==0))
			{
				point=j;

			}
		}


	}




	cout<<"AT \tCPUT  \tWT\t TT\n\n";
	for(int i=0;i<10;i++)
		cout<<at[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
	int avgwt=0,avgtat=0;
	for(i=0;i<10;i++)
	{
		avgwt+=wt[i];
		avgtat+=tat[i];
	}
	cout<<"\n\n Avg. Waiting time = "<<float(avgwt)/10.0;
	cout<<"\n Avg. Turn Around time = "<<float(avgtat)/10.0;


}

///////////////////////////Robin Round Scheduling Algorithm///////
void rrsa()
{
	int rt[]={6,2,1
	,7,5,3,4,5,7,2};

	int tq=4;
	int wt[10]={0};
	int tat[10]={0};
	int job[10]={0};
	int count=0;
	int clock=0;
	int point=0;
	while(count<10)
	{

		if(rt[point]>tq)
		{
			clock+=tq;;
			rt[point]=rt[point]-tq;
		}
		else
		{
			clock+=rt[point];
			rt[point]=0;
		}


		if(rt[point]==0)
		{
			job[point]=1;
			count++;
			tat[point]=clock-at[point];
			wt[point]=tat[point]-ct[point];

		}


		if((point<9) && (at[point+1]<=clock)&& (job[point+1]==0))
			point+=1;
		else
		{     point=0;
			while(job[point]==1)
				point++;
		}

	}




	cout<<"AT \tCPUT  \tWT\t TT\n\n";
	for(int i=0;i<10;i++)
		cout<<at[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
	int avgwt=0,avgtat=0;
	for(i=0;i<10;i++)
	{
		avgwt+=wt[i];
		avgtat+=tat[i];
	}
	cout<<"\n\n Avg. Waiting time = "<<float(avgwt)/10.0;
	cout<<"\n Avg. Turn Around time = "<<float(avgtat)/10.0;



}
