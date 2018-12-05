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
};

node simp(node a){
	if(a.mom<0){
		a.child=-a.child;
		a.mom=-a.mom;
	} 	
	if(a.child==0){
		a.mom=1;
	}else{
		long long g=gcd(abs(a.child),abs(a.mom));
		a.child/=g;
		a.mom/=g;
	}
	return a;	
}

node sum(node a,node b){
	node res;
	res.child=a.child*b.mom+b.child*a.mom;
	res.mom=a.mom*b.mom;
	return simp(res);
}

node dif(node a,node b){
	node res;
	res.child=a.child*b.mom-b.child*a.mom;
	res.mom=a.mom*b.mom;
	return simp(res);
}

node prod(node a,node b){
	node res;
	res.child=a.child*b.child;
	res.mom=a.mom*b.mom;
	return simp(res);
}

node div(node a,node b){
	node res;
	res.child=a.child*b.mom;
	res.mom=a.mom*b.child;
	return simp(res);
}

void show(node res){
	res=simp(res);
	long long temp=res.child;
	if(temp<0)
		printf("(");
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
	if(temp<0)
		printf(")");
}

int main(){
	node a,b,ans;
	scanf("%lld/%lld %lld/%lld",&a.child,&a.mom,&b.child,&b.mom);
	ans=sum(a,b);
	show(a);
	printf(" + ");
	show(b);
	printf(" = ");
	show(ans);
	printf("\n");	
	
	ans=dif(a,b);
	show(a);
	printf(" - ");
	show(b);
	printf(" = ");
	show(ans);
	printf("\n");	
	
	ans=prod(a,b);
	show(a);
	printf(" * ");
	show(b);
	printf(" = ");
	show(ans);
	printf("\n");	

	show(a);
	printf(" / ");
	show(b);
	printf(" = ");
	if(b.child==0){
		printf("Inf");
	}else{
		ans=div(a,b);
		show(ans);
	}
	printf("\n");
	
	return 0;
} 