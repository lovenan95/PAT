#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int a,ah,b,bh,cnta=0,cntb=0;
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&a,&ah,&b,&bh);
		if((a+b)==ah&&a+b!=bh){
			cntb++;
		}
		if(a+b!=ah&&a+b==bh){
			cnta++;
		}
	}
	printf("%d %d",cnta,cntb);
	return 0;
} 