#include <stdio.h>
#include <fcntl.h>

int main()
{
	char szWBuf[30] = "你好";
	char szRBuf[30];
	//打开文件
	int fd = open("b.txt",O_CREAT|O_TRUNC|O_RDWR,0644);
	if (fd == -1)
	{
		printf("打开文件失败!\n");
		return 0;
	}
	//写文件
	write(fd,szWBuf,sizeof(szWBuf));
	lseek(fd,0,SEEK_SET);
	//读文件
	read(fd,szRBuf,sizeof(szRBuf));
	printf("读到的内容为%s\n", szRBuf);
	//关闭文件
	close(fd);
	return 0;
}
