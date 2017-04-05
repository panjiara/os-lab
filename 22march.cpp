#include<bits/stdc++.h>
using namespace std;

int main()
{
	 int seq[12]={10,11,104,170,73,309,185,245,246,434,458,364};
	 int word=200;
	 int op;
	 int word1=100,n,pf[12],i=0;
	 int A[12][2];
	 for(int i=0;i<12;i++)
     {
         A[i][2]=0;
         A[i][1]=seq[i];
     }

	    n=word/word1;
	    cout<<n<<endl;
	    int cq[n],sc=0;
		for(i=0; i<12; ++i)
		{
			pf[i]=seq[i]/word1;
			cout<<pf[i]<<" ";
		}
		cout<<"\n";
		int ctr=0;
		for(i=0; i<n; ++i)
			cq[i]=-5;
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
					A[j][2]=1;
					A[j][1]=seq[j];
				}
			}
			if(flag==false)
			{
				cq[ctr]=pf[j];
				ctr=(ctr+1)%n;
				A[j][2]=-1;
				A[j][1]=seq[j];
			}

			else
			{
				sc++;
			}
			cout<<seq[j]<<endl;
			/*for(i=0; i<n; i++)
			{
				cout<<cq[i]<<" ";
			}*/
			for(int i=0;i<12;i++)
            {
                cout<<A[i][1]<<"  " <<A[i][2]<<endl;
            }
			cout<<"\n";
			flag=false;
	    }
		cout<<"Success counter: "<<sc<<"\n";
		cout<<"Success fraction: "<<(float)sc/12<<"\n";

	 return 0;
}
