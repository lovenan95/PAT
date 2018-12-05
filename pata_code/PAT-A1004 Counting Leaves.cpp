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

const int maxn=110;
int n,m;
int cntl[maxn]={0};

struct node{
	int id;
	int layer;
	vector<int> child;
}tre[maxn];

int maxlayer=0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	tre[root].layer=1;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		maxlayer=max(maxlayer,tre[top].layer);
		if(tre[top].child.size()==0){
			cntl[tre[top].layer]++;		
		}
		for(int i=0;i<tre[top].child.size();i++){
			int chi=tre[top].child[i];
			tre[chi].layer=tre[top].layer+1;
			q.push(chi);
		}
		
		
	} 
	
	
}

int main(){
	scanf("%d%d",&n,&m);	
	for(int i=0;i<m;i++){
		int fa,k;
		scanf("%d",&fa);
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			int tc;
			scanf("%d",&tc);
			tre[fa].child.push_back(tc);
		}
	}
	BFS(1);
	for(int i=1;i<=maxlayer;i++){
		printf("%d",cntl[i]);
		if(i<maxlayer){
			printf(" ");
		}
	}
	
	
	return 0;
}











