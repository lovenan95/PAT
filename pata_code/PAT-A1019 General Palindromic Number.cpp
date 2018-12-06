#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,base;
int a[100];
int num=0;

int main(){
	scanf("%d %d",&n,&base);
	do{
		a[num++]=n%base;
		n/=base;
	}while(n!=0);
	int i=0,j=num-1;
	while(i<j){
		if(a[i]==a[j]){
			i++;
			j--;
		}else{
			break;
		}
	}
	if(i<j){
		printf("No\n");
		for(int k=num-1;k>=0;k--){
			printf("%d",a[k]);
			if(k!=0){
				printf(" ");
			}
		}
	}else{
		printf("Yes\n");
		for(int k=num-1;k>=0;k--){
			printf("%d",a[k]);
			if(k!=0){
				printf(" ");
			}
		}
	}













	return 0;
}

 