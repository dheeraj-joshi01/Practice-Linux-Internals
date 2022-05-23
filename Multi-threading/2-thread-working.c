//Using 2 threads at a time to see which executes at what time

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>			//POSIX thread library



pthread_t tid1, tid2;			//thread identifier

//task to be executed by thread 1
	void* task_1(void *arg)
	{
		printf("\n-----Thread 1 is executing-----\n");
		
		for(int i=0; i<10; i++)
			printf("thread 1: %d\n",i);

		return NULL;
	}


//task to be executed by thread 2
	void* task_2(void *arg)
	{
		sleep(1);
		printf("\n-----Thread 2 is executing-----\n");
		
		for(int i=0; i<10; i++)
			printf("thread 2: %d\n",i);

		return NULL;
	}



int main(void)
{
	//thread creation
	int ret1 = pthread_create(&tid1, NULL, task_1, NULL);
	int ret2 = pthread_create(&tid2, NULL, task_2, NULL);


	//check error
	if(ret1 && ret2)
		printf("thread not created...there's some error.\n");
	
	else
		printf("Thread created successfully..\n");



	// sleep(3);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);



	printf("Exiting main thread\n");

return 0;
}
