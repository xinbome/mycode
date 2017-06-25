#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
	//创建子进程
	pid_t pid = fork();
	if(pid < 0)
	{
		printf("error");
	}
	if(pid == 0)
	{
		printf("b\n");
		_exit(0);
	}
	else
	{
		pid_t pid = fork();	

		if(pid < 0)
		{
		printf("error");
		}

		if(pid == 0)
		{
		while(1)
		{
			printf("c\n");
		}
		_exit(0);
		}
		else
		{
		//wait(NULL);
		sleep(20);
		printf("a\n");
		}
	}
	return 0;
}
