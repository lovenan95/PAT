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
int n;
int a[maxn];

struct node{
	int ans;
	int left;
	int right;
	node(){
		ans=0;
		left=0;
		right=0;
	}
}sum,maxsum;

int main(){
	scanf("%d",&n);
	bool sign=false;
	for(int i=0;i<n;i++){
		int tp;
		scanf("%d",&tp);
		if(tp>=0){
			sign=true;
		}
		a[i]=tp;
	}	
	if(sign==false){
		printf("0 %d %d",a[0],a[n-1]);
	}else{
		int k=0;
		for(;k<n;k++){
			if(a[k]>=0){
				break;
			}
		}
		node sum,maxsum;
		sum.left=k;
		maxsum.ans=-1;//!!!!!!!!!!!!!!!!
		for(;k<n;k++){
			sum.ans+=a[k];
			sum.right=k;
//			printf("sum=%d sumleft=%d sumright=%d\n",sum.ans,sum.left,sum.right);
//			printf("maxsum=%d maxsumleft=%d maxsumright=%d\n",maxsum.ans,maxsum.left,maxsum.right);
			if(sum.ans>maxsum.ans){
				maxsum.ans=sum.ans;
				maxsum.left=sum.left;
				maxsum.right=sum.right;
			}
			if(sum.ans<0){
				sum.ans=0;
				sum.left=k+1;
				sum.right=k+1;
			}
		}
		printf("%d %d %d",maxsum.ans,a[maxsum.left],a[maxsum.right]);
	}
	return 0;
}










