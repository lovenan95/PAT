#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,sum,c;
	scanf("%d %d",&a,&b);
	sum=a+b;
	int cnt=0;
	for(c=sum;c!=0;c/=10){
		cnt++;
	}
	c=abs(sum);
	int sum1,sum2,sum3;
	if(cnt<=3){
		printf("%d",sum);
	}else if(cnt<=6){
		sum1=c%1000;
		sum2=(sum/1000)%1000;
		printf("%d,%03d",sum2,sum1);//%03d表示左填充0至三位 
	}else{
		sum1=c%1000;
		sum2=(c/1000)%1000;
		sum3=(sum/1000000);
		printf("%d,%03d,%03d",sum3,sum2,sum1);
	}
	
	return 0;
}