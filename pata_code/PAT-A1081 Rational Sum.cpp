#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<stdlib.h>
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n;
long long gcd(long long a,long long b){
	if(b==0)
		return a;
	else return gcd(b,a%b);
}

struct node{
	long long child;
	long long mom;
}a[110],res;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld/%lld",&a[i].child,&a[i].mom);
		if(a[i].mom<0){
			a[i].child=-a[i].child;
			a[i].mom=-a[i].mom;
		} 
	}
	res.child=a[0].child;
	res.mom=a[0].mom;
	if(res.child==0){
		res.mom=1;
	}else{
		int d=gcd(abs(res.child),abs(res.mom));
		res.child/=d;
		res.mom/=d;
	}
	
	for(int i=1;i<n;i++){
		res.child=res.child*a[i].mom+a[i].child*res.mom;
		res.mom=res.mom*a[i].mom;
		if(res.child==0){
			res.mom=1;
		}else{
			int g=gcd(abs(res.child),abs(res.mom));
			res.child/=g;
			res.mom/=g;
		}
	}
	long long integer=res.child/res.mom;
	
	if(res.mom!=1){
		if(abs(res.child)<res.mom){
			printf("%lld/%lld",res.child,res.mom);
		}else{
			res.child=abs(res.child)-abs(integer)*res.mom;
			printf("%lld %lld/%lld",integer,res.child,res.mom);		
		}
	}else{
		printf("%lld",res.child);
 	}
	
	return 0;
} 