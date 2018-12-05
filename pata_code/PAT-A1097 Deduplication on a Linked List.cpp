#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<math.h> 
#include<stack> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

const int maxn=100010;
int ad,N;

struct node{
	int addr;
	int value;
	int next;
	int jdz;
}a[maxn],res[maxn],del[maxn];

bool hashtab[100010]={false};

int main(){
	scanf("%d %d",&ad,&N);
	for(int i=0;i<N;i++){
		int addr;
		scanf("%d",&addr);
		scanf("%d %d",&a[addr].value,&a[addr].next);
		a[addr].addr=addr;
		a[addr].jdz=abs(a[addr].value);
	}
	int p=ad,cnt1=0,cnt2=0;
	while(p!=-1){
		if(hashtab[a[p].jdz]==false){
			res[cnt1++]=a[p];
			hashtab[a[p].jdz]=true;
			p=a[p].next;			
		}else{
			del[cnt2++]=a[p];
			p=a[p].next;			
		}
	}
	for(int i=0;i<cnt1;i++){
		if(i<cnt1-1){
			printf("%05d %d %05d\n",res[i].addr,res[i].value,res[i+1].addr);
		}else{
			printf("%05d %d -1\n",res[i].addr,res[i].value);
		}
	}
	
	for(int i=0;i<cnt2;i++){
		if(i<cnt2-1){
			printf("%05d %d %05d\n",del[i].addr,del[i].value,del[i+1].addr);
		}else{
			printf("%05d %d -1\n",del[i].addr,del[i].value);
		}
	}
	
	
	
	
	return 0;
}