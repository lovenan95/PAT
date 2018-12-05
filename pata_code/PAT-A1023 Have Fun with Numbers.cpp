#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<math.h> 
#include<algorithm>
using namespace std;

char str[30];
int num[30];
int num2[30];
int hash1[20]={0};
int hash2[20]={0};

void change(char str[]){
	int len=strlen(str);
	int j=len-1;
	for(int i=0;i<len;i++){
		num[i]=str[j]-'0';
		j--;
	}	
} 
int main(){
	scanf("%s",str);
	int len=strlen(str);
	change(str);
	for(int i=0;i<len;i++){
		hash1[num[i]]++;
	}
	int sw=0,gw=0;
	int len2=len;
	for(int i=0;i<len;i++){
		int temp=num[i]*2+sw;
		sw=temp/10;
		gw=temp%10;
		num2[i]=gw;
		if(i==len-1&&sw!=0){
			num2[len2++]=sw;
		}
	}
	for(int i=0;i<len2;i++){
		hash2[num2[i]]++;
	}
	bool flag=true;
	for(int i=0;i<10;i++){
		if(hash1[i]!=hash2[i]){
			flag=false;
			break;
		}
	}
	if(flag==false){
		printf("No\n");
	}else{
		printf("Yes\n");		
	}
	for(int i=len2-1;i>=0;i--){
		printf("%d",num2[i]);
	}
	
	
	
	
	
	return 0;
}