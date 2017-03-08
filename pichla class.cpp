#include<bits/stdc++.h>
using namespace  std;
struct process {

int psize;
int ct;

bool done;
int bid;
} p[20];
struct memory
{
   int bsize;
   int osize;
   int pid;
   bool emp;

}m[10];

queue <int > q;
int main()
{
    int np,nb;
    int frag=0;
    printf("enter the number of processes\n");
    scanf("%d",&np);
    printf("enter the burst and size of each block\n");
    for(int i=0;i<np;i++)
    {

        cin >> p[i].ct >> p[i].psize;
        p[i].done=false;


    }

    printf("enter the number of blocks\n");
    scanf("%d",&nb);
    printf("enter the block sizes\n");

    for(int i=0;i<nb;i++)
    {
        cin >> m[i].bsize;
        m[i].emp=false;
        m[i].osize=m[i].bsize;
    }
    int sofar=0;
    int t=0;
    int run=0;

    while (run <np)
    {
         printf(" At t= %d\n ",t);
        printf("available memory \n");
        for(int k=0;k<nb;k++)
        {
            printf("  m[%d] = %d\n",k+1,m[k].bsize);

        }


        for(int i=0;i<np;i++)
        {
            if( p[i].done == false)
{
               for(int k=0;k<nb;k++)
               {
                 if (  m[k].emp == false && m[k].bsize >= p[i].psize)
                   {

                       m[k].bsize-=p[i].psize;
                       frag+=m[k].bsize;

                       m[k].pid=i+1;
                       p[i].bid=k+1;
                       printf(" job[%d] will be loaded in M[%d] \n",i+1,k+1);

                       q.push(i);
                       p[i].done=true;
                        m[k].emp=true;
                        sofar ++;
                        break;
                   }

                    }

                    }
        }
        printf("\n");
        // printf(" \n No of jobs loaded so far  %d\n",sofar);
        printf(" Jobs In Main Memory are \n");
        for(int k=0;k<nb;k++)
         {
             printf(" J[%d]",m[k].pid);

         }

         int w;




         w=q.front();
         q.pop();

         int mf=p[w].bid;
         mf--;
         m[mf].bsize=m[mf].osize;

         m[mf].emp=false;


         t+=p[w].ct;
         printf(" \n Job[%d] will run for %d seconds \n ",w+1,t);
run++;
 printf(" so block released m [%d] = %d\n",mf+1,m[mf].bsize);

printf("total fragmentation  now= %d\n",frag);

printf("\n");



    }
return 0;


}

