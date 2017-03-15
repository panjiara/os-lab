#include<bits/stdc++.h>
using namespace  std;
struct prakriya {

int process_size;
int context_time;

bool ho_gaya;
int block_id;
} p[20];
struct memory
{
   int block_size;
   int osize;
   int process_id;
   bool khali_hai;

}m[10];

queue <int > katar;
int main()
{
    int P,B;
    int frag=0;
    printf("number of process \n");
    scanf("%d",&P);
    printf("Enter the cpu cycle time and  block size\n");
    for(int i=0;i<P;i++)
    {

        cin >> p[i].context_time >> p[i].process_size;
        p[i].ho_gaya=false;


    }

    printf("number of Blocks Please!!\n");
    scanf("%d",&B);
    printf("Block Sizes Pleas!! \n");

    for(int i=0;i<B;i++)
    {
        cin >> m[i].block_size;
        m[i].khali_hai=false;
        m[i].osize=m[i].block_size;
    }
    int sofar=0;
    int t=0;
    int run=0;

    while (run <P)
    {
         printf(" At t= %d\n ",t);
        printf("available memory \n");
        for(int k=0;k<B;k++)
        {
            printf("  m[%d] = %d\n",k+1,m[k].block_size);

        }
         for(int i=0;i<P;i++)
        {
            if( p[i].ho_gaya == false)
{
               for(int k=0;k<B;k++)
               {
                 if (  m[k].khali_hai == false && m[k].block_size >= p[i].process_size)
                   {

                       m[k].block_size-=p[i].process_size;
                       frag+=m[k].block_size;

                       m[k].process_id=i+1;
                       p[i].block_id=k+1;
                       printf(" job[%d] will be loaded in M[%d] \n",i+1,k+1);

                       katar.push(i);
                       p[i].ho_gaya=true;
                        m[k].khali_hai=true;
                        sofar ++;
                        break;
                   }

                    }

                    }
        }
        printf("\n");
        printf(" Main memory jobs are::::::::\n");
        for(int k=0;k<B;k++)
         {
             printf(" J[%d]=>",m[k].process_id);

         }

         int temp;




         temp=katar.front();
         katar.pop();

         int mf=p[temp].block_id;
         mf--;
         m[mf].block_size=m[mf].osize;

         m[mf].khali_hai=false;


         t+=p[temp].context_time;
         printf(" \n Job[%d] will run for %d seconds \n ",temp+1,t);
run++;
 printf(" so block released m [%d] = %d\n",mf+1,m[mf].block_size);

printf("total fragmentation  now= %d\n",frag);

printf("\n");



    }
return 0;


}

