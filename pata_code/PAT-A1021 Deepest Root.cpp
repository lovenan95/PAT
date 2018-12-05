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
const int maxn=10010;
const int INF=1000000000;
int n;
vector<int> adj[maxn];
int vis[maxn]={false}; 
int father[maxn];

int findfather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}

void Union(int a,int b){
	int fa=findfather(a);
	int fb=findfather(b);
	if(fa!=fb){
		father[fa]=fb;
	}
}

void init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;/*ÏÈ°ÑËùÓÐ½Úµã³õÊ¼»¯Îª×ÔÉí*/
	}
}

vector<int> ans,temp;
int maxh=0;
void DFS(int u,int height){
	vis[u]=true;
	if(maxh<height){
		maxh=height;
		temp.clear();
		temp.push_back(u);
	}else if(maxh==height){
		temp.push_back(u);
	}
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v]==false){
			DFS(v,height+1);
		}
	}
}



int main(){
	memset(father,-1,sizeof(father));
	scanf("%d",&n);
	init(n);/*ÊäÈëÊý¾ÝÖÐÓÐÎ´³öÏÖµÄ½ÚµãÒ²Òª³õÊ¼»¯*/
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		Union(a,b);
	}	
	int isroot[maxn]={0};
	for(int i=1;i<maxn;i++){
		if(father[i]!=-1){
			int root=findfather(i);
			isroot[root]++;
		}
	}
	int block=0;
	for(int i=1;i<maxn;i++){
		if(isroot[i]>0){
			block++;
		}
	}
	if(block>1){
		printf("Error: %d components\n",block);
	}else{
		DFS(1,1);
		ans=temp;
//		for(int i=0;i<ans.size();i++){
//			printf("**%d ",ans[i]);
//		}		
//		printf("\n");
		memset(vis,false,sizeof(vis));
		DFS(ans[0],1);
		for(int i=0;i<temp.size();i++){
			ans.push_back(temp[i]);
		}
		set<int> st;
//		for(int i=0;i<ans.size();i++){
//			printf("%d ",ans[i]);
//		}
		for(int i=0;i<ans.size();i++){
			st.insert(ans[i]);
		}
		for(set<int>::iterator it=st.begin();it!=st.end();it++){
			printf("%d\n",*it);
		}
	} 





	
	
	return 0;
}









