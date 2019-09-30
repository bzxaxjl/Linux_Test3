#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int * a, int len) {
    if( len <= 1 ) return;

    int i=0, j=len-1, t, temp = a[0];
    while( i<j ) {
        while( a[j]>temp && j>i ) j--; a[i] = a[j];
        while( a[i]<=temp && i<j ) i++; a[j] = a[i];
    }
    a[i] = temp;
    sort(a, i);
    sort(a+i+1, len-i-1);
    return;
}
int main(void) {
	int begintime,endtime;
	int i = 0;
	//up all for the timeline
	int h, a[100];
  	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
    for (i = 0; i < 100; ++i){
        a[i] = rand()%1000+1;//����1~100�������
    }
	begintime=clock();	//��ʱ��ʼ   	
	sort(a, 100);
    for(h=0; h<100; h++) {
        printf("%d ", a[h]);
    }
	endtime = clock();	//��ʱ����
	printf("\n\nRunning Time��%dms\n", endtime-begintime);
    return 0;
}
