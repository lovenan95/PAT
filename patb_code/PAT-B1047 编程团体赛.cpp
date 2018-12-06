#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;

int N,id,score,team;
int sum[1010]={0};

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d-%d %d",&team,&id,&score);
		sum[team]+=score;
	}
	int maxt,maxs=0;
	for(int i=0;i<1010;i++){
		if(maxs<sum[i]){
			maxs=sum[i];
			maxt=i;
		}
	}
	printf("%d %d",maxt,maxs);
} 