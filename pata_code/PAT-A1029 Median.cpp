#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n,m;
int a[2000010];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=n;i<n+m;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+m+n);
	int pos=(m+n-1)/2;
	int mid=a[pos];
	printf("%d",mid);
	
	
	return 0;
}