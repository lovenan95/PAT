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
struct node{
	int address;
	int data;
	int next;
}lst[maxn]; 

vector<node> res;
int main(){
	int st,n,k;
	scanf("%d%d%d",&st,&n,&k);
	for(int i=0;i<n;i++){
		int ad,da,nt;
		scanf("%d%d%d",&ad,&da,&nt);
		lst[ad].address=ad;
		lst[ad].data=da;
		lst[ad].next=nt;
	}
	for(int i=st;i!=-1;i=lst[i].next){
		if(lst[i].data<0){
			res.push_back(lst[i]);
		}
	}
	for(int i=st;i!=-1;i=lst[i].next){
		if(lst[i].data>=0&&lst[i].data<=k){
			res.push_back(lst[i]);
		}
	}
	for(int i=st;i!=-1;i=lst[i].next){
		if(lst[i].data>k){
			res.push_back(lst[i]);
		}
	}		
	int i;
	for(i=0;i<res.size()-1;i++){
		printf("%05d %d %05d\n",res[i].address,res[i].data,res[i+1].address);
	}
	printf("%05d %d -1\n",res[i].address,res[i].data);
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}









