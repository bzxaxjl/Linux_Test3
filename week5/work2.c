#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int writeToarr (int a[])
{
	int i=0,n,j=0;
	FILE *fp;//�����ļ�ָ��
	//up all for the timeline
	if((fp=fopen("123.txt","r"))==NULL)//����ļ���������
	{
		printf("cantfind the file!");
	}//�����û���ҵ��ļ�
	while(!feof(fp))//����Ϊ�ļ���βʱ
	{
		fscanf(fp,"%d",&a[i++]);//������ļ��е����ݷ���������
	}
	printf("����ǰ���ݶ��������гɹ���\n");
	fclose(fp);//�ر��ļ�
}
void writefile(int a[])//�����������д���ļ� 
{
	FILE *fp;
	int i=0;
	int h, rawdata[100];
	printf("����rawdata\n");
  	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
    for (i = 0; i < 100; ++i){
        rawdata[i] = rand()%1000+1;//����1~1000�������
    }
	fp=fopen("123.txt","w");//���ļ��Ա�д������
	
	for (i = 0; i < 100; i++) 
	{ //��a�����е�����д��fpָ���123.txt�ļ�
		fprintf(fp,"%d\n",rawdata[i]);
	}
	fclose(fp); //д����ϣ��ر��ļ�
} 
void sortdata(int * a, int len) {//������ 
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
	printf("�ļ�����123.txt");
	for(h=0; h<100; h++) {//������������� 
    	printf("%d   ",rawdata[h]);
    }
}
void writedata(int a[])//������õ�����д���ļ��� 
{
	FILE *fp;
	int i,b[100];
	fp=fopen("123.txt","w");
	printf("\n����writedata\n");
	for (i = 0; i < 100; i++) 
	{ 
		b[i]=a[i];
	}
	for (i = 0; i < 100; i++) 
	{
		fprintf(fp,"%d\n",b[i]);
	}
	fclose(fp); 
	printf("\n���������д���ļ��ɹ�!\n");
}
int main()
{
	int begintime,endtime;
	int i = 0;
	int h=0, rawdata[100];
	
  	writefile(rawdata);//���ɳ�ʼ��д���ļ��� 
    writeToarr(rawdata);//��ȡ�ļ�������rawdata[]�� 
	begintime=clock();	//��ʱ��ʼ   
	sortdata(rawdata, 100);//����
	
	for(h=0; h<100; h++) {//������������� 
    	printf("%d   ", rawdata[h]);
    }
  	writedata(rawdata);//д���ļ� 	
  	showarr(rawdata);
	endtime = clock();	//��ʱ����	
	printf("\nRunning Time��%dms\n", endtime-begintime);
    return 0;
}






