#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char const *argv[])
{
    int n = 60,y;
    int pidlist[n];
    int Bavg = 0,Wavg = 0,TAavg = 0;
    int ppid = getpid();
    setPolicy(2);
    checkPolicy();


    for(int i=0;i<n;i++) 
    {
        int p = fork();
        pidlist[i] = p;
        if(p == 0)
        {   int x = getpid();
            // printf(1,"[son] pid %d \n",x);
            
            if (i <= 9)
            {
                setPriority(x,6);
            }else if (i <= 19)
            {
                setPriority(x,5);
            }else if (i <= 29)
            {
                setPriority(x,4);
            }else if (i <= 39)
            {
                setPriority(x,3);
            }else if (i <= 49)
            {
                setPriority(x,2);
            }else 
            {
                setPriority(x,1);
            }
            
            
            for (int j = 0; j < 20; j++)
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
}