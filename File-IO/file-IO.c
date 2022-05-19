/*************************
Performing FILE IO operations using 
open(), read(), write(), lseek(), execl(), dup2()

*************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char rbuff[1024], wbuff[] = "Hello..this is write buffr!!";
	
	int fd, newFD;
	int wbyte, rbyte;
	
	//opening the file
	//create a 'myfile.txt' in same directory
	fd = open("myfile.txt", O_RDWR, 777);
	
	//error case
	if(fd == -1)
	{
		printf("error in file opening\n");
		exit(0);
	}
	
	//file Ops
	else
	{
	
	/*OPEN FILE*/
		printf("\nFILE OPENED.....\n");
		printf("FD for this file is : %d\n", fd);
		
	/*WRITE TO FILE*/	
		printf("\nWRITING TO FILE.....\n");
		//writing to file from wbuff
		wbyte = write(fd, wbuff, sizeof(wbuff));
		printf("No. of bytes written to file --> %d bytes\n", wbyte);
		
	/*SET CFO*/	
		//setting file pointer/CFO to beginning of the file
		lseek(fd, 0, SEEK_SET);
		
	/*READ FROM FILE*/	
		printf("\nREADING FROM FILE.....\n");
		//reading the file contents and saving it to rbuff
		rbyte = read(fd, rbuff, wbyte);
		printf("Total bytes read from the file --> %d bytes\n", rbyte);
		printf("Data read is --- %s\n",rbuff);
		
		printf("\n");
		
	/*DUPLICATING FD USING dup2()*/
		newFD = dup2(fd, 7);			//duplicating previous fd and giving it custom name --- fd = 7
		printf("NEW FD for this file is : %d\n", newFD);
		
	/*MODIFYING FILE DATA*/	
		printf("\nMODIFYING FILE DATA.....\n");
		//set cursor at last
		int cur = lseek(newFD, 1, SEEK_END);
		
		printf("Now cursor is at %d byte\n", cur);

		//modifying data in file
		char new[] = " And this is modified text...!!";		//new text to be added
		
		wbyte = write(newFD, new, sizeof(new));
		printf("No. of bytes modified --> %d bytes\n", wbyte);
		
		
		printf("\nREADING MODIFYING DATA.....\n");
		
		//setting file pointer/CFO to beginning of the file
		lseek(newFD, 0, SEEK_SET);
		
		printf("Modified data is --- \n");
		
		//displaying file contents without opening using execl() sys call			
		execl("/bin/cat", "cat", "myfile.txt", NULL);	
		
		printf("\n");
		
	}
	
	close(newFD);
	close(fd);
	
	return 0;
}
