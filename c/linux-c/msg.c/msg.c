#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
//消息的结构体
struct msg
{
	long type;
	char szMsg[512];
};

int main()
{
	int msgid;
	pid_t pid;
	key_t key;
	struct  msg sendMsg,rcvMsg;
	key = ftok("a.txt",1);//专门用来生成key值的函数
	//创建消息队列
	msgid = msgget(key,IPC_CREAT|0644);
	if(msgid == -1)
	{
		printf("创建消息队列失败！\n");
		exit(0);
	}
	pid = fork();
	if(pid < 0)
	{
		printf("创建子进程失败！\n");
		exit(0);
	}
	if(pid ==0)
	{
		sendMsg.type = 1;
		strcpy(sendMsg.szMsg,"hello!");
		//子进程发送消息到消息队列
		if(msgsnd(msgid,&sendMsg,sizeof(sendMsg),IPC_NOWAIT) < 0) {printf("子进程发送消息失败\n"); exit(0);}

	}else
	{
		//接受消息
		if(msgrcv(msgid,&rcvMsg,sizeof(rcvMsg),0,0) < 0)
		{
			printf("接受消息失败！\n");
			exit(0);
		}
		printf("父进程读取到的消息为：%s\n",rcvMsg.szMsg);

		//删除消息队列
		msgctl(msgid,IPC_RMID,0);
	}
	return 1;
}