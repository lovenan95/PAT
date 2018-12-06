#include<stdio.h>
#include<string.h>
char str[110];
int r[10]={0};
char res[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int sum=0;
int main(){
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		sum+=str[i]-'0';
	}
	if(sum==0){
		printf("zero");
	}
	else{
	
		int k=0;
		while(sum!=0){
			r[k]=sum%10;
			sum/=10;
			k++;
		}
		k--;
		for(;k>=0;k--){
			printf("%s",res[r[k]]);
			if(k!=0){
				printf(" ");
			}
		}
	}	
	
	
	
	
	return 0;
}