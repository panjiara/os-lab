#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int ct=0;
int resT[10],terT[10];

 int allot(int pro,int i)
 {
     if(resT[i]==0)
     resT[i]=ct;
     ct+=pro;
     terT[i]=ct;

}
    struct node
{
       int no,bt,pr,a;
};
 int main()
{
 
     node pro[5];
     int wT[5]={0};
     int taT[5]={0};
     int mem[5]={0},c=0;
 for(int i=0;i<5;i++)
 {
         pro[i].no=i;
         pro[i].a=0;
         
}
pro[0].bt=6;pro[1].bt=2;pro[2].bt=1;pro[3].bt=7;
pro[4].bt=5;
pro[0].pr=0;pro[1].pr=3;pro[2].pr=5;pro[3].pr=9;
pro[4].pr=10;
allot(pro[0].bt,0);
pro[0].a=1;

for(int i=1;i<5;i++)
{
        c=0;
        for(int j=1;j<5;j++)
        {
                if(c==0)
               { if(pro[j].a==0)
                c=j;
                }
        
        else if((pro[j].pr<=ct)&&(pro[j].bt<pro[c].bt)&&pro[j].a==0)
        {
            c=j;
        }
        }
        allot(pro[c].bt,c);
        pro[c].a=1;
}
 cout<<"pro"<<"\t"<<"wt"<<"\t"<<"tat"<<endl;
for(int i=0;i<5;i++)
{
                 wT[i]=resT[i]-pro[i].pr;
                 taT[i]=terT[i]-resT[i];
                
                 cout<<i+1<<"\t"<<wT[i]<<"\t"<<taT[i]<<endl;
}



      getch();
      return 0;
      }

