#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int j, ret, pid[5], s[5];

    for (j = 0; j < 5; j++)
    {
        pid[j] = fork();
        if (pid[j] == 0)
        {
            printf("child:%d ~~~~ pid == %d ~~~~ ppid == %d\n", j, getpid(), getppid());
            sleep(5);
            _exit(j);
        }
        else
        {
            printf("parent:%d ~~~~ parent pid == %d\n", j, getpid());
            sleep(1);
        }
    }

    for (j = 0; j < 5; j++)
    {
        waitpid(pid[j], &s[j], 0);
        printf("parent: child %d exited with status %d\n", j, WEXITSTATUS(s[j]));
    }

    return 0;
}
