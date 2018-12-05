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
const int maxn=220;
const int INF=1000000000;
int n,k,st,ed;
map<string,int> sti;
map<int,string> its;
int G[maxn][maxn],weight[maxn];
int d[maxn];
bool vis[maxn]={false};
vector<int> pre[maxn];
vector<int> path,tempath;
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
			if(vis[v]==false&&d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			}else if(d[u]+G[u][v]==d[v]){
				pre[v].push_back(u);
			}
		}
	}
}
int numc=0,maxh=0,maxavgh=0;
void DFS(int v){
	if(v==0){
		numc++;
		tempath.push_back(v);
		int temph=0,tempavgh=0;
		for(int i=tempath.size()-1;i>=0;i--){
			temph+=weight[tempath[i]];
		}
		tempavgh=temph/(tempath.size()-1);		
		if(temph>maxh){
			maxh=temph;
			maxavgh=tempavgh;/*!!!!!!!*/
			path=tempath;
		}else if(temph==maxh){
			if(tempavgh>maxavgh){
				maxavgh=tempavgh;
				path=tempath;
			}
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
	fill(G[0],G[0]+maxn*maxn,INF);
	memset(weight,0,sizeof(weight));
	scanf("%d%d",&n,&k);
	string start;
	cin>>start;
	sti[start]=0;
	its[0]=start;
	int cntc=1;
	for(int i=0;i<n-1;i++){
		string temp;
		cin>>temp;
		sti[temp]=cntc;
		its[cntc]=temp;
		scanf("%d",&weight[cntc]);
		cntc++;	
	}
	for(int i=0;i<k;i++){
		string c1,c2;
		int cst;
		cin>>c1>>c2>>cst;
		G[sti[c1]][sti[c2]]=G[sti[c2]][sti[c1]]=cst;
	}
	Dijkstra(0);
	DFS(sti["ROM"]);
	printf("%d %d %d %d\n",numc,d[sti["ROM"]],maxh,maxavgh);
	for(int i=path.size()-1;i>=0;i--){
		cout<<its[path[i]];
		if(i>0){
			printf("->");
		}
	}
	return 0;
}









