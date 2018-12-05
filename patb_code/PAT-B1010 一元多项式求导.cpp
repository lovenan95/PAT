#include<stdio.h>
const int maxn=1010;
struct node{
	int k;
	int e;
}p[maxn];
int main(){
	int a,b,j=0;
	while(scanf("%d %d",&a,&b)!=EOF){
		p[j].e=b;
		p[j].k=a;
		j++;
	}
	int cnt=0;
	for(int i=0;i<j;i++){
		if(p[i].e!=0){
			p[i].k=p[i].k*p[i].e;
			p[i].e--;
			cnt++;
		}else{
			p[i].k=0;
		}
	}
	if(cnt==0)
		printf("0 0");
	else{
		for(int i=0;i<j;i++){
			if(p[i].k==0)
				continue;
			if(p[i].k!=0){
				printf("%d %d",p[i].k,p[i].e);
				cnt--;
			}	
			if(cnt!=0&&p[i].k!=0){
				printf(" ");
			}
		}
	}
	return 0;
}