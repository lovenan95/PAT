#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;

const int maxn=100010;

int n,s1=0,s2=0,s;
int a[maxn];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}	
	sort(a,a+n);
	if(n%2==0){
		printf("0 ");
		for(int i=0;i<n/2;i++){
			s1+=a[i];
		}
		for(int i=n/2;i<n;i++){
			s2+=a[i];
		}
		printf("%d",s2-s1);
	}else{
		printf("1 ");
		for(int i=0;i<n/2;i++){
			s1+=a[i];
		}
		for(int i=n/2;i<n;i++){
			s2+=a[i];
		}		
		printf("%d",s2-s1);		
	}	
	
	
	
	
	
	
	return 0;
} 










