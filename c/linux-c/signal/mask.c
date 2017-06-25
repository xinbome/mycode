#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void func()
{
	printf("收到signal信号！\n");
}

int main()
{
	sigset_t newsig,oldsig;
	//安装信号处理函数
	if(signal(SIGINT,&func) < 0)
	{
		printf("安装失败！");
		exit(0);
	}

	//清空信号集
	if(sigemptyset(&newsig) < 0)
	{
		printf("清空信号集失败！");
		exit(0);
	}

	sigaddset(&newsig,SIGINT);
	//屏蔽中断信号
	if(sigprocmask(SIG_SETMASK,&newsig,&oldsig) < 0)
	{
		printf("添加信号屏蔽字失败");
		exit(0);
	}

	printf("信号SIGINT已被屏蔽！\n");
	printf("请用ctrl+c测试！\n");	
	sleep(20);	
	//查看未处理的信号
	sigpending(&newsig);
	if(sigismember(&newsig,SIGINT) == 1)
	{
	printf("信号SIGINT未处理！\n");			
	}
	printf("解除SIGINT的屏蔽！\n");
	sigprocmask(SIG_SETMASK,&oldsig,&newsig);
	printf("请按ctrl+c测试：\n");
	sleep(8);
	return 0;
}