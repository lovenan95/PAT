#include<stdio.h>
int N,M;
void reverse(int a[],int begin,int end){
	int mid=(begin+end-1)/2;
	for(int i=begin;i<=mid;i++){
		int temp;
		temp=a[i];
		a[i]=a[end];
		a[end]=temp;
		end--;
	}
}
int main(){
	int a[110];
	scanf("%d %d",&N,&M);
	M=M%N;
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	reverse(a,1,N-M);
	reverse(a,N-M+1,N);
	reverse(a,1,N);
	for(int i=1;i<=N;i++){
		printf("%d",a[i]);
		if(i!=N){
			printf(" ");
		}
	}
	return 0;
}