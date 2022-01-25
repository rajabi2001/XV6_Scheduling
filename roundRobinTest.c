#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char const *argv[])
{
    int Bavg = 0,Wavg = 0,TAavg = 0;


    printf(1,"This is roundRobinTest\n");

    // if (fork()){ //child1
    //     printf(1,"i'm a child");
       
     
    // }else{ //parent

    //     if (fork()){    //child2
    //         printf(1,"i'm a child");
        
        
    //     }else{ //parent

    //         if (fork()){ //child3
    //             printf(1,"i'm a child");


    //         }else{ //parent
    
    //             if (fork()){    //child4
    //                 printf(1,"i'm a child");
        
        
    //             }else{ //parent

    //                 if (fork()){    //child5
    //                     printf(1,"i'm a child");
        
        
    //                 }else{ //parent

    //                     if (fork()){    //child6
    //                         printf(1,"i'm a child");
        
        
    //                     }else{ //parent
        
    //                         if (fork()){    //child7
    //                             printf(1,"i'm a child");
        
        
    //                         }else{ //parent
        
    //                             if (fork()){    //child8
    //                                 printf(1,"i'm a child");
        
        
    //                             }else{ //parent
        
    //                                 if (fork()){    //child9
    //                                     printf(1,"i'm a child");
        
        
    //                                 }else{ //parent
        
    //                                     wait();
    //                                 }
    //                             }
    //                         }

    //                     }
        
    //                 }
        
    //             }
    //         }
    //     }
    // }

    int x =1 ;
    for (int i = 0; i < 3; i++)
    {
        int pid = fork();
        if (pid == 0 ) //child
        {
            
            x +=1;

            for (int j = 0; j < 10; j++)
            {
                printf(1,"/%d/ : /%d/\n",x,j);
            }
            

        }else //parent
        {
            
            // while (iszombie(pid) != 1);
            wait();
            
            int Btime,TAtime,Wtime;
            
            getPerformance(pid,&Btime,&TAtime,&Wtime);

            printf(1,"%d , Wtime = %d ? Btime = %d ?  TAtime = %d\n",pid ,Wtime ,Btime ,TAtime);

            Wavg += Wtime;
            Bavg += Btime;
            TAavg += TAtime;

            

            
        }
        

          
    }
    
    Wavg /=10;
    Bavg /=10;
    TAavg /=10;

    printf(1,"Wavg = %d\n",Wavg);
    printf(1,"Bavg = %d\n",Bavg);
    printf(1,"TAavg = %d\n",TAavg);
    return 0;
}
