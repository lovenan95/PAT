#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	double x;
	int e;
};

bool cmp(node a,node b){
	return a.e>b.e;
}

node p1[1010];
node p2[1010];
node r[2020];
node res[2020];
int k1,k2;
int main(){
	scanf("%d",&k1);
	for(int i=0;i<k1;i++){
		scanf("%d %lf",&p1[i].e,&p1[i].x);
	}
	scanf("%d",&k2);
	for(int i=0;i<k2;i++){
		scanf("%d %lf",&p2[i].e,&p2[i].x);
	}
	int k=0;
	for(int i=0;i<k1;i++){
		for(int j=0;j<k2;j++){
			r[k].e=p1[i].e+p2[j].e;
			r[k].x=p1[i].x*p2[j].x;
//			if(r[k].e==r[k-1].e&&k>0){
//				r[k-1].x=r[k-1].x+r[k].x;
//				k--;
//			}
			k++;		
		}
	}
	int num=0;
	for(int i=0;i<2020;i++){
		if(r[i].x!=0){
			num++;
		}
	}
	sort(r,r+num,cmp);
	int m=0,i=1;
	res[0].e=r[0].e;
	res[0].x=r[0].x;	
	while(i<num){	
		if(res[m].e==r[i].e){
			res[m].x=res[m].x+r[i].x;
			i++;
		}
		if(res[m].e!=r[i].e){
			m++;
			res[m].x=r[i].x;
			res[m].e=r[i].e;
			i++;
		}
	}
	int numres=0;
	for(int i=0;i<2020;i++){
		if(res[i].x!=0){
			numres++;
		}
	}		
	printf("%d",numres);
	for(int i=0;i<2020;i++){
		if(res[i].x!=0)
			printf(" %d %0.1lf",res[i].e,res[i].x);
	}
	
	
	
	
	return 0;
}
