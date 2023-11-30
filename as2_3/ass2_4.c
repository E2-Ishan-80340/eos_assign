// 4. Write a program that compiles above multi-ﬁle project.
// It runs commands "gcc -c circle.c", "gcc -c square.c", "gcc -c rectangle.c", "gcc -c main.c" concurrently.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int s1,s2,s3,ret1,ret2,ret3,pid1,pid2,pid3;//squ,rect,main
    // char *env_array[] = {"sunbeam","/bin/bash","/home/sunbeam/Desktop/daily_works/OS/day12/as2_3/"}
    // char *args[] = { "gcc", "circle.c", NULL };
    pid1 = fork();
    if(pid1 == 0)
    {
        ret1 = execl("/usr/bin/gcc","gcc","-c","circle.c",NULL);
        if(ret1 == 0)
        {
            printf("Exec Failed");
            _exit(1);
        }
    }
    
    wait(&s1);
    if(WEXITSTATUS(s1)==0)
    {
        pid2 = fork();
        if(pid2 == 0)
        {
            ret2 = execl("/usr/bin/gcc","gcc","-o","circle","circle.o",NULL);
            if(ret2 == 0)
            {
                printf("Exec Failed");
                _exit(1);
            }
            
        }
    }
    wait(&s2);
    if(WEXITSTATUS(s2)==0)
    {
        pid3 = fork();
        if(pid3 == 0)
        {
            ret3 = execl("/home/sunbeam/Desktop/daily_works/OS/day12/as2_3/circle","./circle",NULL);
            if(ret3 == 0)
            {
                printf("Exec Failed");
                _exit(1);
            }
        }
    }
    wait(&s3);
    if(WEXITSTATUS(s3)==0)
    {
        // waitpid(cir,&s,0);      
        printf("parent : child exit status : %d\n",WEXITSTATUS(s3));
    }
    return 0;
}
