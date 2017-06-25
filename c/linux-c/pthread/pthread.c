#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
void func1()
{
	int i = 5;
	for(;i > 0;i--)
	{
		sleep(1);
		printf("我是线程1\n");
	}
}

void func2()
{
	int i = 5;
	for(;i > 0;i--)
	{
		sleep(1);
		printf("我是线程2\n");
	}
}

int main()
{
	pthread_t p1,p2;
	//创建两个线程

	pthread_create(&p1,NULL,(void*)&func1,NULL);
	pthread_create(&p2,NULL,(void*)&func2,NULL);
	pthread_join(p1,NULL);//等待线程1结束
	pthread_join(p2,NULL);//等待线程2结束	
	//sleep(10);//进程结束的话，线程也就不存在了
	printf("我是主进程！\n");	
	return 1;
}