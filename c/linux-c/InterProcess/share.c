#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	key_t key = 75;//IPC_PRIVATE;
	int shmid;
	char * addr;
	char input[500];
	pid_t pid;
	//1创建共享内存
	shmid = shmget(key,1024,IPC_CREAT|0777);//1k大
	if(shmid == -1)
	{
		printf("创建共享内存失败！");
		exit(0);
	}
	//2将进程与共享内存进行关联
	addr = (char*)shmat(shmid,NULL,0);
	if(addr == NULL)
	{
		printf("映射失败");
	}

	//3创建子进程
	pid = fork();
	if(pid < 0)
	{
		printf("创建子进程失败！");
		exit(0);
	}
	if(pid == 0)
	{
		printf("This is server!Input your words:");
		scanf("%s",input);
		strcpy(addr,input);
		exit(0);
	}else
	{
		//wait(NULL);
		sleep(10);
		printf("This is client!：%s\n", addr);			
		//4将共享内存与进程脱离
		if(shmdt(addr) == -1)
		{
			printf("脱离失败！");
			exit(0);
		}
		//5删除共享内存
		if(-1 == shmctl(shmid,IPC_RMID,NULL))
		{
			printf("删除内存失败！");
			exit(0);			
		}
	}



	return 0;
}