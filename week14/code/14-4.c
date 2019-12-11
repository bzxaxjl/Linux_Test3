#include "my.h"
void fun (void *arg)
{
	int TID = pthread_self();
	printf("worker---%d : gettid return %d\n",TID,TID);
	printf("worker---%d : pthread_self return %p\n",TID,(void*)pthread_self());
	printf("work---%d:will exit!\n",TID);
	pthread_exit(NULL);
	return ;
}
int main()
{
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid,NULL,(void*(*)()) fun,NULL);
	if(ret !=0)
	{
		perror("create failed!\n");
		return -1;
	}
	pthread_join(tid,NULL);
	printf("Master %d : ALL Done!\n",getpid());
	return 0;
}
