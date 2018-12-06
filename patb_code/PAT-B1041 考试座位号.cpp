#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	string id;
	int k;
}st[1010];
int N,M;
int main(){
	scanf("%d",&N);
	string str;
	int sj,ks;
	for(int i=1;i<=N;i++){
		cin>>str;
		scanf("%d",&sj);
		scanf("%d",&ks);
		st[sj].id=str;
		st[sj].k=ks;
	}
	scanf("%d",&M);
	int ask;
	for(int i=1;i<=M;i++){
		scanf("%d",&ask);
		cout<<st[ask].id<<" "<<st[ask].k<<endl;
	}
	
	
	
	
	
	
	return 0;
} 