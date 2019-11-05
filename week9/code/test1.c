#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
static void __attribute__ ((constructor)) before_main(void)
{
	printf("Running before main!\n");
}
int main(int argc,char *argv[])
{
	int i;
	printf("test1:pid = %d,ppid = %d\n",getpid(),getppid());
	for(i=0;i<0;i++){
		printf("test1 : %d : %s\n",i,argv[i]);	
	}
	return 0;
}
