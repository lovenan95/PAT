#include<stdio.h>
#include<string.h>

char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
int w[20]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char a[20];
int n,sum,mod,cnt=0;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",a);
		sum=0;
		mod=0;
		int len=strlen(a);
		for(int k=0;k<len-1;k++){
			sum+=w[k]*(a[k]-'0');	
		}
		mod=sum%11;	
		if(M[mod]==a[len-1]){
			cnt++;
		}else{
			puts(a);
//			printf("\n");
		}
	}
	if(cnt==n){
		printf("All passed");
	}
	
	
	return 0;
}