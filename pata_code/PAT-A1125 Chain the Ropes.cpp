#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<set>
using namespace std;

const int maxn=10010;
int n;
int a[maxn];
int sum=0;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}	
	sort(a,a+n);
	int ans=a[0];
	for(int i=1;i<n;i++){
		ans=(ans+a[i])/2;
	}	
	printf("%d",ans);
	
	
	return 0;
}











