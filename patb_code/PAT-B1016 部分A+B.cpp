#include<stdio.h>
int main(){
	long long a,b,pa=0,pb=0;
	int da,db;
	scanf("%lld %d %lld %d",&a,&da,&b,&db);
	while(a>0){
		int ya;
		ya=a%10;
		if(ya==da){
			pa=pa*10+da;
		}
		a=a/10;
	}
	while(b>0){
		int yb;
		yb=b%10;
		if(yb==db){
			pb=pb*10+db;
		}
		b=b/10;
	}
	long long sum=pa+pb;
	printf("%lld",sum);
	return 0;
}