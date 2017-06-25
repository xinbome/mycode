#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#define PORT 8080
int main()
{
	char szRcvBuf[512];
	char szSendBuf[512]="你好，服务器";
	int c_sockfd;
	int fd;
	char pause = '0';
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = PORT;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//创建套接字
	c_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(c_sockfd == -1)
	{
		printf("创建套接字失败");
		exit(0);
	}
	fd = connect(c_sockfd,(struct sockaddr*)(&addr),(socklen_t)(sizeof(addr)));
	if(fd == -1)
	{
		printf("连接到服务器失败!");
		exit(0);
	}
	while(1)
	{
	printf("请输入要发给客户端的信息：\n");
	scanf("%s",szSendBuf);		
	send(c_sockfd,szSendBuf,strlen(szSendBuf),0);
	//sleep(3);
	recv(c_sockfd,szRcvBuf,sizeof(szRcvBuf),0);
	printf("收到服务器的指令:%s\n",szRcvBuf);
	//scanf("%c",&pause);
	}
	close(c_sockfd);	
	return 0;
}
