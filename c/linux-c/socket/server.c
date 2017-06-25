#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080
int main()
{
	char szRcvBuf[512];
	char szSendBuf[512] = "你好客户端!";
	int s_sockfd,c_sockfd;
	struct sockaddr_in s_addr,c_addr;
	s_addr.sin_family = AF_INET;
	//IP地址,INADDR_ANY 系统直接填写本机IP地址
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_port = PORT;
	char pause = '0';

	//创建套接字
	s_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(s_sockfd == -1)
	{
		printf("创建套接字失败!");
		exit(0);
	}
	//绑定
	bind(s_sockfd,(struct sockaddr*)(&s_addr),sizeof(s_addr));
	//监听
	listen(s_sockfd,5);
	printf("等待客户端连接...\n");	
	int len = sizeof(c_addr);
	//等待客户端连接
	c_sockfd = accept(s_sockfd,(struct sockaddr*)(&c_addr),(socklen_t*)(&len));	
	while(1)
	{	
		//接受数据
		recv(c_sockfd,szRcvBuf,sizeof(szRcvBuf),0);
		printf("服务端收到客户端的消息为:%s\n",szRcvBuf);

		printf("请输入要发给客户端的信息：\n");
		scanf("%s",szSendBuf);
		//发送数据给客户端
		send(c_sockfd,szSendBuf,strlen(szSendBuf),0);
		printf("发送数据给客户端完毕!\n");
		//scanf("%c",&pause);		
	}
	close(c_sockfd);  //断开连接		
}
