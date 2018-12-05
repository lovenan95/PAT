#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<math.h> 
#include<algorithm>
using namespace std;

long long n;
long long res[100010];
int cmax=0;

int main(){
	scanf("%lld",&n);
	int cnt=0;
	bool flag=false;
	int s=(int) sqrt(1.0*n);
	for(int i=2;i<=s;i++){
		int k=i;
		cnt=0;
		long long mul=1;
		if(n%k!=0){
			continue;
		}	
		while(mul<n){
			cnt++;
			mul=mul*k;
			if(n%mul==0){
				if(cmax<cnt){
					cmax=cnt;
					int r=0;
					for(int j=i;j<=k;j++){
						res[r]=j;
						r++;
					}
				}
			}
			k++;
		}
	} 
	if(cmax>=1){
		printf("%d\n",cmax);		
		for(int j=0;j<cmax;j++){
			printf("%lld",res[j]);
			if(j<cmax-1){
				printf("*");
			}
		}
	}
	if(cmax==0){
		printf("1\n");
		printf("%lld",n);
	}
	
	return 0;
}
 