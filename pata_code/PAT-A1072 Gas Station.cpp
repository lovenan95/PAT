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

const int maxn=1020;
const int INF=1000000000;
int n,m,k;
double ds;
int G[maxn][maxn];
int d[maxn];
vector<int> path,tempath;
vector<int> pre[maxn];
int vis[maxn]={false};
int change(string str){
	int value;
	if(str[0]=='G'){
		str.erase(str.begin());
		sscanf(str.c_str(),"%d",&value);
		value+=n;
	}else{
		sscanf(str.c_str(),"%d",&value);
	}
	return value;
}

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=1;i<=n+m;i++){
		int u=-1,min=INF;
		for(int j=1;j<=n+m;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1)	return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(G[u][v]!=INF&&vis[v]==false){
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

int main(){
	fill(G[0],G[0]+maxn*maxn,INF);
	scanf("%d%d%d%lf",&n,&m,&k,&ds);
	for(int i=0;i<k;i++){
		string a,b;
		int dis;
		cin>>a>>b>>dis;
		int u,v;
		u=change(a);
		v=change(b);
		G[u][v]=G[v][u]=dis;
	}
	int minid=-1;
	int ansdis=-1,anssum=INF;
	for(int i=n+1;i<=m+n;i++){
		int sumdis=0,mindis=INF;
		memset(vis,false,sizeof(vis));
		Dijkstra(i);
		for(int j=1;j<=n;j++){
			if(d[j]>ds){
				mindis=-1;
				break;
			}
			if(mindis>d[j]){
				mindis=d[j];
			}
			sumdis+=d[j];
		}
		if(mindis==-1)	continue;
		if(mindis>ansdis){
			ansdis=mindis;
			anssum=sumdis;
			minid=i;
		}else if(mindis==ansdis){
			if(anssum>sumdis){
				anssum=sumdis;
				minid=i;
			}
		}
	}
	if(minid==-1){
		printf("No Solution\n");
	}else{
		printf("G");
		printf("%d\n",minid-n);
		double resdis=1.0*ansdis;
		printf("%.1f %.1f",resdis,1.0*anssum/n);
	}
	return 0;
}







