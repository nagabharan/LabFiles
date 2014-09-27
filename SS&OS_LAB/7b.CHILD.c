#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char cmd[10];
	pid_t child;
	if((child=fork())<0)
	{
		printf("Fork error");
		exit(0);
	}
	if(child==0)
	{
		printf("Command to perform: ");
		gets(cmd);
		system(cmd);
	}
	else
	{
		wait();
		printf("Child complete");
	}
}
