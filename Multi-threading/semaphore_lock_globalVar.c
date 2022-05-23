//op on global var using semaphore lock
//this program executes 1 thread at a time


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

int sharedVal = 5;

sem_t my_sem;			//creating semaphore lock

void *td_inc(void *arg)
{
	sem_wait(&my_sem);		//apply lock
	sharedVal++;		//critical section
	sem_post(&my_sem);		//release lock
	
	printf("inc val = %d\n",sharedVal);
}


void *td_dec(void *arg)
{
	sem_wait(&my_sem);		//apply lock
	sharedVal--;		//critical section
	sem_post(&my_sem);		//release lock
	
	printf("dec val = %d\n",sharedVal);
}


void main()
{
	pthread_t th1, th2;
	
	sem_init(&my_sem, 0, 1);		//initialize lock
	
	pthread_create(&th1, NULL, td_inc, NULL);
	pthread_create(&th2, NULL, td_dec, NULL);
	
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	printf("sharedVal is %d\n", sharedVal);
	
}
