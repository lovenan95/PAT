#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
int main(){
	char str[90];
	gets(str);
	int len=strlen(str);
	char nw[90];
	int n1=(len+2)/3;
	int n3=n1;
	int n2=len-n1-n3+2;
	int k=0;
	while(k<n1-1){
		printf("%c",str[k]);
		k++;
		for(int i=0;i<n2-2;i++){
			printf(" ");
		}
		printf("%c\n",str[len-1]);
		len--;
	}
	for(int i=n1-1;i<n1+n2-1;i++){
		printf("%c",str[i]);
	}
	return 0;
}