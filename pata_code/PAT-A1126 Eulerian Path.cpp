#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<set>
using namespace std;

const int maxn=510;
int n,m;
int G[maxn][maxn],degree[maxn]={0};
bool vis[maxn]={false};
int cnt=0;

void DFS(int v){
	vis[v]=true;
	cnt++;
//	cout<<"cnt="<<cnt<<"\n";
	for(int i=1;i<=n;i++){
		if(G[v][i]!=0&&vis[i]==false){
			DFS(i);
		}
	}
}
int main(){
	fill(G[0],G[0]+maxn*maxn,0);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
		degree[u]++;
		degree[v]++;
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		printf("%d",degree[i]);
		if(i<n){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	for(int i=1;i<=n;i++){
		if(degree[i]%2!=0){
			flag++;
		}
	}
	DFS(1);
//	printf("cnt=%d\n",cnt);
	if(flag==0&&cnt==n){
		printf("Eulerian\n");
	}else if(flag==2&&cnt==n){
		printf("Semi-Eulerian\n");
	}else{
		printf("Non-Eulerian\n");
	}
	return 0;
}








