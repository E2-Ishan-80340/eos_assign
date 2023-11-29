// 3. Find max number of child processes that can be created on Linux using C program? 
// Hint: use fork() in inﬁnite loop (wisely).

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
    int ret,s1;
    int count = 0;
    while(1)
    {
        ret = fork();
        if(ret == -1)
            break;
        else if(ret == 0 )
        {
            sleep(5);
            _exit(1);
        }
        else
        {
            count++;
            // sleep(1);
        }
    }
    waitpid(ret,&s1,0);
    printf("Max Count of Childs : %d\n",count);
    return 0;
}