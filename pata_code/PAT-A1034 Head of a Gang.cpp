#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
using namespace std;

const int maxn=2010;
int n,k;
int w[maxn];
map<string,int> sti;
map<int,string> its;

int father[maxn];

int findfather(int x){
	int a=x;
	while(father[x]!=x){
		x=father[x];
	}
	while(father[a]!=a){
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
		if(w[fa]>w[fb]){
			father[fb]=fa;
		}else{
			father[fa]=fb;
		}
	}
}

int init(int x){
	if(father[x]==-1){
		father[x]=x;
	}
}

struct node{
	int id;
	int num;
	int sw;
	node(){
		num=0;
		sw=0;
		id=-1;
	}
}gang[maxn];
bool cmp(node a,node b){
	return its[a.id]<its[b.id];
}
int main(){
	scanf("%d%d",&n,&k);
	int cnt=1;
	memset(father,-1,sizeof(father));
	for(int i=0;i<n;i++){
		string na,nb;
		cin>>na>>nb;
		if(sti.find(na)==sti.end()){
			sti[na]=cnt;
			init(sti[na]);
			its[cnt]=na;
			cnt++;			
		}
		if(sti.find(nb)==sti.end()){
			sti[nb]=cnt;
			init(sti[nb]);
			its[cnt]=nb;
			cnt++;			
		}	
		int we;
		scanf("%d",&we);
		w[sti[na]]+=we;
		w[sti[nb]]+=we;
		Union(sti[na],sti[nb]);
//		cout<<"*sti[na]=**"<<na<<" findfather()"<<its[findfather(sti[na])]<<endl;
		
	}
//	for(int i=0;i<cnt;i++){
//		cout<<its[i]<<" weight= "<<w[i]<<endl;
//	} 	
	
	for(int i=1;i<cnt;i++){
		if(father[i]!=-1){
			int root=findfather(i);
			gang[root].id=root; 
			for(int j=1;j<cnt;j++){
				if(findfather(j)==root&&w[j]>=w[gang[root].id]){
					gang[root].id=j;
				}				
			}
//			gang[root].id=root;
			gang[root].sw+=w[i];
			gang[root].num++;
//			cout<<"gang[root].id="<<its[gang[root].id]<<"gang[root].num= "<<gang[root].num<<endl;
//			cout<<"gang[root].sw="<<gang[root].sw<<endl;
		}
	}
	sort(gang,gang+cnt,cmp);
	int sg=0;
	for(int i=1;i<cnt;i++){
		if(gang[i].id!=-1){
			if(gang[i].num>2&&gang[i].sw>2*k){
				sg++;
			}
		}
	}
	
//	for(int i=1;i<cnt;i++){
//		cout<<"gang id"<<gang[i].id<<endl;
//	}	
	
	printf("%d\n",sg);
	if(sg!=0){
		for(int i=1;i<cnt;i++){
			if(gang[i].id!=-1){
				if(gang[i].num>2&&gang[i].sw>2*k){
					cout<<its[gang[i].id]<<" "<<gang[i].num<<endl;
				}
			}
		}		
	}
	return 0;
}












