#include<stdio.h>
#include<string.h>
const int maxn=70;
char day[7][10]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
char str1[maxn],str2[maxn],str3[maxn],str4[maxn];
char d,h;

int main(){
	gets(str1);
	int len1=strlen(str1);
	gets(str2);
	int cnt=0;
	for(int i=0;i<len1;i++){
		if(cnt==1&&str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='N'&&str2[i]>='A'&&str2[i]<='N'){
			h=str1[i];
			break;
		}
		if(cnt==1&&str1[i]==str2[i]&&str1[i]>='0'&&str1[i]<='9'&&str2[i]>='0'&&str2[i]<='9'){
			h=str1[i];
			break;
		}
		if(cnt==0&&str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G'&&str2[i]>='A'&&str2[i]<='G'){
			d=str1[i];
			cnt++;
		}
	}
//	printf("%c\n",d);
//	printf("%c\n",h);
	
	gets(str3);
	int len3=strlen(str3);
	gets(str4);
	int pos=0;
	for(int i=0;i<len3;i++){
		if(str3[i]==str4[i]&&(str3[i]>='a'&&str3[i]<='z'||str3[i]>='A'&&str3[i]<='Z')){
			pos=i;
			break;
		}
	}
	printf("%s ",day[d-'A']);
	if(h>='0'&&h<='9'){
		printf("0%c:",h);
	}else if(h>='A'&&h<='N'){
		int hh=h-'A'+10;
		printf("%d:",hh);
	}
	printf("%02d",pos);
	
	
	
	
	
	
	
	
	
	return 0;
}