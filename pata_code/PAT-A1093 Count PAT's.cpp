#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

char str[100010];
int pa[100010]={0},at[100010]={0};
int main(){
	gets(str);
	int len=strlen(str);
	int kp=0,kt=0,cntp=0,cntt=0;
	long long res=0;
	for(int i=0;i<len;i++){
		if(str[i]=='P'){
			cntp++;
		}
		if(str[i]=='A'){
			pa[i]=cntp;
			kp++;
		}
	}
	for(int i=len-1;i>=0;i--){
		if(str[i]=='T'){
			cntt++;
		}
		if(str[i]=='A'){
			at[i]=cntt;
			kt++;
		}
	}	
	for(int i=0;i<len;i++){
		res=(res+at[i]*pa[i])%1000000007;
	}
	printf("%lld",res);
	return 0;
} 