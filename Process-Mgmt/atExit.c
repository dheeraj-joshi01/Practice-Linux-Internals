/************************************************************************
execution of functions in reverse order using atexit()
************************************************************************/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void function_A()
{
	printf("Calling function 1\n");
}

void function_B()
{
	printf("Calling function 2\n");
}

void function_C()
{
	printf("Calling function 3\n");
}

int main()
{
	/*Normal function call*/
		printf("Normal function call...\n");
		
		function_A();
		
		function_B();

		function_C();
	
	/*Function call using atexit()*/
		printf("\nFunction call using atexit()...\n");
		
		atexit(function_A);
		
		atexit(function_B);
		
		atexit(function_C);
	
	
	//_exit(0);		//will not call for the func which are registred at atexit()
	
	return 0;
	
}
