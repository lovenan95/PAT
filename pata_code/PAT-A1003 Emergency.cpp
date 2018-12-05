#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<set>
#include<map>
using namespace std;

const int INF=1000000000;
const int maxn=600;
int n,m,st,ed;
int G[maxn][maxn],weight[maxn];
int d[maxn],w[maxn];
bool vis[maxn]={false};
vector<int> path,tempath;
vector<int> pre[maxn];

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
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

int maxw=0,num=0;
void DFS(int v){
	if(v==st){
		num++;
		tempath.push_back(v);
		int tempw=0;
		for(int i=tempath.size()-1;i>=0;i--){
			int id=tempath[i];
			tempw+=weight[id];
		}
		if(maxw<tempw){
			maxw=tempw;
			path=tempath;
		}	
		
		tempath.pop_back(); 
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
	for(int i=0;i<n;i++){
		int we;
		scanf("%d",&we);
		weight[i]=we;
	}
	for(int i=0;i<m;i++){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		G[a][b]=G[b][a]=l;
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d",num,maxw);
	return 0;
}














