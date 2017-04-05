#include<bits/stdc++.h>
using namespace std;
 struct request{
    int arr,track,sector;
    double tc;
}req[20];
int main(){

    for(int i=0;i<10;i++)
    {
        cin>>req[i].arr;
        cin>>req[i].track;
        cin>>req[i].sector;
    }
    int last_track=100,last_sector=0;
for(int i=0;i<10;i++)
{
    int t;
    if(last_sector>req[i].sector)
    {
        t=8-last_sector+req[i].sector;

    }
    else
        t=req[i].sector-last_sector;

    req[i].tc=10+0.1*abs(last_track-req[i].track)+1+t;
    last_track=req[i].track;
    last_sector=req[i].sector;
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
