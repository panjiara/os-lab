#include<iostream>
#include<cstdio>

using namespace std;

void swap(int &a, int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

struct mem
{
	  int oi;
	  int memory;
	  int rem;
	  bool occupied;
} M[5000];

struct job
{
	  int oi;
	  int jsize;
	  int cpu;
	  int start;
	  int end;
	  int store;      //stores the occupied memory block id
} J[5000];

int main()
{
    freopen("fit.txt","r",stdin);
	freopen("fit4b.txt","w",stdout);
	int j,m;
				
	//cout<<"Enter no. of memory blocks: ";
	cin>>m;
	//cout<<"Enter sizes of all the memory blocks: ";
	for(int i=0; i<m; ++i)
	{
		cin>>M[i].memory;
		M[i].oi=i+1;
	}
	
	for(int i=0; i<m; ++i)
	{
		for(int k=0; k<i; ++k)
		{
			if(M[i].memory<M[k].memory)
			{
				swap(M[i].memory, M[k].memory);
				swap(M[i].oi, M[k].oi);
			}
			else if(M[i].memory==M[k].memory)
			{
				 if(M[i].oi<M[k].oi)
				 {
				 	  swap(M[i].memory, M[k].memory);
								swap(M[i].oi, M[k].oi);
				 }
			}
		}
	}	
	
	for(int i=0; i<m; ++i)
	{
		cout<<"M"<<M[i].oi<<"-->"<<M[i].memory<<"\n";
		M[i].rem=M[i].memory;
		M[i].occupied=false;
	}	
	cout<<"\n\n";
		
	//cout<<"Enter no. of jobs: ";
e	cin>>j;
	//cout<<"Enter burst time and sizes needed by all the jobs: ";
	for(int i=0; i<j; ++i)
	{
		cin>>J[i].cpu>>J[i].jsize;
		J[i].end=-1;
		J[i].oi=i+1;
	}
	
	for(int i=0; i<j; ++i)
	{
		for(int k=0; k<i; ++k)
		{
			if(J[i].cpu<J[k].cpu)
			{
				  swap(J[i].cpu,J[k].cpu);
				  swap(J[i].jsize,J[k].jsize);
				  swap(J[i].oi,J[k].oi);
			}
			else if(J[i].cpu==J[k].cpu)
			{
				 if(J[i].oi<J[k].oi)
				 {
				 	  swap(J[i].cpu,J[k].cpu);
				    swap(J[i].jsize,J[k].jsize);
				    swap(J[i].oi,J[k].oi);
				 }
			}
		}
	}	
	
	for(int i=0; i<j; ++i)
	{
		cout<<"J"<<J[i].oi<<"-->"<<J[i].cpu<<"\t"<<J[i].jsize<<"\n";
	}
	cout<<"\n\n";
				
    int executed=0, t=0;
    
    int n=0;
    bool flag=false;
    for(int i=0; i<j; ++i)
    {
    	 for(int k=0; k<m; ++k)
    	 {
    	 	if(J[i].jsize<M[k].memory)
    	 	{
    	 		flag=true;
    	 		break;
    	 	}
    	 }
    	 if(flag==true) n++;
    	 flag=false;
    }
    
    while(executed<n)
    {
         for(int i=0; i<j; ++i)
         {
             if(J[i].end==t)
             {
                M[J[i].store].rem+=J[i].jsize;
                M[J[i].store].occupied=false;
             }
         }
         for(int i=0; i<j; ++i)
         {
             if(J[i].end==-1)
             {
                for(int k=0; k<m; ++k)
                {
                   if(M[k].occupied==false && M[k].rem>=J[i].jsize)
                   {
                     executed++;
                     J[i].start=t;
                     J[i].end=t+J[i].cpu;
                     M[k].rem-=J[i].jsize;
                     J[i].store=k;
                     cout<<"J "<<J[i].oi<<" -> M"<<M[k].oi<<"\n";
                     M[k].occupied=true;
                     break;
                   }
                }
             }
         }
         int ifrag=0;
         int waitqlength=j-executed;
         
         cout<<"Block no\tRemaining\n";
         for(int k=0; k<m; ++k)
         {
             ifrag+=M[k].rem;
             cout<<"M"<<M[k].oi<<"\t\t"<<M[k].rem<<"\n";
         }
         cout<<"t="<<t<<"\n";
         cout<<"Waiting Queue Length= "<<waitqlength<<"\n";
         cout<<"Internal Fragmentation= "<<ifrag<<"\n\n";
         ++t;
    }
    cout<<"\n\n";
    cout<<"Waiting Time\n";
    int et=-1;
    for(int i=0; i<j; ++i)
    {
        et=(et>J[i].end)?et:J[i].end;
        cout<<"J"<<J[i].oi<<": ";
        if(J[i].end!=-1) cout<<J[i].start<<"\n";
        else cout<<"Not done\n";
    }
    cout<<"\n\nTotal jobs executed: "<<n<<"\n";
    cout<<"Finish time: "<<et<<"\n";
    cout<<"Throughput: "<<(float)n/et;
    return 0;
}
