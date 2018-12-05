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
const int INF=1000000000;
const int maxn=600;
int n,m,st,ed;
int G[maxn][maxn];
int cost[maxn][maxn];
bool vis[maxn]={false};
int d[maxn];
vector<int> tempath,path;
vector<int> pre[maxn];

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(d[j]<min&&vis[j]==false){
				min=d[j];
				u=j;
			}
		}
		if(u==-1)	return;
		vis[u]=true;
		for(int v=0;v<n;v++){
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
int mincost=INF;
void DFS(int v){
	if(v==st){
		tempath.push_back(v);
		int tempcost=0;
		for(int i=tempath.size()-1;i>=1;i--){
			int id=tempath[i],idnext=tempath[i-1];
			tempcost+=cost[id][idnext];
		}
		if(tempcost<mincost){
			mincost=tempcost;
			path=tempath;
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
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int c1,c2,dis,cst;
		scanf("%d%d%d%d",&c1,&c2,&dis,&cst);
		G[c1][c2]=G[c2][c1]=dis;
		cost[c1][c2]=cost[c2][c1]=cst;
	}	
	Dijkstra(st);
	DFS(ed);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d ",path[i]);
	}	
	printf("%d %d",d[ed],mincost);
	return 0;
} 











