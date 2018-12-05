#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n;
long long p,a[100010];

int main(){
	scanf("%d%ld",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	sort(a,a+n);
	int len=0,i=0,j=0;
	while(i<n&&j<n){
		while(j<n&&a[i]*p>=a[j]){
			len=max(len,j-i+1);
			j++;
		}
		i++; 
	}


//	for(j=n-1;j>=0;j--){
//		for(i=0;i<=j;i++){
//			if(a[i]*p>=a[j]){
//				if(len<j-i+1)
//					len=j-i+1;
//				else break;
//			}
//		}
//	}

	printf("%d",len);
	
	
	
	
	
	
	
	
	
	return 0;
}