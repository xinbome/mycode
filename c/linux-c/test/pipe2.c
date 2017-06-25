//有名管道
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define FIFO "one_fifo"

int main()
{
	char szWBuf[50];
	char szRBuf[50];
	//创建有名管道
	if(mkfifo(FIFO,0777) < 0)
	{
		printf("创建管道失败！");
		exit(0);
	}


	int fd = open(FIFO,O_RDWR);
	if(fd < 0)
	{
		printf("打开文件失败！");
		exit(0);
	}


	pid_t pid = fork();
	if(pid < 0)
	{
		printf("创建子进程失败");	
		exit(0);			
	}
	if(pid == 0)
	{
		read(fd,szRBuf,sizeof(szRBuf));
		printf("父进程收到子进程的消息为：%s\n",szRBuf);
		exit(0);
	}
	else
	{
		printf("请输入信息，父进程会传递给子进程(有名管道)\n");
		scanf("%s",szWBuf);		
		write(fd,szWBuf,sizeof(szWBuf));
	}

	return 0;
}