#include "my.h"

int main()
{
	pid_t p;	
	int fd[2],rn,wn;	
	char rbuf[30],wbuf[30];
	memset(rbuf,0,sizeof(rbuf));
	memset(wbuf,0,sizeof(rbuf));
	pipe(fd);
	//psize
	p=fork();
	if(p<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(p==0)
	{
		close(fd[0]);
		sprintf(wbuf,"[child %d] is running.\n",getpid());
		while(1)
		{
		close(fd[0]);
		sprintf(rbuf,"1");
		for(int i=0;i<65537;i++)
			write(fd[1],rbuf,sizeof(rbuf));
		close(fd[1]);
		exit(0);
		}
	}
	else{
		wait(NULL);
		close(fd[1]);
		while(1)
		{
			rn=read(fd[0],rbuf,sizeof(rbuf));
			printf("[parent] read from pipe %d byte.Conten of pipe is %s\n",rn,rbuf);
			if(rn==0)
			{
				printf("[parent] read error.\n");
				break;
			}
		}	
		close(fd[0]);
		return 0;
	}
}
