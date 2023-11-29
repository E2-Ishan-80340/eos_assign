//From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
// processes should run concurrently for 5 seconds and cleaned up properly upon termination.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
    int i,s1,s2,s3,ret1,ret2,ret3;
    printf("Program statrted!!!\n");
    ret1=fork();
    if(ret1 == 0)
    {  
        ret2 = fork();
        if(ret2 == 0)
        {
            ret3 = fork();
            if(ret3 == 0)
            {
                for(i = 1; i<=5; i++)
                {
                    printf("CHILD D\n");
                    sleep(1);
                }
                _exit(3);
            }
                for(i=1;i<=5;i++)
                {
                    printf("CHILD C\n");
                    sleep(1);
                }
        waitpid(ret3,&s3,0);
        _exit(2);
        }
            for(i=1;i<=5;i++)
            {
                printf("CHILD B\n");
                sleep(1);
            }
            waitpid(ret2,&s2,0);
            _exit(1);
    }        
        for(i = 1;i<=5;i++)
        {
            printf("PARENT A\n");
            sleep(1);
        }
        waitpid(ret1,&s1,0);

    printf("Program Ended!!!\n");

    return 0;
}


