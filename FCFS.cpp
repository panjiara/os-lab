#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int ct=0;
int resT[10]={0};
int terT[10]={0};

 int allot(int pro,int i)
 {
     if(resT[i]==0)
     resT[i]=ct;
     ct+=pro;
     terT[i]=ct;

}
 int main()
{int i;
 int pro[]={6,2,1,7,5,3,4,5,7,2};
 int at[]={0,3,5,9,10,12,14,16,17,19};
 int wT[10]={0};
 int taT[10]={0};
 
 for(i=0;i<10;i++)
 {
         if(at[i]<=ct)
         allot(pro[i],i);
         else
         {ct++;i--;}
         }
 cout<<"pro"<<"\t"<<"wT"<<"\t"<<"taT"<<endl;
for(i=0;i<10;i++)
{
                 wT[i]=resT[i]-at[i];
                 taT[i]=terT[i]-resT[i];
                 cout<<i+1<<"\t"<<wT[i]<<"\t"<<taT[i]<<endl;
}



      getch();
      return 0;
      }

