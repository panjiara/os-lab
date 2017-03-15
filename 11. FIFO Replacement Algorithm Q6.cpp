#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	 int seq[12]={10,11,104,170,73,309,185,245,246,434,458,364};
	 int word=200;
	 int op;
	 int word1,n,pf[12],i=0;
	 do
	 {
	   cout<<"Choose: \n1.Page size of 100 words\n2.Page Size of 20 words\n3.Page size of 200 words\n4.Main Memory of 400 words (enter 41/42/43)\n5.Exit\n";
	   cin>>op;
	   switch(op)
	   {
	 	  case 1: word=200; 
					word1=100;
				  break;
		  case 2: word=200;
				word1=20;
		  		  break;
		  case 3: word=200;
				word1=200;
		  		  break;
		  case 41: word=400;
		           word1=100;
		           break;
		  case 42: word=400;
		           word1=20;
		           break;
		  case 43: word=400;
		           word1=200;
		           break;
		  case 5: exit(0);		
	   }
	    n=word/word1;
	    int cq[n],sc=0;
		for(i=0; i<12; ++i)
		{
			pf[i]=seq[i]/word1;
			cout<<pf[i]<<" ";
		}
		cout<<"\n";
		int ctr=0;
		for(i=0; i<n; ++i)
			cq[i]=-1;
		int j=0;
		bool flag=false;
		for(j=0; j<12; ++j)
		{
			for(i=0; i<n; ++i)
			{
				if(cq[i]==pf[j])
				{
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				cq[ctr]=pf[j];
				ctr=(ctr+1)%n;
			}
			else
			{
				sc++;
			}
			for(i=0; i<n; ++i)
			{
				cout<<cq[i]<<" ";
			}
			cout<<"\n";
			flag=false;
	    }
		cout<<"Success counter: "<<sc<<"\n";
		cout<<"Success fraction: "<<(float)sc/12<<"\n";
		sc=0;
     } while (op!=5);
	 return 0;
}
