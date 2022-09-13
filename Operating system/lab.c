#include<stdio.h>
#include<unistd.h>

int main()
{
    int i, input[10],sum=0,count=0;
    pid_t pid1,pid2,pid3;

    printf("\nI'm the original process with PID %d and PPID %d.\n",getpid(),getppid());

    printf("Enter 10 values:\n");
    for(i=0;i<10;i++){
        scanf("%d",&input[i]);
    }

    pid1=fork();

    if(pid1==0){
        printf("\nI'm the child process with PID %d and PPID %d.\n",getpid(),getppid());

        for(i=0;i<10;i++){
            if(input[i]%2==0)
                sum+=input[i];
        }

        printf("\nSum of even numbers: %d",sum);


         pid2=fork();

    if(pid2==0){
        printf("\nI'm the child process with PID %d and PPID %d.\n",getpid(),getppid());

        for(i=0;i<10;i++){
            if(input[i]%2==0)
                count++;
        }

        printf("\nTotal even numbers: %d\n",count);



           pid3=fork();

    if(pid3==0){
        printf("\nI'm the child process with PID %d and PPID %d.\n",getpid(),getppid());

       int j,temp;

        for(i=0;i<10;i++){
            for(j=i+1;j<10;j++){
                if(input[i]>input[j]){
                temp=input[i];
                input[i]=input[j];
                input[j]=temp;
                }
            }
        }
        printf("Sorted array:\n");
        for(i=0;i<10;i++){
            printf("%d\t",input[i]);
        }

        printf("Total even numbers: %d\n",count);

    }






    }

    }








    return 0;
}

