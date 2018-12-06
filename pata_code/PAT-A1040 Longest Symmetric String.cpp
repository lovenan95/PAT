#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;
/*ÓÃstring str»á³¬Ê±*/
int main(){
	char str[1010],rts[1010];
	gets(str);
	int len=strlen(str);
	int tempans=0,ans=0;
	for(int i=0;i<len;i++){
		for(int j=len-1;j>=0;j--){
			if(str[i]==str[j]){
				tempans=0;
				int p=i,q=j;
				while(str[p]==str[q]&&p<len&&q>=0){
					p++;
					q--;
					tempans++;
				}
				if(tempans>ans){
					ans=tempans;
				}
			}
		}
	}
	printf("%d",ans);
	
	
	
	
	
	return 0;
}