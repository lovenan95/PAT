#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<math.h> 
#include<algorithm>
using namespace std;

int m,n;

bool isprime(int a){
	if(a<=1)	return false;
	int s=(int) sqrt(1.0*a);
	for(int i=2;i<=s;i++){
		if(a%i==0)
			return false;
	}
	return true;
} 

bool hashtab[10010]={false};

int main(){
	scanf("%d%d",&m,&n);
	while(isprime(m)==false){
		m++;
	}
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		int idx=temp%m;
		if(hashtab[idx]==false){
			hashtab[idx]=true;
			printf("%d",idx);
		}else{
			int j;
			for(j=1;j<m;j++){
				if(hashtab[(temp+j*j)%m]==false){
					hashtab[(temp+j*j)%m]=true;
					printf("%d",(temp+j*j)%m);
					break;
				}
			}
			if(j>=m){
				printf("-");
			}
		}
		if(i<n-1){
			printf(" ");
		}
	}		
	
	
	
	
	
	
	
	
	return 0;
}