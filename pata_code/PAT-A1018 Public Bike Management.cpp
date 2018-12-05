#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<stack> 
#include<string.h> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=1000000000;
int cmax,n,sp,m;
int G[maxn][maxn];
int d[maxn];
int weight[maxn];
bool vis[maxn]={false};
vector<int> pre[maxn];
vector<int> path,tempath;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<=n;i++){
		int u=-1,min=INF;
		for(int j=0;j<=n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1)	return;
		vis[u]=true;
		for(int v=0;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
int mincarry=INF,minback=0;
void DFS(int v){
	if(v==0){
		tempath.push_back(v);
		int tempcarry=0;
//		printf("******************\n");
		for(int i=tempath.size()-2;i>=0;i--){
			int now=tempath[i];
			tempcarry=tempcarry+cmax/2-weight[now];	
//			printf("tempath[i]=%d\n",tempath[i]);			
//			printf("tempcarry=%d\n",tempcarry);			
		}
		if(tempcarry<mincarry){
			mincarry=tempcarry;
			path=tempath;
		}else if(tempcarry==mincarry){
			
		}
		
		
		
		tempath.pop_back();
		return;
	}
	tempath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempath.pop_back();
}

int main(){
	scanf("%d%d%d%d",&cmax,&n,&sp,&m);	
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<m;i++){
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		G[a][b]=G[b][a]=dis;
	}
	Dijkstra(0);
	DFS(sp);	
	if(mincarry>0){
		printf("%d ",mincarry);		
	}else{
		printf("0 ");
	}

	for(int i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i>0){
			printf("->");
		}
	}
	if(mincarry>0){
		printf(" 0");		
	}else{
		printf(" %d",-mincarry);
	}
	
	
	return 0;
}