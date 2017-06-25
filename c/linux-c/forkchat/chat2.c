//有名管道
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define FIFO "myfifo"

int main()
{
	char szWBuf[50] = "to be the best";
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
		write(fd,szWBuf,strlen(szWBuf));
		exit(0);
	}
	else
	{
		read(fd,szRBuf,sizeof(szWBuf));
		printf("父进程收到子进程的消息为：%s\n",szRBuf);
	}

	return 0;
}