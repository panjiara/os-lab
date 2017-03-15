#include<iostream>
#include<cstdio>

using namespace std;

struct job
{
    float arr;   //arrival time
    float cpu;			//burst time
    float rem;  //remaining time
    bool vis;
    bool complete;
    float finish;   //finish time
};

int count(job a[])
{
    int n=0;
    for(int i=0;i<10;i++)
    {
        if(a[i].complete==false)
            n++;
    }
    return n;
}

int main()
{
    freopen("Context.txt","r",stdin);
				float t=0;
    job A[10];
    
    //cout<<"Enter the Arrival and Burst Time consecutively\n";
    for(int i=0;i<10;i++)
    {
								scanf("%f %f",&A[i].arr,&A[i].cpu);
        A[i].vis=A[i].complete=false;
        A[i].rem=A[i].cpu;
    }
    
				float q, ctxt;	//time quantum, context switch
    
				//cout<<"Enter the time quantum\n";
    scanf("%f",&q);
    //cout<<"Enter the context switch time\n";
    scanf("%f",&ctxt);
    
				while(count(A)!=0)
    {
        for(int i=0;((t>=A[i].arr && A[i].vis==false)||(A[i].vis==true))&&(i<10);++i)
        {
            if(A[i].complete==true)
                continue;
            else
            {
                A[i].vis=true;
                if(A[i].rem<=q)
                {
                    t=t+A[i].rem+ctxt;
                    A[i].complete=true;
                    A[i].rem=0;
                    A[i].finish=t;
                }
                else
                {
                    t=t+q+ctxt;
                    A[i].rem-=q;
                }
            }
            cout<<"\nt="<<t<<"\n";
            for(int j=0; j<10; ++j)
            {
            	   if(A[j].arr>t) break;
																if(A[j].rem!=0) cout<<A[j].arr<<"\t"<<A[j].rem<<"\n";
            }
        }
    }
    
    cout<<"\nFinish time\tWaiting Time\tTurnaround Time\n";
    for(int i=0;i<10;i++)
    {
    	  cout<<A[i].finish<<"\t\t"<<A[i].finish-A[i].cpu-A[i].arr<<"\t\t"<<A[i].finish-A[i].arr<<"\n";
    }
    
				float wait=0,turn=0;
    for(int i=0; i<10; ++i)
    {
        wait+=A[i].finish-A[i].arr-A[i].cpu;
        turn+=A[i].finish-A[i].arr;
    }
    wait=(float)wait/10.0;
    turn=(float)turn/10.0;
    cout<<"\nAverage Waiting Time: "<<wait<<"\nAvg turnaround time: "<<turn<<"\n";
    return 0;
}

