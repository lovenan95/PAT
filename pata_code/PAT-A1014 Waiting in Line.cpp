#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<stdlib.h>
#include<vector> 
#include<map> 
#include<stack> 
#include<queue> 
#include<algorithm>
using namespace std;

const int maxn=1111;
int n,m,k,query,q;
int convert(int h,int m){
	return h*60+m;
}
int ans[maxn],needtime[maxn];
struct node{
	int edtime,poptime;
	queue<int> q;
}window[20];
int main(){
	int inidx=0;
	scanf("%d%d%d%d",&n,&m,&k,&query);
	for(int i=0;i<k;i++){
		scanf("%d",&needtime[i]);
	}
	for(int i=0;i<n;i++){
		window[i].edtime=window[i].poptime=convert(8,0);
	}
	for(int i=0;i<min(n*m,k);i++){
		window[inidx%n].q.push(inidx);
		window[inidx%n].edtime+=needtime[inidx];
		if(inidx<n)
			window[inidx].poptime=needtime[inidx];
		ans[inidx]=window[inidx%n].edtime;
		inidx++;
	}
	for(;inidx<k;inidx++){
		int idx=-1,min=1<<30;
		for(int i=0;i<n;i++){
			if(window[i].poptime<min){
				min=window[i].poptime;
				idx=i;
			}
		}
		window[idx].q.pop();
		window[idx].q.push(inidx);
		window[idx].edtime+=needtime[inidx];
		window[idx].poptime+=needtime[window[idx].q.front()];
		ans[inidx]=window[idx].edtime;
	}
	for(int i=0;i<query;i++){
		scanf("%d",&q);
		if(ans[q-1]-needtime[q-1]>=convert(17,0)){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
		}
		
	}
	
	
	
	
	
	
	return 0;
}











