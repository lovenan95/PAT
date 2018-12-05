#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;

bool hashtab[500];
char str[10010],del[10010];

int main(){
	gets(str);
	gets(del);
	int len1=strlen(str);
	int len2=strlen(del);
	memset(hashtab,true,sizeof(hashtab));
	for(int i=0;i<len2;i++){
		hashtab[del[i]]=false;
	}
	for(int i=0;i<len1;i++){
		if(hashtab[str[i]]==true){
			printf("%c",str[i]);
		}
	}
	return 0;
}

