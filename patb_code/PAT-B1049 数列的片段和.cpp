#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n;
double a[100010];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	double ans=0;
	for(int i=1;i<=n;i++){
		
		ans+=a[i]*i*(n+1-i);
			
	}	
	printf("%.2lf",ans);
	
	
	
	
	
	return 0;
}