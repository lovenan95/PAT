#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=54;

struct node{
	char name;
	int number;	 
}; 

int times;
int a[N+1];
node org[N+1];
node shuf[N+1];

//	0S	1	2	3	4	5	6	7	8	9	10	11	12	13
//	1H	1	2	3	4	5	6	7	8	9	10	11	12	13
//	2C	1	2	3	4	5	6	7	8	9	10	11	12	13
//	3D	1	2	3	4	5	6	7	8	9	10	11	12	13
//	4J	1	2	
int main(){
	for(int i=1;i<=13;i++){
		org[i].name='S';
		org[i].number=i;
	}
	for(int i=14;i<=26;i++){
		org[i].name='H';
		org[i].number=i-13;
	}
	for(int i=27;i<=39;i++){
		org[i].name='C';
		org[i].number=i-26;
	}
	for(int i=40;i<=52;i++){
		org[i].name='D';
		org[i].number=i-39;
	}
	for(int i=53;i<=54;i++){
		org[i].name='J';
		org[i].number=i-52;
	}
	
	scanf("%d",&times);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	for(int k=0;k<times;k++){
		for(int i=1;i<=N;i++){
			shuf[a[i]].name=org[i].name;
			shuf[a[i]].number=org[i].number;
		}
		for(int i=1;i<=N;i++){
			org[i].name=shuf[i].name;
			org[i].number=shuf[i].number;
		}
	} 
	for(int i=1;i<=N;i++){
		printf("%c%d",org[i].name,org[i].number);
		if(i!=N){
			printf(" ");
		}
	}
	return 0;
}




