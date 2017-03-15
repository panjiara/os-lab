#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	freopen("op1.txt","r",stdin);
	int jsize, psize;
	//cout<<"Enter the following: ";
	//cout<<"\nJob Size = ";
	cin>>jsize;
	//cout<<"Page Size = ";
	cin>>psize;
	int n;
	//cout<<"No of memory locations = ";
	cin>>n;
	struct s
	{
		int add;
		char inst[20];
	} A[n];
	for(int i=0; i<n; ++i)
	{
		cin>>A[i].add;
	}
	//cout<<"Instructions/Data at the memory locations: \n";
	for(int i=0; i<n; ++i)
	{
		scanf("%s\n",A[i].inst);
	}
	cout<<"No. of pages needed to store the entire job = "<<ceil(jsize/psize);
	cout<<"\nMemory location\tPage number\tOffset\n";
	for(int i=0; i<n; ++i)
	{
		cout<<A[i].add<<"\t\t"<<A[i].add/psize<<"\t\t"<<A[i].add%psize<<"\n";
	}
	return 0;
}
