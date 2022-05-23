//modify attribute 	-->	change stack size of thread

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>


void* proc(void *param)
{
	sleep(2);
	return 0;
}




int main(void)
{
	pthread_attr_t att;
	pthread_t id;
	void *stk;
	size_t siz;
	int err;
	
	size_t my_stksize = 300000;
	void * my_stack;
	
	pthread_attr_init(&att);		//init attribute
	pthread_attr_getstacksize(&att, &siz);	//get size of stack
	pthread_attr_getstackaddr(&att, &stk);	//get stack addrss
	
	printf("def addr : %08x def size : %d\n", stk,siz);
	
	my_stack = (void*)malloc(my_stksize);		//make new stack
	
	pthread_attr_setstack(&att, my_stack, my_stksize);			//get stack info
	
	pthread_create(&id, &att, proc, NULL);
	
	pthread_attr_getstack(&att, &stk, &siz);
	
	printf("new stack addr : %08x def size : %ld\n", stk,siz);
	
	pthread_attr_destroy(&att);
	
	return 0;
}


//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	
