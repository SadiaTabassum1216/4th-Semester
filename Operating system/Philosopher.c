#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>

#define N 5

sem_t chopstick[N];

void *philosopher(void* index)
{
    int i= *(int*) index;

    printf("Philosopher %d thinking.\n", i+1);
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i+1)%N]);

    printf("Philosopher %d takes fork %d and %d.\n",i+1, i+1, ((i+1)%N)+1);
    printf("Philosopher %d is eating.\n", i+1);
    sleep(3);

    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i+1)%N]);

    printf("Philosopher %d putting fork %d and %d down.\n",i+1, i+1, ((i+1)%N)+1);
    printf("Philosopher %d has finished eating.\n", i+1);
    sleep(2);

}

int main()
{
    pthread_t tid[N];
    int table[N];
    for(int i=0; i<N; i++)
    {
        sem_init(&chopstick[i], 0, 1);
    }

    for(int i=0; i<N; i++)
    {
        table[i]= i;
        pthread_create(&tid[i], NULL, philosopher, (void*) &table[i] );

    }


    for(int i=0; i<N; i++)
    {
        pthread_join(table[i], NULL);
    }

}
