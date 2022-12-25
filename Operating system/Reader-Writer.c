#include<stdlib.h>
#include<limits.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include<unistd.h>


int rc = 0, wc = 0;
sem_t read_sem, write_sem ;
pthread_mutex_t mut_1, mut_2, mut_3 ;
int count = 1;

void Reading(void *rno);
void Writing(void *wno);
void reader(void *rno);
void writer(void *wno);

int main()
{

	pthread_t rc[10], wc[5];
	sem_init(&write_sem, 0, 1);
	pthread_mutex_init(&mut_3, NULL);
	pthread_mutex_init(&mut_2, NULL);
	pthread_mutex_init(&mut_1, NULL);
	sem_init(&read_sem, 0, 1);

	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < 10; i++) {
		pthread_create(&rc[i], NULL, (void *)reader, (void *)&a[i]);
	}
	for (int i = 0; i < 5; i++) {
		pthread_create(&wc[i], NULL, (void *)writer, (void *)&a[i]);
	}

	for (int i = 0; i < 10; i++) {
		pthread_join(rc[i], NULL);
	}
	for (int i = 0; i < 5; i++) {
		pthread_join(wc[i], NULL);
	}

	sem_destroy(&write_sem);
	pthread_mutex_destroy(&mut_3);
	sem_destroy(&read_sem);
	pthread_mutex_destroy(&mut_2);
	pthread_mutex_destroy(&mut_1);

	return EXIT_SUCCESS;

}

void Reading(void *rno) {
	printf("Reader No. %d\tcount: %d\n", *((int *)rno), count);
}

void Writing(void *wno) {
	if ( ((long long int)count * 2) > INT_MAX)
		count = 1;
	else
		count = count * 2;

	printf("Writer No. %d\tcount: %d\n", (*((int *)wno)), count);
}

void reader(void *rno) {
	for(;;) {

		pthread_mutex_lock(&mut_3);
		sem_wait(&read_sem);
		pthread_mutex_lock(&mut_1);
		rc++;

		if (rc == 1)
			sem_wait(&write_sem);

		pthread_mutex_unlock(&mut_1);
		sem_post(&read_sem);
		pthread_mutex_unlock(&mut_3);

		Reading(rno);

		pthread_mutex_lock(&mut_1);
		rc--;
		if (rc == 0)
			sem_post(&write_sem);
		pthread_mutex_unlock(&mut_1);

		sleep(2);

	}
}

void writer(void *wno) {
	while (1) {

		pthread_mutex_lock(&mut_2);
		wc++;
		if (wc == 1)
			sem_wait(&read_sem);
		pthread_mutex_unlock(&mut_2);

		sem_wait(&write_sem);
		Writing(wno);
		sem_post(&write_sem);

		pthread_mutex_lock(&mut_2);
		wc--;
		if (wc == 0)
			sem_post(&read_sem);
		pthread_mutex_unlock(&mut_2);


		sleep(2);

	}
}

