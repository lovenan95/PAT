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
int father[maxn];
int hobby[maxn]={0};

int findfather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[a]=x;
	}
	return x;
}

void Union(int a,int b){
	int fa=findfather(a);
	int fb=findfather(b);
	if(fa!=fb){
		father[fb]=fa;
	}
}

void init(int x){
	if(father[x]==-1){
		father[x]=x;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,k;
	scanf("%d",&n);
	memset(father,-1,sizeof(father));
	for(int i=1;i<=n;i++){
		init(i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d: ",&k);
		for(int j=0;j<k;j++){
			int hb;
			scanf("%d",&hb);
			if(hobby[hb]==0){
				hobby[hb]=i;
			}
			Union(i,findfather(hobby[hb]));			
		}
	}	
	int cntmem[maxn]={0};
	int cntroot=0;
	for(int i=1;i<=n;i++){
		int root=findfather(i);
		cntmem[root]++;
	} 
	for(int i=0;i<maxn;i++){
		if(cntmem[i]>0){
			cntroot++;
		}
	}
	sort(cntmem,cntmem+maxn,cmp);
	printf("%d\n",cntroot);
	for(int i=0;i<cntroot;i++){
		printf("%d",cntmem[i]);
		if(i<cntroot-1){
			printf(" ");
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}








