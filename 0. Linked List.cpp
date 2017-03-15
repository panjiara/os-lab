#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int d;
    node *next;
};

void show(node *start)
{
    node *temp=start;
    cout<<"List: ";
    if(start==NULL)
    {
        cout<<"Empty\n";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->d<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

node* insF(node *start, int n)
{
    node *temp=new node;
    temp->d=n;
    if(start==NULL)
    {
        temp->next=NULL;
        start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
    show(start);
    return start;
}

node* insR(node *start, int n)
{
    node *temp=new node;
    temp->d=n;
    if(start==NULL)
    {
        temp->next=NULL;
        start=temp;
    }
    else
    {
        node *ll=start;
        while(ll->next!=NULL)
        {
            ll=ll->next;
        }
        temp->next=NULL;
        ll->next=temp;
    }
    show(start);
    return start;
}

node* insG(node *start, int n, int e)
{
    node *temp=new node;
    temp->d=n;
    node *ll=start;
    if(start==NULL)
    {
        cout<<"List is empty. Please update the list first.";
        return start;
    }
    while(ll->next->d!=e)
    {
        ll=ll->next;
        if(ll->next==NULL) break;
    }
    if(ll->next==NULL)
    {
        cout<<"Element not found!";
    }
    else
    {
        temp->next=ll->next;
        ll->next=temp;
        show(start);
    }
    return start;
}

node* delF(node* start)
{
    if(start==NULL)
    {
        cout<<"\nAlready empty";
    }
    else
    {
        node* temp=start;
        start=temp->next;
        show(start);
    }
    return start;
}

node* delR(node* start)
{
    if(start==NULL)
    {
        cout<<"\nAlready empty";
        return start;
    }
    node *temp=start;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    show(start);
    return start;
}

node* delGa(node* start, int e)
{
    node *temp=start;
    int c=0;
    if(temp->d==e)
    {
        start=temp->next;
    }
    while(temp->next!=NULL)
    {
       while(temp->next->d!=e)
       {
          temp=temp->next;
          if(temp->next==NULL) break;
       }
       if(temp->next==NULL)
       {
          if(c==0) cout<<"Element not found!";
          break;
       }
       else
       {
          temp->next=temp->next->next;
       }
       c++;
    }
    show(start);
    return start;
}

node* delGf(node* start, int e)
{
    node *temp=start;
    int c=0;
    if(temp->d==e)
    {
        start=temp->next;
        show(start);
        return start;
    }
    while(temp->next->d!=e)
    {
        temp=temp->next;
        if(temp->next==NULL) break;
    }
    if(temp->next==NULL)
    {
        cout<<"Element not found!";
    }
    else
    {
        temp->next=temp->next->next;
    }
    show(start);
    return start;
}

int main()
{
	   char c;
	   node* start=NULL;
    while(1)
	   {
	       cout<<"\nChoose the suitable option:";
        cout<<"\n1.Insertion at front end";
        cout<<"\n2.Insertion at rear end";
        cout<<"\n3.Insertion before an element";
        cout<<"\n4.Deletion from front end";
        cout<<"\n5.Deletion from rear end";
        cout<<"\n6.Deletion of an element (first occurrence)";
        cout<<"\n7.Deletion of an element (all occurrences)";
        cout<<"\n8.Exit\n";
        int op,n,e;
        cin>>op;
        switch(op)
        {
            case 1: cout<<"Enter the element to be inserted:";
                    cin>>n;
                    start=insF(start,n);
                    break;
            case 2: cout<<"Enter the element to be inserted:";
                    cin>>n;
                    start=insR(start,n);
                    break;
            case 3: cout<<"Enter the element to be inserted:";
                    cin>>n;
                    cout<<"Enter the element before which it is to be inserted:";
                    cin>>e;
                    start=insG(start,n,e);
                    break;
            case 4: start=delF(start);
                    break;
            case 5: start=delR(start);
                    break;
            case 6: cout<<"Enter the element to be deleted:";
                    cin>>e;
                    start=delGf(start,e);
                    break;
            case 7: cout<<"Enter the element to be deleted:";
                    cin>>e;
                    start=delGa(start,e);
                    break;
            case 8: exit(0);
            default: cout<<"Wrong choice";
        }
	   }
	   return 0;
}
