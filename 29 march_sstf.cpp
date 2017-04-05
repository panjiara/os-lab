#include<bits/stdc++.h>
using namespace std;
 struct request{

    int arr,track,sector;
    double tc;
}req[20];
int A[10];
int check()
{
    int flag=0;
for(int i=0;i<10;i++)
{
    //cout<<A[i]<<"\t";
    if(A[i]==0)
    {
        flag=1;
        break;
    }

}
if(flag==0)
return 0;
else
return 1;
}
int main(){
    for(int i=0;i<10;i++)
    {
        cin>>req[i].arr;
        cin>>req[i].track;
        cin>>req[i].sector;
        req[i].tc=0;
    }
    int last_track=100,last_sector=0;
int ch=1;
double x;
int index=0;
while(ch!=0)
{
   if(index==0)
   {
       int t;
    if(last_sector>req[index].sector)
    {
        t=8-last_sector+req[index].sector;

    }
    else
        t=req[index].sector-last_sector;

    req[index].tc=10+0.1*abs(last_track-req[index].track)+1+t;
    last_track=req[index].track;
    last_sector=req[index].sector;
    A[index]=1;
    x=req[index].tc;
    cout<<x<<"\t";
   }
int mi=INT_MAX;
   for(int i=0;i<10;i++)
   {
       if(A[index+1]==0&&x<req[index+1].arr)
       {
          index++;
          break;
       }

    else if(A[i]==0&&x>req[i].arr)
       {
           if(abs(last_track-req[i].track)<mi)
           {
               mi=abs(last_track-req[i].track);
               index=i;
           }

       }
   }
   int t;
    if(last_sector>req[index].sector)
    {
        t=8-last_sector+req[index].sector;

    }
    else
        t=req[index].sector-last_sector;

    req[index].tc=10+0.1*abs(last_track-req[index].track)+1+t+x;
    last_track=req[index].track;
    last_sector=req[index].sector;
    A[index]=1;
    x=req[index].tc;
    ch=check();
}
    double avg=0;
for(int i=0;i<10;i++)
{
    cout<<"J"<<i+1<<"\n";
    cout<<req[i].arr<<"\t"<<req[i].tc<<"\t\n";
    avg=avg+req[i].tc;
    }
    cout<<"Avg Time\t\t"<<avg/10<<"\n";


return 0;
}

