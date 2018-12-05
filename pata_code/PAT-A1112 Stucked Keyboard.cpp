#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;


int k;
int hashtab[500]={0};

void judge(string str){
	char temp;
	int i=0,j=0;
	int len=str.length();
	while(i<len){
		temp=str[i];
		while(str[j]==temp&&j<len){
			j++;
		}
		if((j-i)%k!=0){
			hashtab[temp]=1;
		}
		i=j;
	}
}

int main(){
	scanf("%d",&k);
	string str;
	cin>>str;
	judge(str);
	int len=str.length();
	for(int i=0;i<len;i++){
		if(hashtab[str[i]]==0){
			printf("%c",str[i]);
			hashtab[str[i]]=-1;			
		}
	}
	printf("\n");
	for(int i=0;i<str.length();){
		if(hashtab[str[i]]==-1){
			printf("%c",str[i]);
			i+=k;
		}else{
			printf("%c",str[i]);
			i++;
		}
	}
	return 0;
}









