#include<iostream> 
#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<string> 
#include<vector> 
#include<queue> 
#include<algorithm>
using namespace std;

const int maxn=510;
const int INF=1000000000;

int n,m;	
int st,ed;
int G[maxn][maxn],tim[maxn][maxn];
int d[maxn],t[maxn];
bool visd[maxn],vist[maxn];
vector<int> pred[maxn],pret[maxn];
vector<int> pathd,tempath,patht;
int mintim=INF,mincnt=INF;

void Dijkstra1(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(visd[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1)	return;
		visd[u]=true;			
		for(int v=0;v<n;v++){
			if(visd[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pred[v].clear();
					pred[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pred[v].push_back(u);
				}
			}
		}
	}
}

void DFS1(int v){
	if(v==st){
		tempath.push_back(v);
		int temptim=0;
		for(int i=tempath.size()-1;i>0;i--){
			int id=tempath[i],idnext=tempath[i-1];
			temptim+=tim[id][idnext];
		}
		if(temptim<mintim){
			mintim=temptim;
			pathd=tempath;
		}
		tempath.pop_back();
		return;
	}
	tempath.push_back(v);
	for(int i=0;i<pred[v].size();i++){
		DFS1(pred[v][i]);
	}
	tempath.pop_back();
}

void Dijkstra2(int s){
	fill(t,t+maxn,INF);
	t[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,mint=INF;
		for(int j=0;j<n;j++){
			if(vist[j]==false&&t[j]<mint){
				mint=t[j];
				u=j;
			}
		}
		if(u==-1)	return;
		vist[u]=true;
		for(int v=0;v<n;v++){
			if(vist[v]==false&&tim[u][v]!=INF){
				if(t[u]+tim[u][v]<t[v]){
					t[v]=t[u]+tim[u][v];
					pret[v].clear();
					pret[v].push_back(u);
				}else if(t[u]+tim[u][v]==t[v]){
					pret[v].push_back(u);
				}
			}
		}		
	}
}

void DFS2(int v){
	if(v==st){
		tempath.push_back(v);
		if(patht.size()==0||tempath.size()<patht.size()){
			patht=tempath;
		}
		tempath.pop_back();
		return;
	}
	tempath.push_back(v);
	for(int i=0;i<pret[v].size();i++){
		DFS2(pret[v][i]);
	}
	tempath.pop_back();
}

int main(){
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(tim[0],tim[0]+maxn*maxn,INF);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int v1,v2,way,l,t;
		scanf("%d%d%d%d%d",&v1,&v2,&way,&l,&t);
		if(way==0){//way==1时是单向，way==0时是双向 
			G[v1][v2]=G[v2][v1]=l;
			tim[v1][v2]=tim[v2][v1]=t;			
		}else{
			G[v1][v2]=l;
			tim[v1][v2]=t;			
		}
	}

	scanf("%d %d",&st,&ed);
	Dijkstra1(st);
	DFS1(ed);
	tempath.clear();
	Dijkstra2(st);
	DFS2(ed);
	
	if(pathd!=patht){
		printf("Distance = %d: ",d[ed]);
		for(int i=pathd.size()-1;i>=0;i--){
			printf("%d",pathd[i]);
			if(i>0){
				printf(" -> ");
			}else{
				printf("\n");
			}
		}
		printf("Time = %d: ",t[ed]);
		for(int i=patht.size()-1;i>=0;i--){
			printf("%d",patht[i]);
			if(i>0){
				printf(" -> ");
			}else{
				printf("\n");
			}
		}		
	}else{
		printf("Distance = %d; ",d[ed]);
		printf("Time = %d: ",t[ed]);
		for(int i=patht.size()-1;i>=0;i--){
			printf("%d",patht[i]);
			if(i>0){
				printf(" -> ");
			}else{
				printf("\n");
			}
		}		
		
	}

	
	
	
	return 0;
} 