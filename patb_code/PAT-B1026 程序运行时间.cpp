#include<stdio.h>
#include<math.h>
int main(){
	int c1,c2;
	scanf("%d %d",&c1,&c2);
	int time=c2-c1;
	int hour=time/100/3600;
	int min=(time/100%3600)/60;
	double temp=time/100.0;
	temp=temp-hour*3600-min*60;
	int sec=round(temp);
	printf("%02d:%02d:%02d",hour,min,sec);
	return 0;
} 