#include "my.h"

int main()
{
	pid_t tid;
	int i,ret;
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	for(i=0;i<100000;i++)
	{
		tid=fork();
	}
	gettimeofday(&tv2,&tz);
	printf("running time is %ld\n",tv2.tv_usec-tv1.tv_usec);
	return 0;
}
