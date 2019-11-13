#include "my.h"
static void __attribute__ ((constructor)) before_main(void)
{
	printf("----Before main!----\n");
}
static void __attribute__ ((constructor)) after_main(void)
{
	printf("----After main!----\n");
}
static void callback1()
{
	printf("----callback1----\n");
}
static void callback2()
{
	printf("----callback2----\n");
}

int main(void)
{
	atexit(callback1);
	atexit(callback2);
	char buf[] = {"puts use full buffer"};
	//while(1);
	//_exit(0);
	exit(0);
	//return 0;	
}
