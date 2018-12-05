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
const int maxn=100010;
int n;
double p,r;
struct node{
	int layer;
	vector<int> child;
}tre[maxn]; 
int hashtab[maxn]={0};
int maxl=0;
void BFS(int root){
	queue<int> q;
	tre[root].layer=0;
	q.push(root);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		maxl=max(maxl,tre[top].layer);
		hashtab[tre[top].layer]++;
		for(int i=0;i<tre[top].child.size();i++){
			int now=tre[top].child[i];
			tre[now].layer=tre[top].layer+1;
			q.push(now);
		}		
	}	
}

int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	int root;
	for(int i=0;i<n;i++){
		int fa;
		scanf("%d",&fa);
		if(fa!=-1){
			tre[fa].child.push_back(i);		
		}else{
			root=i;
		}
	}
	BFS(root);
	int num=hashtab[maxl];
	r/=100;
	double hp=1.0*pow(1+r,maxl)*p;
	printf("%0.2f %d",hp,num);
	
	
	
	
	
	
}










