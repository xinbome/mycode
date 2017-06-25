#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//无名管道的两个单向通讯
int main()
{
	int fd[2];
	int fd1[2];
	char szWBuf[50] = "a";
	char szRBuf[50];

	char sew[50] = "b";
	char ser[50];
	//创建无名管道
	if(pipe(fd) < 0)
	{
		printf("创建管道失败！\n");
		exit(0);
	}

	if(pipe(fd1) < 0)
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
		close(fd1[1]);
		read(fd1[0],ser,strlen(ser));
		printf("子进程受到父进程的消息：%s\n",szRBuf);	
			
		//关闭读端
		close(fd[0]);
		write(fd[1],szWBuf,strlen(szWBuf));
		exit(0);
	}else
	{
		close(fd1[0]);
		write(fd1[1],sew,strlen(sew));
		
		//wait(NULL);
		//关闭写端
		close(fd[1]);
		read(fd[0],szRBuf,strlen(szRBuf));
		printf("父进程受到子进程的消息：%s\n",szRBuf);
	}
}