#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int writeToarr (int a[])
{
	int i=0,n,j=0;
	FILE *fp;//定义文件指针
	//up all for the timeline
	if((fp=fopen("123.txt","r"))==NULL)//如果文件名不存在
	{
		printf("cantfind the file!");
	}//则输出没有找到文件
	while(!feof(fp))//当不为文件结尾时
	{
		fscanf(fp,"%d",&a[i++]);//逐个将文件中的数据放入数组中
	}
	printf("排序前数据读入数组中成功！\n");
	fclose(fp);//关闭文件
}
void writefile(int a[])//生成随机数并写入文件 
{
	FILE *fp;
	int i=0;
	int h, rawdata[100];
	printf("调用rawdata\n");
  	srand((unsigned int)time(NULL));//设置当前时间为种子
    for (i = 0; i < 100; ++i){
        rawdata[i] = rand()%1000+1;//产生1~1000的随机数
    }
	fp=fopen("123.txt","w");//打开文件以便写入数据
	
	for (i = 0; i < 100; i++) 
	{ //将a数组中的整数写入fp指向的123.txt文件
		fprintf(fp,"%d\n",rawdata[i]);
	}
	fclose(fp); //写入完毕，关闭文件
} 
void sortdata(int * a, int len) {//排序函数 
    if( len <= 1 ) return;
    int i=0, j=len-1, t, temp = a[0];
    while( i<j ) {
        while( a[j]>temp && j>i ) j--; a[i] = a[j];
        while( a[i]<=temp && i<j ) i++; a[j] = a[i];
    }
    a[i] = temp;
    sortdata(a, i);
    sortdata(a+i+1, len-i-1);
    return;
}
void showarr(int *a){
	int h=0,rawdata[100];
	printf("文件名：123.txt");
	for(h=0; h<100; h++) {//输出排序后的数据 
    	printf("%d   ",rawdata[h]);
    }
}
void writedata(int a[])//将排序好的数据写入文件中 
{
	FILE *fp;
	int i,b[100];
	fp=fopen("123.txt","w");
	printf("\n调用writedata\n");
	for (i = 0; i < 100; i++) 
	{ 
		b[i]=a[i];
	}
	for (i = 0; i < 100; i++) 
	{
		fprintf(fp,"%d\n",b[i]);
	}
	fclose(fp); 
	printf("\n排序后数组写入文件成功!\n");
}
int main()
{
	int begintime,endtime;
	int i = 0;
	int h=0, rawdata[100];
	
  	writefile(rawdata);//生成初始并写入文件中 
    writeToarr(rawdata);//读取文件到数组rawdata[]中 
	begintime=clock();	//计时开始   
	sortdata(rawdata, 100);//排序
	
	for(h=0; h<100; h++) {//输出排序后的数据 
    	printf("%d   ", rawdata[h]);
    }
  	writedata(rawdata);//写入文件 	
  	showarr(rawdata);
	endtime = clock();	//计时结束	
	printf("\nRunning Time：%dms\n", endtime-begintime);
    return 0;
}






