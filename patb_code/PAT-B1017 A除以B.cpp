#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<math.h> 
#include<algorithm>
using namespace std;

char a[1010];
int numa[1010];
int res[1010];
int b;
int r;

void change(char str[]){
	int len=strlen(str);
	for(int i=0;i<len;i++){
		numa[i]=str[i]-'0';
	}	
} 

int main(){
	scanf("%s",a);
	scanf("%d",&b);
	int len=strlen(a);
	change(a);
	int idx=0;
	int rem=0;
	for(int i=0;i<len;i++){
		int tq=(rem+numa[i])/b;
		int tr=(rem+numa[i])%b;
		if(tq==0&&i==0){
			rem=10*tr;
		}else{
			res[idx]=tq;
			rem=tr*10;
			idx++;
		}
		r=tr;		
	}
	if(res[0]==0){
		printf("0");
	}else{
		for(int i=0;i<idx;i++){
			printf("%d",res[i]);
		}		
	}
	printf(" %d",r);
	
	
	
	
	
	return 0;
} 