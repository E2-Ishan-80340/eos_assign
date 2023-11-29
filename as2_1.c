// 1. Input signal number and a process id from user.
// Send given signal to the given process using kill() syscall.
#include<stdio.h>
#include<signal.h>

int main()
{
    int signum,procid;
    printf("Enter signal number :");
    scanf("%d",&signum);
    printf("Enter process ID :");
    scanf("%d",&procid);
    kill(procid,signum);
    printf("programm killed !!!!!\n");

    return 0;
}