#include "my.h"
 int g=10;
int main()
{
	int l=20;
	static int s =30;
	pid_t pid;
	pid =fork();
	if(pid<0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(pid==0) 
	{
		int p=99;
		printf("-----address of var----\n");
		printf("&g=%16p\n l=%16p\n &s=%16p\n p=%16p\n",&g,&l,&s,&p);	
		g=100;
		l=200;
		s=300;
		p=999;
		printf("value in child\n");
		printf("&g=%d\nl=%d\n&s=%d\np=%d\n",g,l,s,p);
		return 0;
		//exit(0);
		//atexit(0);
	}
	else{
		printf("-----address of var in parent----\n");
		printf("parent:\n&g=%16p\nl=%16p\n&s=%16p\n",&g,&l,&s);	
		g=100;
		l=200;
		s=300;
		printf("value in parent\n");
		printf("parent:&g=%d\nl=%d\n&s=%d\n",g,l,s);
		return 0;
	}
}
