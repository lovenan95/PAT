#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;
char org[1010];
int hashtab[300]={0};

int main(){
	gets(org);
	int len=strlen(org);
	for(int i=0;i<len;i++){
		if(org[i]>='A'&&org[i]<='Z'){
			org[i]=org[i]-'A'+'a';
		}
	}
	for(int i=0;i<len;i++){
		if(org[i]>='a'&&org[i]<='z'){
			hashtab[org[i]]++;
		}
	}
//	puts(org);
	int letter;
	int max=-1;
	for(int i=0;i<300;i++){
		if(max<hashtab[i]){
			max=hashtab[i];
//			if(letter>org[i])
				letter=i;
		}
	}
	if(max!=-1)	
		printf("%c %d",letter,max);
	
	
	return 0;
}