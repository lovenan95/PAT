#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int N;
char str[110][260];
char suf[260];

int main(){
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		gets(str[i]);
		int len=strlen(str[i]);
		reverse(str[i],str[i]+len);
//		puts(str[i]);
	}
	int k=0;
	char temp;
	bool flag=true,yes=false;
	for(int i=0;i<260;i++){
		int j=0;
		temp=str[j][i];
		int cnt=1;	
		for(j=1;j<N&&flag==true;j++){
			if(temp==str[j][i]){
				cnt++;
//				printf("%d\n",cnt);
			}else{
				flag=false;
				break;
			}
			if(cnt==N){
				suf[k]=temp;
				k++;
				yes=true;
//				puts(suf);
			}
		}
	}
	if(yes==true){
		reverse(suf,suf+strlen(suf));
		puts(suf);
	}else{
		printf("nai");
	}

	
		
	
	return 0;
}