#include<iostream>

#include<vector>
#include<conio.h>

#define NOJ 25

#define NOMB 10

using namespace std;

int main() {

int i,j,pro,tno=0;

	int joblist[NOJ][2]={5,5760,4,4190,8,3290,2,2030,2,2550,6,6990,8,8940,10,740,
			7,3930,6,6890,5,6580,8,3820,9,9140,10,420,10,220,7,7540,
			3,3210,1,1380,9,9450,3,3610,7,7540,2,2710,8,8390,5,5950,10,760};

	int mem[NOMB]={9500,7000,4500,8500,3000,9000,1000,5500,1500,500};

	vector<int> memutil(NOMB,0);

	double avgtp=0.0,avgif=0.0,avgwt=0.0,avgql=0.0;

	vector<int> jobcomp(NOJ,0),jobtomem(NOJ,-1),memtojob(NOMB,-1),jobtottime(NOJ,-1),memoccp(NOMB,0);

	int nocompj=0,nocurrj=NOJ,nojq=NOJ;

	for(i=0;nocompj<NOJ;i++) {

		cout<<"Time: "<<i<<"\n";

		int nopj=0,intfrag=0;

	for(pro=0;pro<NOJ;pro++)

		{

			if(jobcomp[pro]!=1)

				{

				if(jobtottime[pro]==i)

				{

				nocompj++;

				nocurrj--;

			cout<<"Job "<<pro+1<<" completed and freed memory "<<jobtomem[pro]+1<<"\n";

				memoccp[jobtomem[pro]]=0;

				memtojob[jobtomem[pro]]=-1;

				jobtomem[pro]=-2;

				jobtottime[pro]=-2;

				jobcomp[pro]=1;

				}

				}

		}

		for(pro=0;pro<NOJ;pro++)

		{

			if(jobtomem[pro]==-1)

			for(int m=0;m<NOMB;m++)

			{

				if(!memoccp[m])

				{

					if(mem[m]>=joblist[pro][1])
						{
							memoccp[m]=1;
							memutil[m]++;
							avgwt+=i;
							jobtottime[pro]=i+joblist[pro][0];
							jobtomem[pro]=m;
							memtojob[m]=pro;
							cout<<"Process "<<pro+1<<" allocated memory block "<<m+1<<" till time "<<jobtottime[pro]<<"after waiting for "<<i<<" units\n";
							nopj++;
							nojq--;
							break;
						}
				}
			}
		}
		if(nojq!=0) tno++;
		for(int m=0;m<NOMB;m++)
		if(memoccp[m])
			intfrag+=mem[m]-joblist[memtojob[m]][1];
		avgtp+=nopj;
		avgql+=nojq;
		avgif+=intfrag;
		cout<<"Throughput = "<<nopj<<"\nWaiting queue length = "<<nojq<<"\nInternal Fragmentation = "<<intfrag<<"\n";
		cout<<"\n\n";
	}
	avgtp/=tno;
	avgql/=tno;
	avgwt/=NOJ;
	avgif/=i-1;
	cout<<"Total time = "<<i-1<<" "<<tno<<"\nAverage throughput = "<<avgtp<<"\nAverage wait queue length = "<<avgql<<"\nAverage wait time = "<<avgwt<<"\nAverage internal fragmentation = "<<avgif<<"\n";
	cout<<"\nJoblist:\n";
	for(i=0;i<NOJ;i++) cout<<joblist[i][0]<<"\t"<<joblist[i][1]<<"\n";
	cout<<"\nMemory:\n";

	for(i=0;i<NOMB;i++)
cout<<mem[i]<<"\n";


getch();
	return 0;

}
