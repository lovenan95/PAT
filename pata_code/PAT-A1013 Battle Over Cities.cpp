#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
using namespace std;

const int maxn=1010;
const int INF=1000000000;
int n,m,k;
int G[maxn][maxn];
bool vis[maxn];
int query;
void DFS(int v){
	if(v==query){
		return;
	}
	vis[v]=true;
	for(int i=1;i<=n;i++){
		if(vis[i]==false&&G[i][v]!=INF){
			DFS(i);
		}
	}
} 

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	for(int i=0;i<k;i++){
		scanf("%d",&query);
		int block=0;
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(i!=query&&vis[i]==false){
				DFS(i);
				block++;
			}
		}
		printf("%d\n",block-1);
	}
	
	
	
	
	
	return 0;
} 











