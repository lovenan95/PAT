#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
const int maxn=100010;
const int INF=1000000000;
int n;
double p,r;

struct node{
	int product;
	int layer;
	vector<int> child;
	node(){
		layer=0;
		product=0;
	}
}tre[maxn];

bool notroot[maxn]={false};
double sum=0;
void DFS(int root){
	if(tre[root].child.size()==0){
//		printf("pow(1+r,tre[root].layer)=%0.4f\n",pow(1+r,tre[root].layer));
		sum+=pow(1+r,tre[root].layer)*p*tre[root].product;
//		printf("tre[root].product=%d\n",tre[root].product);
//		printf("p=%0.2f\n",p);
//		printf("sum=%0.2f\n",sum);
		return;
	}
	for(int i=0;i<tre[root].child.size();i++){
		int next=tre[root].child[i];
		tre[next].layer=tre[root].layer+1;
		DFS(next);
	}
	
}

int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100.0;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				int child;
				scanf("%d",&child);
				notroot[child]=true;
				tre[i].child.push_back(child);		
			}
		}else{
			int amt;
			scanf("%d",&amt);
			tre[i].product=amt;
		}
	}	
	int root;
	for(int i=0;i<n;i++){
		if(notroot[i]==false){
			root=i;
			break;
		}
	}
	tre[root].layer=0;
	DFS(root);
	printf("%.1f\n",sum);
	
	
	
	
	
	
	return 0;
}








