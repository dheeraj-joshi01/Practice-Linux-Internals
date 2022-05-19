//menu driven program to run shell commands using execl() and fork()

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
	pid_t pid;
	int opt;
	
	//infinite loop
	while(1)
	{
		printf("\n--------------------------------------------------------\n");
		printf("\nenter\n1: to run 'ls' cmd \n2: to run 'ps -ef' cmd \n3: to run 'ps -aux' cmd \n0: to exit\n");
		scanf("%d", &opt);
		
		
		//exit case
		if(!opt)
			exit(0);
			
		sleep(1);
			
		pid = fork();		//creating child process 
		
		
		//child process in execution
		if(pid == 0)
		{
			printf("\n--------------------------------------------------------\n");
			
			//getting process id's
			printf("\nChild Created....child PID = %d\n", getpid());
			printf("PID of Parent process = %d\n", getppid());
			printf("\n");
			
			printf("\n--------------------------------------------------------\n");
			//menu driven
			switch(opt)
			{
				case 1:
				execl("/bin/ls", "ls", NULL);
				break;
				
				case 2:
				execl("/bin/ps", "ps", "-ef", NULL);
				break;
				
				case 3:
				execl("/bin/ps", "ps", "-aux", NULL);
				break;
				
				default:
				printf("Invalid Option\n");
				break;
			}
			exit(0);
		}
		
		else
			sleep(3);		//sleep of 3 second
	}
	
	return 0;
}
