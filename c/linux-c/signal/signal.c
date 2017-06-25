#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void func()
{
	printf("收到信号SIGINT!\n");
}
int main()
{
	//安装信号处理函数
	if(signal(SIGINT,&func) < 0)
	{
		perror("安装信号失败!\n");
		exit(0);
	}
	sleep(5);
	kill(getpid(),SIGINT);
	return 1;
}