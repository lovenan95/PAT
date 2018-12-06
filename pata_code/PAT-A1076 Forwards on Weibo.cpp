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

const int maxn=1010;
const int INF=1000000000;

vector<int> adj[maxn];
bool vis[maxn]={false};
int n,l;
int level[maxn]={0};
int cnt=-1;
void BFS(int root){
	queue<int> q;
	q.push(root);
	level[root]=0;
	vis[root]=true;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(level[top]>l){
			break;
		}
//		printf("level=%d  top=%d \n",level[top],top);
		cnt++;		
		for(int i=0;i<adj[top].size();i++){
			int v=adj[top][i];
			if(vis[v]==false){
				vis[v]=true;
				level[v]=level[top]+1;
				q.push(v);				
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&l);	
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int usl;
			scanf("%d",&usl);
			adj[usl].push_back(i);
		}
	}
	
	
	int qk;
	scanf("%d",&qk);
	for(int i=0;i<qk;i++){
		int query;
		scanf("%d",&query);
		memset(vis,false,sizeof(vis));
		memset(level,0,sizeof(level));
		cnt=-1;
		BFS(query);
		printf("%d\n",cnt);
	}
	
	
	
	
	return 0;
}








