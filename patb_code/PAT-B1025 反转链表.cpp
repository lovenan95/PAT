#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<stack> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;
const int maxn=100010;
int ad,N,K;

struct node{
	int addr;
	int data;
	int next;
	int order;
	node(){
		order=100010;
		next=-1; 
	}
}a[maxn],b[maxn];

bool cmp(node a,node b){
	return a.order<b.order;
}

int main(){
	scanf("%d%d%d",&ad,&N,&K);
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		scanf("%d%d",&a[temp].data,&a[temp].next);
		a[temp].addr=temp;
	}
	int rank=1,num=0;
	while(ad!=-1){
		a[ad].order=rank;
		b[num]=a[ad];
		ad=a[ad].next;
		rank++;
		num++;
	}
	sort(b,b+num,cmp);
	
//	for(int i=0;i<num;i++){
//		printf("%05d %d %05d\n",b[i].addr,b[i].data,b[i].next);
//	}

	int group=N/K;
	int rem=N%K; 
	
	for(int i=0;i<group&&(i+1)*K<=num;i++){
		reverse(b+i*K,b+K*(i+1));
	}
//	for(int i=0;i<N;i++){
//		printf("%05d %d %05d order=%d\n",b[i].addr,b[i].data,b[i].next,b[i].order);
//	}
	
	for(int i=0;i<num;i++){
		if(i<num-1)
			printf("%05d %d %05d\n",b[i].addr,b[i].data,b[i+1].addr);
		else{
			printf("%05d %d -1\n",b[i].addr,b[i].data);
		}
	}

	return 0;
}




