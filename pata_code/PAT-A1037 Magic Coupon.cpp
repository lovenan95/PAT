#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int nc,np;
int cou[100010],couf[100010];
int pro[100010],prof[100010];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int temp;
	int c1=0,c2=0,p1=0,p2=0;
	scanf("%d",&nc);
	for(int i=0;i<nc;i++){
		scanf("%d",&temp);
		if(temp>=0){
			cou[c1]=temp;
			c1++;
		}else{
			couf[c2]=temp;
			c2++;
		}
	}
	scanf("%d",&np);
	for(int i=0;i<np;i++){
		scanf("%d",&temp);
		if(temp>=0){
			pro[p1]=temp;
			p1++;
		}else{
			prof[p2]=temp;
			p2++;
		}
	}	
	sort(cou,cou+c1,cmp);
	sort(pro,pro+p1,cmp);
	sort(couf,couf+c2);
	sort(prof,prof+p2);
	int ans=0;
	for(int i=0,j=0;i<c1&&j<p1;i++,j++){
		ans+=cou[i]*pro[j];
	}
	for(int i=0,j=0;i<c2&&j<p2;i++,j++){
		ans+=couf[i]*prof[j];
	}
	printf("%d",ans);
	
	
	
	
	return 0;
}