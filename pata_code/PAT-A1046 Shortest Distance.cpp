#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100010;
int N,M,s,e,dis1=0,dis2=0,dis=0;
int d[maxn]={0};
int dsum[maxn]={0};
int main(){
	scanf("%d",&N);
	int sum=0;
	for(int i=1;i<=N;i++){
		scanf("%d",&d[i]);
		sum+=d[i];
		dsum[i]=sum;//Ô¤´æ1ºÅË³Ê±Õëµ½iºÅÏÂÒ»¸ö½ÚµãµÄ¾àÀë 
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d %d",&s,&e);
		int e1=max(s,e),s1=min(s,e);
		dis1=dsum[e1-1]-dsum[s1-1];		
		printf("%d\n",min(dis1,sum-dis1));
	}
	return 0;
}
