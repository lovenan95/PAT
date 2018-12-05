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
int n;
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
		father[max(fa,fb)]=min(fa,fb);
	}
}

void init(int x){
	if(father[x]==-1){
		father[x]=x;
	}
}

struct node{
	int id;
	int mes;
	int area;
}fam[maxn];

struct result{
	int id;
	int mes;
	int num;
	int area;
	double setavg;
	double avgarea;
	result(){
		id=10010;
		mes=0;
		area=0;
		avgarea=0;
		num=0;
	}
}res[maxn];

bool cmp(result a,result b){
	if(a.avgarea!=b.avgarea){
		return a.avgarea>b.avgarea;
	}else{
		return a.id<b.id;
	}
}

int main(){
	scanf("%d",&n);
	memset(father,-1,sizeof(father));
	for(int i=0;i<n;i++){
		int id,ft,mt,k,child,M,Area;
		scanf("%d%d%d%d",&id,&ft,&mt,&k);
		init(id);
		if(ft!=-1){
			init(ft);
			Union(id,ft);
		}
		if(mt!=-1){
			init(mt);
			Union(id,mt);
		}
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			init(child);
			Union(id,child);
		}
		scanf("%d%d",&M,&Area);
		fam[id].id=id;
		fam[id].area=Area;
		fam[id].mes=M;
	}
	int memroot[maxn]={0};
	for(int i=0;i<maxn;i++){
		if(father[i]!=-1){
			int root=findfather(i);
			memroot[root]++;
			res[root].area+=fam[i].area;
			res[root].mes+=fam[i].mes;
			res[root].id=root;
			res[root].num++;
//			cout<<"fam[i].mes="<<fam[i].mes	<<endl;				
//			cout<<"res[root].mes="<<res[root].mes<<endl;				
		}
	}
	int numf=0;
	for(int i=0;i<maxn;i++){
		if(memroot[i]>0){
			numf++;
		}
	}
	printf("%d\n",numf);	
	for(int i=0;i<maxn;i++){
		if(res[i].num!=0){
			res[i].avgarea=1.0*res[i].area/res[i].num;
			res[i].setavg=1.0*res[i].mes/res[i].num;

		}
	}
	sort(res,res+maxn,cmp);	
	for(int i=0;i<numf;i++){
		printf("%04d %d %.3f %.3f\n",res[i].id,res[i].num,res[i].setavg,res[i].avgarea);
	}
	return 0;
}









