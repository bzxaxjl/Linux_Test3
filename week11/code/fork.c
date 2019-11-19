#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
int main(int argc, char *args[])
{
	// 打开文件描述符：在fork之前打开才能让父进程和子进程共享
	int fd = open("a.txt", O_RDONLY);
	// 判断文件打开是否成功
	if (fd == -1)
	{
		printf("File open failed : %s\n", strerror(errno));
	}
	
	// 定义读取文件的缓冲区
	char buf[1024];
	
	// 执行fork函数
	pid_t pd = fork();
	// 判断fork是否成功
	if (pd == -1)
	{
		printf("fork failed : %s\n", strerror(errno));
	}
	
	// 通过if...else...执行父子进程的特有代码
	if (pd > 0)
	{		
		printf("father fd = %d\n", fd);
		close(fd);	
	}
	else
	{
		// 清空缓冲区内存
		memset(buf, 0, sizeof(buf));
		// 读取文件内容
		printf("reading of son:");
		read(fd, buf, sizeof(buf));
		// 将读取到的内容显示到屏幕上
		printf("%s", buf);
		printf("son fd = %d\n", fd);
		close(fd);	
	}
	
	return 0;
}


