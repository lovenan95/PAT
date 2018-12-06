#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;

int N;
int a[100010];
bool flag=false;
int hashtab[10010]={0};
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		hashtab[a[i]]++;
	}
	for(int k=0;k<N;k++){
		if(hashtab[a[k]]==1){
			printf("%d",a[k]);
			flag=true;
			break;
		}
	}
	if(flag==false)
		printf("None");
	return 0;
} 