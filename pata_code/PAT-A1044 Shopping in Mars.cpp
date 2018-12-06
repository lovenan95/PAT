#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

const int maxn=100010;
int n,m;
int a[maxn];
int sum[maxn]={0};

int main(){
	scanf("%d%d",&n,&m);
	int s=0,cnt=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
		sum[cnt++]=s;
	}
	int flag=false;
	int tmax=1000000000;
	for(int i=1;i<=n;i++){
		int j=lower_bound(sum+i,sum+n+1,sum[i-1]+m)-sum;
		if(sum[j]-sum[i-1]==m){
			printf("%d-%d\n",i,j);
			flag=true;
		}else if(sum[j]-sum[i-1]>m&&tmax>sum[j]-sum[i-1]){
			tmax=sum[j]-sum[i-1];
		}			
	}
	if(flag==false){
		for(int i=1;i<=n;i++){
			int j=lower_bound(sum+i,sum+n+1,sum[i-1]+tmax)-sum;
			if(sum[j]-sum[i-1]==tmax){
				printf("%d-%d\n",i,j);
			}
		}		
	}
	return 0;
} 











