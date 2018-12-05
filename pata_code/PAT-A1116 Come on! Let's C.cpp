#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int N,K;

int rk[10010];

bool isprime(int x){
	int sqr=sqrt(1.0*x);
	for(int i=2;i<=sqr;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
	
}

int main(){
	memset(rk,-1,sizeof(rk));
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int id;
		scanf("%d",&id);
		rk[id]=i;
	}
	scanf("%d",&K);
	for(int i=1;i<=K;i++){
		int query;
		scanf("%d",&query);
		if(rk[query]==-1){
			printf("%04d: Are you kidding?\n",query);
		}else if(rk[query]==0){
			printf("%04d: Checked\n",query);
		}else if(isprime(rk[query])==true&&rk[query]!=1){
			printf("%04d: Minion\n",query);
			rk[query]=0;
		}else if(rk[query]==1){
			printf("%04d: Mystery Award\n",query);
			rk[query]=0;
		}else{
			printf("%04d: Chocolate\n",query);
			rk[query]=0;			
		}
		
	}
	
	
	
	
	
	
	
	return 0;
}








