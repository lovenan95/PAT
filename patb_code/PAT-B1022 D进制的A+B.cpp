#include <stdio.h>
int main(){
	int a,b,d;
	scanf("%d %d %d",&a,&b,&d);
	int s;
	s=a+b;
	int z[50]={0};
	int i=0;
	do{
		z[i++]=s%d;
		s/=d;
	}while(s!=0);
	i-=1;
	while(i!=-1){
		printf("%d",z[i--]);
	}	
	return 0;
}