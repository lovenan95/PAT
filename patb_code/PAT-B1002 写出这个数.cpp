#include<stdio.h>
char a[110];
int main(){
	int sum=0;
	for(int i=0;i<110;i++){
		a[i]='0';
	}
	gets(a);
	int k=0;
	while(a[k]!='\0'){
		sum=sum+a[k]-'0';
		k++;
	}
//	printf("%d",sum);
	int s[110],cnt=0;
	while(sum!=0){
		s[cnt]=sum%10;
		cnt++;
		sum/=10;
	}
	for(int i=cnt-1;i>=0;i--){
//		printf("%d ",s[i]);
		if(s[i]==0){
			printf("ling");
		}else if(s[i]==1){
			printf("yi");
		}else if(s[i]==2){
			printf("er");
		}else if(s[i]==3){
			printf("san");
		}else if(s[i]==4){
			printf("si");
		}else if(s[i]==5){
			printf("wu");
		}else if(s[i]==6){
			printf("liu");
		}else if(s[i]==7){
			printf("qi");
		}else if(s[i]==8){
			printf("ba");
		}else if(s[i]==9){
			printf("jiu");
		}
		if(i!=0){
			printf(" ");
		}
	}
	return 0;
}
