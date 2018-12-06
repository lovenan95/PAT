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

const int maxn=100010;
int n;
double a[maxn];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	double sum=0;
	for(int i=0;i<n;i++){
		sum+=(n-i)*(i+1)*a[i];
	}
	printf("%.2f",sum);
	return 0;
}