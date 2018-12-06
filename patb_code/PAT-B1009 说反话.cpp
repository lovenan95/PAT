#include <stdio.h>
#include <string.h>

int main(){
	char str[90];
	gets(str);
	int len=strlen(str);
	char str2[90];
	int i=len-1,j,cnt=0,k=0;
	while(i>=0){
		while(str[i]!=' '&&i>=0)
		{
			i--;
			cnt++;
		}
		j=i+1;
		while(cnt!=0){
			str2[k++]=str[j++];
			cnt--;
		}
		str2[k++]=' ';
		i--;
		cnt=0;
	
	}
	str2[len]='\0';
	puts(str2);
	
	return 0;
}