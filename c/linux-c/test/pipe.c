#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd[2];
	char szWBuf[50];
	char szRBuf[50];

	//创建无名管道
	if(pipe(fd) < 0)
	{
		printf("创建管道失败！\n");
		exit(0);
	}


	//创建子进程
	pid_t pid = fork();
	if( pid < 0)
	{
		printf("创建子进程失败！\n");
		exit(0);		
	}
	if(pid == 0)
	{
		//sleep(2);
		close(fd[1]);
		read(fd[0],szRBuf,sizeof(szRBuf));
		printf("子进程受到父进程的消息：%s\n",szRBuf);	
			

	}else
	{
		printf("请输入信息，父进程会传递给子进程（无名管道）\n");
		scanf("%s",szWBuf);
		close(fd[0]);
		write(fd[1],szWBuf,strlen(szWBuf));

	}
	return  0;
}