#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	pid_t cpid,ppid,pid;
	if((pid=fork())<0)
	{
		printf("Fork error");
		exit(0);
	}
	if(pid==0)
	{
		printf("\n I am Child");
		printf("\n My id is %d", getpid());
		printf("\n My parent id is %d", getppid());
		exit(0);
	}
	else
	{
		wait();
		printf("\n I am Parent");
		printf("\n My id is %d", getpid());
		printf("\n My child id is %d\n", pid);
	}
}

