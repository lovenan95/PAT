#include<stdio.h>
const int maxn=1000001;
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int p[maxn]={0},prime[maxn],num=0;
	for(int i=2;i<maxn;i++){
		for(int j=i+i;j<maxn;j=j+i){
			p[j]=1;
		}
		if(p[i]==0){
			prime[num++]=i;
		}
	}
	int cnt=0;
	for(int i=m-1;i<n;i++){
		printf("%d",prime[i]);
		cnt++;
		if(cnt==10){
			printf("\n");
			cnt=0;
		}else if(i!=n-1){
			printf(" ");
		}
	}
	return 0;
}