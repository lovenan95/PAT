#include<stdio.h>
struct factor{
	int p;
	int k;
}fac[10];
const int maxn=1000001;
bool p[maxn]={0};
int prime[maxn],num=0;
void findprime(int n){
	for(int i=2;i<maxn;i++){
		for(int j=i+i;j<maxn;j=j+i){
			p[j]=1;
		}
		if(p[i]==0){
			prime[num++]=i;
		}
		if(num>n){
			break;
		}
	}
}
int main(){
	int N,n,cnt=0;
	scanf("%d",&N);
	findprime(N);
	n=N;
	for(int i=0;i<10;i++){
		fac[i].k=0;
	}
	if(n==1){
		printf("1=1");
	} else{
		printf("%d=",N);
	}
	for(int i=0;i<num;i++){
		while(n%prime[i]==0&&n!=0&&n!=1){
			fac[cnt].p=prime[i];
			fac[cnt].k++;
			n=n/prime[i];
			if(n%prime[i]!=0)
				cnt++;			
		}
	}
//	if(n!=1){
//		fac[cnt].p=n;
//		fac[cnt].k=1;
//	}
	if(fac[0].k!=0&&fac[0].k!=1){
			printf("%d^%d",fac[0].p,fac[0].k);
		}
	else if(fac[0].k!=0&&fac[0].k==1){
		printf("%d",fac[0].p);
	}
	for(int i=1;i<cnt;i++){
		if(fac[i].k!=0&&fac[i].k!=1){
			printf("*%d^%d",fac[i].p,fac[i].k);
		}
		else if(fac[i].k!=0&&fac[i].k==1){
			printf("*%d",fac[i].p);
		}
	}
	return 0;
}