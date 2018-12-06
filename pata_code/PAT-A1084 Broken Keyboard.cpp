#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;

char org[100],type[100];

void print(char s){
	if(s>='a'&&s<='z'){
		s=s+'A'-'a';
		printf("%c",s);
	}else{
		printf("%c",s);
	}
}

void change(char &s){
	if(s>='a'&&s<='z'){
		s=s+'A'-'a';
	}
}

bool h[1000]={false};
int main(){
	scanf("%s",org);
	int len1=strlen(org);
	scanf("%s",type);
	int len2=strlen(type);
	int i=0,j=0;
	while(i<len1&&j<len2){
		char c1=org[i],c2;
		c2=type[j];
		change(c1);
		change(c2);
//		printf("1%c 2%c****\n",c1,c2);
		if(c1==c2){
			i++;
			j++;
		}else if(c1!=c2){
			if(h[c1]==false){
				h[c1]=true;
				print(c1);				
			}
			i++;
		}
	}
	if(j==len2&&i<len1){
		for(;i<len1;i++){
			char ch=org[i];
			change(ch);
			if(h[ch]==false){
				print(ch);
				h[ch]=true;
			}
		}
	}
	return 0;
} 