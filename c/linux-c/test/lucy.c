//有名管道
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define FIFO "write_fifo"
#define OTHERFIFO "read_fifo"

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


	//创建有名管道
	if(mkfifo(OTHERFIFO,0777) < 0)
	{
		printf("创建管道失败！");
		exit(0);
	}

	int fd1 = open(OTHERFIFO,O_RDWR);
	if(fd1 < 0)
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

		//printf("Lucy.c 功能2：接受Peter.c的消息 通过read_fifo管道\n ");		
		read(fd1,szRBuf,sizeof(szRBuf));
		printf("Peter.c已向Lucy.c发出：%s\n",szRBuf);
		//exit(0);
	}
	else
	{
		//printf("Lucy.c 功能：发送消息给Peter.c 通过write_fifo管道\n ");
		printf("请输入Lucy.c要向Peter.c发出的消息\n");
		scanf("%s",szWBuf);		
		write(fd,szWBuf,sizeof(szWBuf));
		printf("Lucy.c已向Peter.c发出%s\n",szWBuf);
	}


	return 0;
}