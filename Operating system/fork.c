#include<stdio.h>
#include<unistd.h>

int main()
{
    int pid;
    printf("I'm the original process with PID %d and PPID %d.\n",getpid(),getppid());
    pid=fork();

    printf("Hi\n");

    if(pid!=0){
        printf("I'm the parent process with PID %d and PPID %d.\n",getpid(),getppid());
        printf("Child pid is %d\n",pid);

    }

    else
    {
        printf("I'm the child process with PID %d and PPID %d.\n",getpid(),getppid());
    }

    printf("PID %d terminated.\n",getpid());
    return 0;
}
