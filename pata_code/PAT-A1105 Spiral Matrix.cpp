#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<stack> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;
const int maxn=10010;

int N,m,n;
int a[maxn];
int spi[maxn][maxn];

bool cmp(int a,int b){
	return a>b;
} 

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	if(N==1){
		printf("%d",a[1]);
		return 0;
	}
	sort(a+1,a+N+1,cmp);
	int m=(int)ceil(sqrt(1.0*N));
	while(N%m!=0){
		m++;
	}	
	m=max(m,N/m);
	int n=N/m;
	int cnt=1;
	int k=0;
	while(cnt<=N){
		for(int i=1+k;i<=n-1-k;i++){
			spi[1+k][i]=a[cnt++];
			if(cnt>N) break;
//			cout<<spi[1+k][i]<<" ";
		}
		if(cnt>N) break;
		for(int i=1+k;i<=m-1-k;i++){
			spi[i][n-k]=a[cnt++];
			if(cnt>N) break;
//			cout<<spi[i][n-k]<<" ";
		}
		if(cnt>N) break;		
		for(int i=n-k;i>=2+k;i--){
			spi[m-k][i]=a[cnt++];
			if(cnt>N) break;
//			cout<<spi[m-k][i]<<" ";
		}
		if(cnt>N) break;		
		for(int i=m-k;i>=2+k;i--){
			spi[i][1+k]=a[cnt++];
			if(cnt>N) break;
//			cout<<spi[i][1+k]<<" ";
		}
		if(cnt>N) break;
		k++;
		if(cnt==N){
			if(m%2==1){
				spi[(m+1)/2][(m+1)/2]=a[N];
				cnt++;					
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d",spi[i][j]);
			if(j<n){
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
	return 0;
}










