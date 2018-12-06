#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<math.h>
#include<stdlib.h>
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

bool isprime(int k){
	if(k<=1)	return false;
	int s=(int) sqrt(1.0*k);
	for(int i=2;i<=s;i++){
		if(k%i==0)
			return false;
	}
	return true;
}

int change(int a,int r){
	int i=0;
	int str[100010]={0};
	while(a>0){
		str[i]=a%r;
		a/=r;
		i++;
	}
	int res=0;
	for(int k=0;k<i;k++){
		res=res*r+str[k];
	}
	
	return res;		
}

int main(){
	int n,radix;
	while(scanf("%d",&n)!=EOF){
		if(n<0)	return 0;
		scanf("%d",&radix);
		
		if(isprime(n)==false){
			printf("No\n");
		}else{
			int res=change(n,radix);
			if(isprime(res)==false){
				printf("No\n");
			}else{
				printf("Yes\n");
			}			
			
		}

		
		
		
	}
	
	
	
	
	
	return 0;
}