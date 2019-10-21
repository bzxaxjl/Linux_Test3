#include"dylib.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void showarray (int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d : %4d\n",i,a[i]);
}
void initarray(int *a,int n)
{
	int i;
    for (i = 0; i < 5; ++i){
	srand((unsigned int)time(0));//设置当前时间为种子
        a[i] = rand()%100+1;//产生1~100的随机数
    }
}
