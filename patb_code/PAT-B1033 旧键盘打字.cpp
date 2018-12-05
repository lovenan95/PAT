#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;
const int maxn=100010;
char brok[maxn],org[maxn];
bool hashtab[1000];
int main(){
	memset(hashtab,true,sizeof(hashtab));
	gets(brok);
	gets(org);
	int len1=strlen(brok);
	int len2=strlen(org);
	for(int i=0;i<len1;i++){
		if(brok[i]=='+'){
			for(char j='A';j<='Z';j++){
				hashtab[j]=false;
			}			
		}
		hashtab[brok[i]]=false;
		if(brok[i]>='A'&&brok[i]<='Z'){
			hashtab[brok[i]-'A'+'a']=false;
		}
	}	
	for(int i=0;i<len2;i++){
		if(hashtab[org[i]]==true){
			printf("%c",org[i]);
		}
	}
	
//	for(int i=0;i<1000;i++){
//			printf("%d	",hashtab[i]);
//	}
	


	return 0;
}