#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;

char org[1010],str[1010];
int hashtab[300]={0};
int main(){
//	printf("%d %d %d",'5','d','G');
	gets(org);
	gets(str);
	int len1=strlen(org);	
	int len2=strlen(str);	
	for(int i=0;i<len1;i++){
		hashtab[org[i]]++;
	}
	for(int i=0;i<len2;i++){
		hashtab[str[i]]--;
	}
	bool flag=true;
	int no=0;
	for(int i=0;i<300;i++){
		if(hashtab[i]<0){
			flag=false;
			no-=hashtab[i];
		}
	}
	if(flag==true){
		printf("Yes %d",len1-len2);
	}else{
		printf("No %d",no);
	}
	
	
	
	
	return 0;
}