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
const int maxn=1010;
const int INF=1000000000;
int n,m,k;
int st,ed;
int line[maxn][maxn]={0};
int G[maxn][maxn];
bool vis[maxn]={false};
int d[maxn];
vector<int> pre[maxn];
vector<int> tempath,path;
map<int,int> sti;
map<int,int> its;
int idx=0;
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<idx;i++){
		int u=-1,min=INF;
		for(int j=0;j<idx;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1)	return;
		vis[u]=true;
		for(int v=0;v<idx;v++){
			if(vis[v]==false&&G[u][v]!=0){
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
int mintrans=INF;
void DFS(int v){
	if(v==sti[st]){
		tempath.push_back(v);
		int temptrans=0;
		for(int i=tempath.size()-2;i>0;i--){
			int id=tempath[i],idnext=tempath[i-1],idpre=tempath[i+1];
			if(line[id][idnext]!=line[id][idpre]){
				temptrans++;
			}
		}
		if(temptrans<mintrans){
			mintrans=temptrans;
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
	scanf("%d",&n);
	memset(G,0,sizeof(G));
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		int s0;
		scanf("%d",&s0);
		if(sti.find(s0)==sti.end()){
			sti[s0]=idx;
			its[idx]=s0;
			idx++;			
		}
		for(int j=2;j<=m;j++){
			int temp;
			scanf("%d",&temp);
			if(sti.find(temp)==sti.end()){
				sti[temp]=idx;
				its[idx]=temp;
				idx++;			
			}			
			line[sti[temp]][sti[s0]]=i;
			line[sti[s0]][sti[temp]]=i;
			G[sti[s0]][sti[temp]]=G[sti[temp]][sti[s0]]=1;
			s0=temp;
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&st,&ed);
		memset(vis,false,sizeof(vis));
		mintrans=INF;
		tempath.clear();
		path.clear();
		for(int i=0;i<idx;i++){
			pre[i].clear();
		}
		Dijkstra(sti[st]);		
		DFS(sti[ed]); 
		printf("%d\n",d[sti[ed]]);
		int now=sti[st];
		if(mintrans==0){
			printf("Take Line#%d from %04d to %04d.\n",line[path[1]][sti[ed]],st,ed);			
			continue;
		}
		for(int j=path.size()-2;j>0;j--){
			int id=path[j],idnext=path[j-1],idpre=path[j+1];
			if(line[id][idnext]!=line[idpre][id]){
				printf("Take Line#%d from %04d to %04d.\n",line[id][idpre],its[now],its[id]);
				now=id;
			}
			if(j==1){
				printf("Take Line#%d from %04d to %04d.\n",line[id][idnext],its[id],ed);
			}
		}
	}
	return 0;
} 
