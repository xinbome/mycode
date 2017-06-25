#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

//给文件上建议性锁

void SetLock(int fd,int iType)
{
	struct flock oldLock;
	oldLock.l_type = 0;
	oldLock.l_start = 0;
	oldLock.l_whence = SEEK_SET;
	oldLock.l_len = 10;
	oldLock.l_pid = 0;
	//查看文件是否已经上锁
	fcntl(fd,F_GETLK,&oldLock);
	if(oldLock.l_type != F_UNLCK)
	{
		//如果有锁，判断是什么锁
		if(oldLock.l_type == F_RDLCK)
		{
			//说明现在是读取锁
			printf("文件现在已经上了读取锁，上锁进程号为%d\n", oldLock.l_pid);
		}else if (oldLock.l_type == F_WRLCK)
		{
			printf("文件现在已经上了写入锁，上锁进程号为%d\n", oldLock.l_pid);
		}
	}

	oldLock.l_type = iType;
	//给文件上锁
	fcntl(fd,F_SETLKW,&oldLock);

	if(oldLock.l_type == F_RDLCK)
	{
		printf("上锁成功!\n");
		printf("由进程号为：%d进程上了读取锁！\n", getpid());

	}else if(oldLock.l_type == F_WRLCK)
	{
		printf("上锁成功!\n");
		printf("由进程号为：%d进程上了写入锁！\n", getpid());		
	}else if(oldLock.l_type == F_UNLCK)
	{
		printf("由进程号为：%d进程解锁！\n", getpid());		
	}
}

int main()
{
	int fd = open("b.txt",O_CREAT|O_TRUNC|O_RDWR,0644);
	if (fd == -1)
	{
		printf("打开文件失败!\n");
		return 0;
	}
	char c;
	//给文件上锁
	SetLock(fd,F_WRLCK);
	sleep(10);
	scanf("%c",&c);
	SetLock(fd,F_UNLCK);
	close(fd);
	return 1;
}