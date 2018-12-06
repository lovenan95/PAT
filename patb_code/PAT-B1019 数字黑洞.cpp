#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void toarr(int num,int arr[]){
	for(int i=3;i>=0;i--){
		arr[i]=num%10;
		num=num/10;
	}
}
int tonum(int arr[]){
	int num2=0;
	for(int i=0;i<4;i++){
		num2=num2*10+arr[i];
	}
	return num2;
}
int main(){
	int N,n1,sum,n2,num[4],s[4];
	scanf("%d",&N);
	if(N==6174)
	{
		printf("7641 - 1467 = 6174\n");
	}
	while(N!=0&&N!=6174){
		toarr(N,num);
		sort(num,num+4,cmp);
		n1=tonum(num);
		sort(num,num+4);
		n2=tonum(num);
		sum=n1-n2;
		toarr(sum,s);
		printf("%04d - %04d = %04d",n1,n2,sum);
		if(sum!=6174&&sum!=0){
			N=sum;
		}else{
			break;
		}
		printf("\n");
	}	
	return 0;
}