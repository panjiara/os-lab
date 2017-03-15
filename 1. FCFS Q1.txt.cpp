#include <iostream>

using namespace std;

struct node
{
    int arr;
    int cpu;
    int cumu;
    int wait;
    int turn;
    node *next;
};

node* ins(node *start, int t1, int t2)
{
    node *temp=new node;
    temp->arr=t1;
    temp->cpu=t2;
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

/*node* calSJF(node *start)
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

node *insB(node *start, node *key)
{
    node *temp=start;
    int flag=false;
    while(temp->next!=NULL)
    {
        if(temp->next->cpu > key->cpu)
        {
           key->next=temp->next;
           temp->next=key;
           flag=true;
           break;
        }
    }
    if(flag==false)
    {
        key->next=NULL;
        temp->next=key;
    }
    return start;
}

node* sort(node *start)
{
    node *temp=start;
    if(start==NULL)
    {
        cout<<"No jobs were added to the queue.\n";
        return start;
    }
    node *sorted=start;
    while(temp!=NULL)
    {
        sorted=insB(sorted,temp);
        temp=temp->next;
    }
    return sorted;
}*/

void show(node *start)
{
    node *temp=start;
    if(start==NULL)
    {
        cout<<"No jobs were added to the queue.\n";
        return;
    }
    cout<<"\nJob ID\tWaiting time\tTurnaround Time\n";
    int i=0,wait=0,turn=0;
    while(temp!=NULL)
    {
        cout<<i+1<<"\t"<<temp->wait<<"\t"<<temp->turn<<"\n";
        wait+=temp->wait;
        turn+=temp->turn;
        i++;
        temp=temp->next;
    }
    cout<<"\nAverage waiting time: "<<(float)wait/i;
    cout<<"\nAverage turnaround time: "<<(float)turn/i;
}

int main()
{
    node *start=NULL;
    int op,n;
    do
    {
        cout<<"\nChoose:\n1.FCFS\n2.SJF\n3.SRT\n4.Round Robin\n5.Exit\n";
        cin>>op;
        cout<<"Number of jobs: ";
        cin>>n;
        int t1,t2;
        cout<<"Enter arrival time and CPU cycle (in ms):\n";
        for(int j=1; j<=n; ++j)
        {
            cout<<"Job "<<j<<": ";
            cin>>t1>>t2;
            start=ins(start,t1,t2);
        }

        switch(op)
        {
            case 1: start=calFCFS(start);
                    show(start);
                    start=NULL;
                    break;
            /*case 2: start=sort(start);
                    start=calSJF(start);*/
        }
    }while(op!=5);
	return 0;
}
