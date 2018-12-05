#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

int N;
char c;

int main(){
	scanf("%d %c",&N,&c);
	int k=(int)sqrt((N+1)/2.0)-1;
	int p=k;
	int q;
	int m;
	for(;k>=0;k--){
		q=(p-k);
		while(q!=0){
			printf(" ");
			q--;
		}
		m=2*k+1;
		while(m>0){
			printf("%c",c);
			m--;
		}
//		q=(p-k); 
//		while(q!=0){
//			printf(" ");
//			q--;
//		}
		printf("\n");
	}
	
	for(k=1;k<=p;k++){
		q=(p-k);
		while(q!=0){
			printf(" ");
			q--;
		}
		m=2*k+1;
		while(m>0){
			printf("%c",c);
			m--;
		}
//		q=(p-k);
//		while(q!=0){
//			printf(" ");
//			q--;
//		}
		printf("\n");
	}
	int s;
	s=N-(2*(p+1)*(p+1)-1);
	printf("%d\n",s);
	
	
	
	
	
	
	return 0;
}