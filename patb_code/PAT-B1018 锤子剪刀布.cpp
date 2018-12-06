#include<stdio.h>
int N,p[3]={0},q[3]={0};
int pa[3]={0},qa[3]={0};
int judge(char c){
	if(c=='B'){
		return 2;
	}
	if(c=='C'){
		return 1;
	}
	if(c=='J'){
		return 0;
	}
}
//		p[0]p[1]p[2]
//¼×	Ê¤	Æ½	¸º 
//pa	0	1	2
//		J	C	B
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char a,b;
		getchar();
		scanf("%c %c",&a,&b);
		int k1=judge(a);
		int k2=judge(b);
		if(k1==0&&k2==2){
			p[0]++;
			pa[0]++;
			q[2]++;
		}else if(k1==2&&k2==0){
			q[0]++;
			qa[0]++;
			p[2]++;
		}else if(k1>k2){
			p[0]++;
			pa[k1]++;
			q[2]++;
		}else if(k1<k2){
			q[0]++;
			qa[k2]++;
			p[2]++;
		}else if(k1==k2){
			p[1]++;
			q[1]++;
		}
	}
	for(int i=0;i<3;i++){
		printf("%d",p[i]);
		if(i!=2){
			printf(" ");
		}
	}
	printf("\n");
	for(int i=0;i<3;i++){
		printf("%d",q[i]);
		if(i!=2){
			printf(" ");
		}
	}
	printf("\n");
	int idx1=0,idx2=0;
	int temp1=pa[0];
	int temp2=qa[0];
	for(int i=0;i<3;i++){
		if(temp1<pa[i]){
			temp1=pa[i];
			idx1=i;
		}else if(temp1==pa[i]&&idx1<i){
			idx1=i;
		}
	}
	for(int i=0;i<3;i++){
		if(temp2<qa[i]){
			temp2=qa[i];
			idx2=i;
		}else if(temp2==qa[i]&&idx2<i){
			idx2=i;
		}
	}
	if(idx1==0){
		printf("J ");
	}else if(idx1==1){
		printf("C ");
	}else{
		printf("B ");
	}
	if(idx2==0){
		printf("J");
	}else if(idx2==1){
		printf("C");
	}else{
		printf("B");
	}
	return 0;
}