#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;
const int maxn=100010;

int N,M;
int coin[maxn];
struct node{
	int v1,v2;
}res[maxn];

bool cmp(node a,node b){
	return a.v1<b.v1;
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&coin[i]);
	}
	sort(coin,coin+N);
//	for(int i=0;i<N;i++){
//		printf("%d ",coin[i]);
//	}
	int i=0,j=N-1,k=0;
	while(i<j){
		int sum=coin[i]+coin[j];
		if(sum==M){
			res[k].v1=coin[i];
//				printf("**v1=%d\n",coin[i]);
			res[k].v2=coin[j];
//				printf("##v2=%d\n",coin[j]);
			k++;
			break;
		}else if(sum>M){
			j--;
		}else{
			i++; 
		}
	}
	if(k==0){
		printf("No Solution");
	}else{
		printf("%d %d",res[0].v1,res[0].v2);
	}
	return 0;
}