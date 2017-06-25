#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//消息的结构体
struct msg
{
	long type;
	char szMsg[1024];
};


int main()
{
	int msgid;
	pid_t pid,pid1;
	key_t key;
	struct  msg sendMsg[10],rcvMsg[10];
	key = ftok("a.txt",1);//专门用来生成key值的函数


	//创建消息队列
	msgid = msgget(key,IPC_CREAT|0644);
	if(msgid == -1)
	{
		printf("创建消息队列失败！\n");
		exit(0);
	}

				
	//printf("测试1\n");

	pid = fork();
	if(pid < 0)
	{
		printf("创建子进程失败！\n");
		exit(0);
	}
	if(pid ==0)
	{
		//clent依次从10到1发送消息
		int n = 0;
		for(n = 9;n>=0;n--)
		{
			sendMsg[n].type = n + 1; 	
			strcpy(sendMsg[n].szMsg,"hello!");	
			if(msgsnd(msgid,&sendMsg[n],sizeof(sendMsg[n]),IPC_NOWAIT) < 0) 
			{
				printf("子进程发送消息失败\n"); exit(0);
			}
			else
			{
				printf("%dclient sent\n",sendMsg[n].type);
			}						
		}
		//printf("测试2\n");		

	}else
	{
		//server接受消息
		sleep(1);
		pid1 = fork();
		if(pid1 < 0)
		{
			printf("创建子进程失败！\n");
			exit(0);
		}
		if(pid1 == 0)
		{
			//printf("测试3\n");		
			int m = 9;
			for(;m >= 0;m--)
			{
				if(msgrcv(msgid,&rcvMsg[m],sizeof(rcvMsg[m]),m,0) < 0)
				{
					printf("接受消息失败！%d\n",msgid);
					exit(0);
				}
				printf("读取到的消息为：%s\n",rcvMsg[m].szMsg);					
			}
			//删除消息队列		
			msgctl(msgid,IPC_RMID,0);		
		}

	}
	return 1;
}