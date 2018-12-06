#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<math.h>
#include<stdlib.h>
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n;
bool isprime(int a){
	int s=(int) sqrt(1.0*a);
	for(int i=2;i<=s;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	scanf("%d",&n);
	int cnt=0;
	for(int i=3;i+2<=n;i++){
		if(isprime(i)==true&&isprime(i+2)==true){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
} 