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
       int no,bt,pr;
};
 int main()
{
 
     node pro[5];
     int wT[5]={0};
     int taT[5]={0};
 for(int i=0;i<5;i++)
 {
         pro[i].no=i;
         
         
}
pro[0].bt=10;pro[1].bt=1;pro[2].bt=2;pro[3].bt=1;
pro[4].bt=5;
pro[0].pr=3;pro[1].pr=1;pro[2].pr=4;pro[3].pr=5;
pro[4].pr=2;
for(int i=0;i<5;i++)
{
        for(int j=0;j<5;j++)
        {node temp;
                if(pro[i].pr<pro[j].pr)
              {  
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
                }
        }
}
for(int i=0;i<5;i++)
{
       allot(pro[i].bt,pro[i].no);
 
}
 cout<<"wT"<<"\t"<<"taT"<<endl;
for(int i=0;i<5;i++)
{
                 wT[i]=resT[i];
                 taT[i]=terT[i]-resT[i];
                 cout<<wT[i]<<"\t"<<taT[i]<<endl;
}



      getch();
      return 0;
      }

