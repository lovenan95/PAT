#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int n;
char a[10];
int cnt=0,sum[10010]={0};
bool hashtab[10010]={false};
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",a);
		int len=strlen(a);
		int s=0;
		for(int i=0;i<len;i++){
			s+=a[i]-'0';
		}
		if(hashtab[s]==false){
			hashtab[s]=true;
			sum[cnt++]=s;
		}
	}	
	sort(sum,sum+cnt);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d",sum[i]);
		if(i<cnt-1){
			printf(" ");
		}
	}
	
	
	
	
	
	
	return 0;
}









