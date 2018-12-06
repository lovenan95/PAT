#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int n,e;
int a[100010];
bool flag=false;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	sort(a+1,a+n+1,cmp);
	int i=1;
	for(;i<=n;i++){
		if(a[i]<=i){
			break;
		}
	}
	printf("%d",i-1);
	return 0;
}











