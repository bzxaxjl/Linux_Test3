/*由父进程创建三个子进程，child1，child2，child3，两个管道p1，p2,child1把0-65535写到管道p1中，child2读出管道的0-65535并显示，然后又写到管道p2中，child3读取管道p3并求和*/
#include "my.h"
#define NUM 65535
int main(){
	pid_t p1,p2,p3;	
	int s1,s2,s3;
	int rn1,rn2;
	long sum=0;
	char r1buf[25],w1buf[25],r2buf[25];
	memset(r1buf,0,sizeof(r1buf));
	memset(w1buf,0,sizeof(w1buf));
	memset(r2buf,0,sizeof(r2buf));
	//建立管道
	int fdo[2],fdt[2];
	pipe(fdo);
	pipe(fdt);
	p1=fork();
	if(p1<0){
		perror("fork son processor one error!\n");
		return -1;
	}
	else if(p1==0){
		printf("[child %d]\t[parent %d]\n",getpid(),getppid());
		close(fdo[0]);//关闭管道1的读端
		close(fdt[0]);//关闭管道2的读端
		close(fdt[1]);//关闭管道2的写端
		for(int i=0;i<=NUM;i++){
			sprintf(w1buf,"%d\n",i);
			write(fdo[1],w1buf,sizeof(w1buf));//w1buf内容写到管道1	
		}
		close(fdo[1]);
		//printf("test over1\n");
		exit(9);
	}
	else{
		p2=fork();
		if(p2<0){
			perror("fork son processor two error!\n");
			return -1;
		}
		else if(p2==0){
			printf("[child %d]\t[parent %d]\n",getpid(),getppid());
			close(fdo[1]);//关闭管道1的写端	
			close(fdt[0]);//关闭管道2的读端
			while((rn1=read(fdo[0],r1buf,sizeof(r1buf)))!=0){//把管道1的东西读取到r1buf	
					printf("%s",r1buf);
					if(write(fdt[1],r1buf,sizeof(r1buf))==-1){//把r1buf内容写到管道2
						printf("write to pipe2 fail\n");
					}
			}//为什么会一直卡在这儿？p1的sprintf哪儿没有加上\n...
			//printf("test over2\n");//？
			close(fdo[0]);
			close(fdt[1]);
			exit(19);
		}
		else{	
			p3=fork();
			if(p3<0){
				perror("fork son processor three error!\n");
				return -1;
			}
			else if(p3==0){
				printf("[child %d]\t[parent %d]\n",getpid(),getppid());
				close(fdt[1]);//关闭管道2的写端
				close(fdo[0]);//关闭管道1的读端	
				close(fdo[1]);//关闭管道1的写端
				while((rn2=read(fdt[0],r2buf,sizeof(r2buf)))!=0){//管道2的内容读取到r2buf
					sum += atoi(r2buf);
					//printf("sum : %d  r2buf : %s\n",sum,r2buf);			
				}
				close(fdt[0]);
				printf("sum : %ld\n",sum);
				exit(99);
				//printf("test over3\n");
			}	
			else{	
				close(fdt[1]);//关闭管道2的写端
				close(fdt[0]);//关闭管道2的读端
				close(fdo[0]);//关闭管道1的读端	
				close(fdo[1]);//关闭管道1的写端
				wait(&s1);
				wait(&s2);
				//rintf("test over!\n");//p1成功退出，但是p2，p3都没有退出，为什么呢？
				wait(&s3);
				printf("%d exit code is %d\n%d exit code is %d\n%d exit code is %d\n",p1,WEXITSTATUS(s1),p2,WEXITSTATUS(s2),p3,WEXITSTATUS(s3));
				return 0;
			}
		}
	}
}

