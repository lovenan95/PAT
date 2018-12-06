#include<stdio.h>
#include<string.h>

char a[1010];
int cnt[10]={0};

int main(){ 
	gets(a);
	int len=strlen(a); 
	for(int i=0;i<len;i++){
		cnt[a[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(cnt[i]!=0)
			printf("%d:%d\n",i,cnt[i]);
	}
	
	
	return 0; 
}
