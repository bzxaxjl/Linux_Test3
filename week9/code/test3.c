#include"my.h"

static void __attribute__((constructor)) before_main()
{
	printf("before main test\n");
}
static void callback1(void)
{
	printf("callback1 is running\n");
}
static void callback2(void)
{
	printf("callback2 is running\n");
}
static void callback3(void)
{
	printf("callback3 is running\n");
}

int main(int argc,char *argv[])
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);	
	int i;
	printf("test2:pid=%d ,ppid = %d\n",getpid(),getppid());
	for(i=0;i<argc;i++)
	{
		printf("test2: %d ,%s\n",i,argv[i]);
	}

}
