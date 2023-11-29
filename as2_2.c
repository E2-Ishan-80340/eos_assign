// 2. Improve your shell program so that it should not be terminated due to SIGINT (ctrl+C).
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

void sigint_handler(int sig)
{
    printf("Signal caught : %d",sig);
}

int main()
{
    char *ptr, cmd[512], *args[32];
    int i,err,ret,s;
    signal(2,sigint_handler);
    while(1){
    printf("cmd> ");
    gets(cmd);
        i=0;
        ptr = strtok(cmd, " ");//cmd is character string, " "--delimiter
    //return : It returns the pointer to the first token encountered in the string.
            // It returns NULL if there are no more tokens found.
        args[i] = ptr;
        i++;
        do
        {
            ptr = strtok(NULL," ");
            args[i] = ptr;
            i++;
        }while(ptr != NULL);

        if(strcmp(args[0], "exit")==0)
            _exit(0);//exxit from shell
        else if(strcmp(args[0],"cd")==0)
            chdir(args[1]);//change the current dir of the shell program
        else
        {
            ret = fork();
            if(ret == 0)
            {
                err = execvp(args[0], args);
                if(err < 0 )
                {
                    perror("bad command");
                    _exit(1);
                }
            }
            else
                waitpid(-1,&s,0);
        }
    }
    return 0;
}