#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
    int arr, cpu, rem, cumu, wait, turn, finish;
    node *next;
};

int min(int a, int b)
{
	return a<b?a:b;
}

void swap(int &a, int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

node* ins(node *start, int t1, int t2)
{
    node *temp=new node;
    temp->arr=t1;
    temp->cpu=t2;
    temp->rem=t2;
    temp->wait=0;
    temp->cumu=0;
    temp->turn=0;
    temp->finish=0;
    if(start==NULL)
    {
        temp->next=NULL;
        start=temp;
    }
    else
    {
        node *q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        temp->next=NULL;
        q->next=temp;
    }
    return start;
}

void show(node *start)
{
    node *temp=start;
    if(start==NULL)
    {
        cout<<"No jobs were added to the queue.\n";
        return;
    }
    cout<<"\nJob ID\tArrival time\tCPU Burst\tFinish time\tWaiting\tTurnaround\n";
    int i=0,wait=0,turn=0;
    while(temp!=NULL)
    {
        cout<<i+1<<"\t\t"<<temp->arr<<"\t\t"<<temp->cpu<<"\t\t"<<temp->finish<<"\t\t"<<temp->wait<<"\t"<<temp->turn<<"\n";
        wait+=temp->wait;
        turn+=temp->turn;
        i++;
        temp=temp->next;
    }
    cout<<"\nAverage waiting time: "<<(float)wait/i;
    cout<<"\nAverage turnaround time: "<<(float)turn/i;
}

node* calFCFS(node *start)
{
    node *temp=start;
    if(start==NULL)
    {
        cout<<"No jobs were added to the queue.\n";
        return start;
    }
    int t=0;
    while(temp!=NULL)
    {
        temp->cumu=t+temp->cpu;
        if(t>=temp->arr) temp->wait=t-temp->arr;
        else temp->wait=0;
        temp->turn=temp->wait+temp->cpu;
        t=temp->cumu;
        temp=temp->next;
    }
    return start;
}

node *deleteP(node *start, int a, int b)
{
    node *temp=start;
    if(temp->arr==a && temp->cpu==b)
    {
        start=temp->next;
        return start;
    }
    while(temp->next!=NULL)
    {
        if(temp->next->arr==a && temp->next->cpu==b)
        {
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    return start;
}


int getLastArr(node* start)
{
    node* temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp->arr;
}

void doSJF(node *start)
{
    int w=0, trn=0;
    node* temp=start;
    cout<<"t=Completion time\narr=Arrival time\ncpu=CPU Burst Time\nwait=Waiting Time\nturn=Turnaround Time\n";
    cout<<"t\tarr\tcpu\twait\tturn\n";

    //1st turn
    temp->cumu=temp->arr;
    temp->wait=temp->arr;
    temp->turn=temp->wait+temp->cpu;
    cout<<temp->cumu<<"\t"<<temp->arr<<"\t"<<temp->cpu<<"\t"<<temp->wait<<"\t"<<temp->turn<<"\n";
    w+=temp->wait;
    trn+=temp->turn;
    //cout<<"\t\t\tJob 1 removed.\n";

    int t=temp->cumu;
    t+=temp->cpu;
    temp=temp->next;

    int nr=1;
    int la=getLastArr(start);

    struct que
    {
        int arvl, brst, oi;
    }Q[10];
    int i=0;

    //turn 2 to last-1
    while(1)
    {
        node *temp1=temp;
        i=0;
        for(int g=0; g<10; ++g)
        {
            Q[g].arvl=Q[g].brst=0;
            Q[g].oi=g;
        }
        while(temp1->arr <= t)
        {
            Q[i].arvl=temp1->arr;
            Q[i].brst=temp1->cpu;
            Q[i].oi=i;
            i++;
            temp1=temp1->next;
        }

        cout<<"\nQ is - \n";
        for(int g=0; g<i; ++g)
        {
            cout<<"   "<<Q[g].arvl<<"\t"<<Q[g].brst<<"\t"<<Q[g].oi<<"\n";
        }
        cout<<"\n";

        int mina=Q[0].arvl;
        int minb=Q[0].brst;
        int mini=0;
        for(int j=1; j<i; ++j)
        {
            if(Q[j].brst < minb)
            {
                mina=Q[j].arvl;
                minb=Q[j].brst;
                mini=j;
            }
        }
        cout<<t<<"\t"<<mina<<"\t"<<minb<<"\t"<<t-mina<<"\t"<<t-mina+minb<<"\n";
        //cout<<"\t\t\tJob "<<mini+1+nr<<" removed.";

        w+=t-mina;
        trn+=t-mina+minb;

        temp=deleteP(temp,mina,minb);
        t+=minb;
        nr++;

        if(t >= la) break;
        //temp=temp->next;
    }
    node *temp2=temp;
    i=0;
    while(temp2->arr <= t)
    {
        Q[i].arvl=temp2->arr;
        Q[i].brst=temp2->cpu;
        Q[i].oi=i;
        i++;
        temp2=temp2->next;
        if(temp2==NULL) break;
    }
    cout<<"\nQ is - \n";
    for(int g=0; g<i; ++g)
    {
        cout<<"   "<<Q[g].arvl<<"\t"<<Q[g].brst<<"\t"<<Q[g].oi<<"\n";
    }
    cout<<"\n";

    for(int k=0; k<i-1; ++k)
    {
        for(int k1=k+1; k1<i; ++k1)
        {
            if(Q[k1].brst < Q[k].brst)
            {
                swap(Q[k].brst,Q[k1].brst);
                swap(Q[k].arvl,Q[k1].arvl);
                swap(Q[k].oi,Q[k1].oi);
            }
            else if(Q[k1].brst == Q[k].brst)
            {
               if(Q[k1].arvl < Q[k].arvl)
               {
                  swap(Q[k].brst,Q[k1].brst);
                  swap(Q[k].arvl,Q[k1].arvl);
                  swap(Q[k].oi,Q[k1].oi);
               }
            }

        }
    }

    /*cout<<"\nQ is - \n";
        for(int g=0; g<i; ++g)
        {
            cout<<Q[g].arvl<<"\t"<<Q[g].brst<<"\t"<<Q[g].oi<<"\n";
        }
        cout<<"\n";
    */
    for(int k=0; k<i; ++k)
    {
        cout<<t<<"\t"<<Q[k].arvl<<"\t"<<Q[k].brst<<"\t"<<t-Q[k].arvl<<"\t"<<t-Q[k].arvl+Q[k].brst<<"\n";
        w+=t-Q[k].arvl;
        trn+=t-Q[k].arvl+Q[k].brst;
        //cout<<"\t\t\tJob "<<Q[k].oi+1+nr<<" removed.\n";
        nr++;
        t+=Q[k].brst;
    }
    cout<<"\n"<<(float)w/10<<"\t"<<(float)trn/10<<"\n";
}

node *modify(node *start, int a, int b, int val)
{
    node *temp=start;
    //cout<<"val="<<val<<"\n";
    if(temp->arr==a && temp->rem==b)
    {
        temp->rem=temp->cpu-val;
        return start;
    }
    while(temp->next!=NULL)
    {
        if(temp->next->arr==a && temp->next->rem==b)
        {
            temp->next->rem-=val;
            //cout<<"a="<<a<<" b="<<b<<"temp->next->rem="<<temp->next->rem<<"\n";
            break;
        }

		temp=temp->next;
    }
    return start;
}

node *modify(node *start, int a, int t)
{
    node *temp=start;
    if(temp->arr==a)
    {
        temp->finish=t;
        return start;
    }
    while(temp->next!=NULL)
    {
        if(temp->next->arr==a)
        {
            temp->next->finish=t;
            break;
        }
		temp=temp->next;
    }
    return start;
}

node *deleteP1(node *start, int a, int b)
{
    node *temp=start;
    if(temp->arr==a && temp->rem==b)
    {
        start=temp->next;
        return start;
    }
    while(temp->next!=NULL)
    {
        if(temp->next->arr==a && temp->next->rem==b)
        {
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    return start;
}

void decideSRT(node *start)
{
	node *temp=start;
	while(temp!=NULL)
	{
		temp->turn = temp->finish - temp->arr;
		temp->wait = temp->turn - temp->cpu;
		temp = temp->next;
	}
	show(start);
}

void doSRT(node *start, node *copy)
{
    node* temp=start;
    node* temptemp=copy;

    int t=temp->arr;
    int la=getLastArr(start);
	
    struct que
    {
        int arvl;
		int brst;
        int rem;
		    
    } Q[10];
    int i=0;
	   
    while(1)
    {
		node *temp1=temp;
        i=0;
        for(int g=0; g<10; ++g)
        {
            Q[g].arvl=0;
			Q[g].brst=0;
            Q[g].rem=0;
        }
        while(temp1->arr <= t)
        {
            Q[i].arvl=temp1->arr;
            Q[i].brst=temp1->cpu;
            Q[i].rem=temp1->rem;
            i++;
            temp1=temp1->next;
            if(temp1==NULL) break;
        }

        cout<<"\nReady Queue: \n";
        for(int g=0; g<i; ++g)
        {
            cout<<"   "<<Q[g].arvl<<"\t"<<Q[g].rem;
			cout<<"\n";
        }
        cout<<"\n";
		if(t >= la) break;
        int mina=Q[0].arvl;
        int minb=Q[0].rem;
        for(int j=1; j<i; ++j)
        {
            if(Q[j].rem < minb)
            {
                mina=Q[j].arvl;
                minb=Q[j].rem;
            }
        }

        int value=min(minb+t, temp1->arr);

        //cout<<"t="<<t<<"\n";
        if(value - t == minb) 
		{
			//cout<<"updated\n";
			temptemp=modify(temptemp,mina,value);
			//show(temptemp);
			temp=deleteP1(temp,mina,minb);      
		}  
        else 
			temp=modify(temp,mina,minb,value-t);
		t=min(minb+t, temp1->arr);

    }

    for(int k=0; k<i-1; ++k)
    {
        for(int k1=k+1; k1<i; ++k1)
        {
            if(Q[k1].rem < Q[k].rem)
            {
                swap(Q[k].rem,Q[k1].rem);
                swap(Q[k].arvl,Q[k1].arvl);
            }
            else if(Q[k1].rem == Q[k].rem)
            {
               if(Q[k1].arvl < Q[k].arvl)
               {
                  swap(Q[k].rem,Q[k1].rem);
                  swap(Q[k].arvl,Q[k1].arvl);
               }
            }

        }
    }

    cout<<"\nSorted Ready Queue: \n";
    for(int g=0; g<i; ++g)
    {
        cout<<"    "<<Q[g].arvl<<"\t"<<Q[g].rem<<"\n";
    }
    cout<<"\n";
    
    for(int k=0; k<i; ++k)
    {
        t+=Q[k].rem;
		temptemp=modify(temptemp, Q[k].arvl, t);   
    }
    decideSRT(temptemp);
}

int main()
{
    node *start=NULL;
    node* copy=NULL;
    int op,n;
    do
    {
        cout<<"\nChoose:\n1.FCFS\n2.Non pre-emptive SJF\n3.SRT\n4.Round Robin\n5.Exit\n";
        cin>>op;
        /*cout<<"Number of jobs: ";
        cin>>n;
        putJob(n);
        int t1,t2;
        cout<<"Enter arrival time and CPU cycle (in ms):\n";
        for(int j=1; j<=n; ++j)
        {
            cout<<"Job "<<j<<": ";
            cin>>t1>>t2;
            start=ins(start,t1,t2);
        }*/
        start=ins(start,0,6);
        start=ins(start,3,2);
        start=ins(start,5,1);
        start=ins(start,9,7);
        start=ins(start,10,5);
        start=ins(start,12,3);
        start=ins(start,14,4);
        start=ins(start,16,5);
        start=ins(start,17,7);
        start=ins(start,19,2);
        copy=ins(copy,0,6);
        copy=ins(copy,3,2);
        copy=ins(copy,5,1);
        copy=ins(copy,9,7);
        copy=ins(copy,10,5);
        copy=ins(copy,12,3);
        copy=ins(copy,14,4);
        copy=ins(copy,16,5);
        copy=ins(copy,17,7);
        copy=ins(copy,19,2);
        switch(op)
        {
            case 1: start=calFCFS(start);
                    show(start);
                    start=NULL;
                    break;
            case 2: //show(start);
					doSJF(start);
                    break;
            case 3: //show(start);
					doSRT(start, copy);
            		break;
        }
    }while(op!=5);
	return 0;
}
