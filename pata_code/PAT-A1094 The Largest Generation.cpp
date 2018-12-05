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
const int maxn=200;
int n,m,k;
struct node{
	int id;
	int layer;
	vector<int> child;
}tre[maxn];
bool notroot[maxn]={false};
int gen[maxn]={0};
int maxl=0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	tre[root].layer=1;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		maxl=max(maxl,tre[top].layer);
		gen[tre[top].layer]++;
		for(int i=0;i<tre[top].child.size();i++){
			int now=tre[top].child[i];
			tre[now].layer=tre[top].layer+1;
			q.push(now);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int id;
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			int chi;
			scanf("%d",&chi);
			tre[id].child.push_back(chi);
			notroot[chi]=true;
		}
	}
	int root;
	for(int i=1;i<=m;i++){
		if(notroot[i]==false){
			root=i;
			break;
		}
	}
	BFS(root);
	int maxg=0,level;
	for(int i=1;i<=maxl;i++){
		if(gen[i]>maxg){
			maxg=gen[i];
			level=i;
		}
	}
	
	printf("%d %d\n",maxg,level);
	
	
	
	
	
	
	return 0;
}








