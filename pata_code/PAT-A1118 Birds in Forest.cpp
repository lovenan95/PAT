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

const int maxn=10010;
int n,k,q;
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

void init(int x){
	if(father[x]==-1){
		father[x]=x;
	}
}

bool cntbird[maxn]={false};
int main(){
	scanf("%d",&n);
	memset(father,-1,sizeof(father));
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		int a,b;
		scanf("%d",&a);
		init(a);
		cntbird[a]=true;
		for(int j=1;j<k;j++){
			scanf("%d",&b);
			init(b);
			cntbird[b]=true;
			Union(a,b);
		}
	}
	int numbird=0;
	for(int i=0;i<maxn;i++){
		if(cntbird[i]==true){
			numbird++;
		}
	}
	int isroot[maxn]={0};
	for(int i=0;i<maxn;i++){
		if(father[i]!=-1){
			int root=findfather(i);
			isroot[root]=1;
		}
	}
	int numroot=0;
	for(int i=0;i<maxn;i++){
		if(isroot[i]==1){
			numroot++;
		}
	}
	printf("%d %d\n",numroot,numbird);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		int rootu=findfather(u);
		int rootv=findfather(v);
		if(rootu==rootv){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		
	}
	
	
	
	return 0;
}


















