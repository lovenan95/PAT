#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;

const int maxn=10010;
char str[maxn];
int hashtab[6]={0};
int cnt=0;
char pat[6]={'P','A','T','e','s','t'};
int main(){
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		for(int j=0;j<6;j++){
			if(str[i]==pat[j]){
				hashtab[j]++;
				cnt++;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<6;j++){
			if(hashtab[j]!=0){
				printf("%c",pat[j]);
				hashtab[j]--;
			}
		}
	}
	
	
	return 0;
} 