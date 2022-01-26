#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char const *argv[])
{

    int n = 10,y;
    int pidlist[n];
    int Bavg = 0,Wavg = 0,TAavg = 0;
    int ppid = getpid();
    setPolicy(0);
    checkPolicy();

    for(int i=0;i<n;i++) 
    {
        int p = fork();
        pidlist[i] = p;
        if(p == 0)
        {   
            int x = getpid();
            
            
            for (int j = 0; j < 1000; j++)
            {
                printf(1,"/%d/ : /%d/\n",x,j);
            }
            
            // pidlist[i] = x;
            break;
        }
    }

    if (getpid() == ppid)
    {
        for(int i=0;i<n;i++){

            y = pidlist[i];

            int Btime,TAtime,Wtime;
            
            getPerformance(y,&Btime,&Wtime,&TAtime);

            printf(1,"pid = %d , TAtime = %d ",y,TAtime );
            printf(1,"Btime = %d ",Btime);
            printf(1,"Wtime = %d \n",Wtime);

            Wavg += Wtime;
            Bavg += Btime;
            TAavg += TAtime;

            wait();
        }
        
        Wavg /=n;
        Bavg /=n;
        TAavg /=n;

        printf(1,"Wavg = %d\n",Wavg);
        printf(1,"Bavg = %d\n",Bavg);
        printf(1,"TAavg = %d\n",TAavg);
    }

    return 0;

    // int Bavg = 0,Wavg = 0,TAavg = 0;


    // printf(1,"This is roundRobinTest\n");

    // for (int i = 0; i < 3; i++)
    // {
    //     int pid = fork();
    //     if (pid == 0 ) //child
    //     {
    //         int x = getpid();
    //         for (int j = 0; j < 10; j++)
    //         {
    //             printf(1,"/%d/ : /%d/\n",x,j);
    //         }
            

    //     }else //parent
    //     {
    //         // x *=i;

    //         while (iszombie(pid) != 1) 
    //             sleep(1);
            

    //         int Btime,TAtime,Wtime;
            
    //         getPerformance(pid,&Btime,&Wtime,&TAtime);

    //         printf(1,"pid = %d , TAtime = %d ",pid,TAtime );
    //         printf(1,"Btime = %d ",Btime);
    //         printf(1,"Wtime = %d \n",Wtime);

    //         Wavg += Wtime;
    //         Bavg += Btime;
    //         TAavg += TAtime;

    //         wait();

            
    //     }
        

          
    // }
    
    // Wavg /=10;
    // Bavg /=10;
    // TAavg /=10;

    // printf(1,"Wavg = %d\n",Wavg);
    // printf(1,"Bavg = %d\n",Bavg);
    // printf(1,"TAavg = %d\n",TAavg);
    // return 0;
}
