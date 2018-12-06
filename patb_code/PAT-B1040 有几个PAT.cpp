#include <stdio.h>
#include <string.h>
int main(){
	char str[100010];
	int ans=0;
	int leftp[100010]={0};
	int rightt[100010]={0};
	gets(str);
	int len=strlen(str);
	if(str[0]=='P'){
		leftp[0]=1;
	}
	for (int i=0;i<len;i++){
		if(str[i]=='P'){
			leftp[i]=leftp[i-1]+1;
		}else{
			leftp[i]=leftp[i-1];
		}
	}
	if(str[len-1]=='T'){
		rightt[len-1]=1;
	}
	for (int i=len-2;i>=0;i--){
		if(str[i]=='T'){
			rightt[i]=rightt[i+1]+1;
		}else{
			rightt[i]=rightt[i+1];
		}
	}
	for(int i=0;i<len;i++){
		if(str[i]=='A'){
			ans=(ans+leftp[i]*rightt[i])%1000000007;
		}
	}
	printf("%d",ans);
	return 0;
}