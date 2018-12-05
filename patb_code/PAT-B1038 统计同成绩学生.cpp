#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;

int N,K;
int score,query;
int hashtab[110]={0};
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&score);	
		hashtab[score]++;
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d",&query);	
		printf("%d",hashtab[query]);
		if(i<K-1){
			printf(" ");
		}
	}
	
	
	
	
	return 0;
} 