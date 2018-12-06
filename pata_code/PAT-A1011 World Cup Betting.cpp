#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node{
	double w,t,l;
};

node a[4];
double maxn[4];
char res[4];

int main(){
	int n=3;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&a[i].w,&a[i].t,&a[i].l);
		maxn[i]=max(max(a[i].w,a[i].t),max(a[i].t,a[i].l));
		if(maxn[i]==a[i].w){
			res[i]='W';
		}else if(maxn[i]==a[i].t){
			res[i]='T';
		}else if(maxn[i]==a[i].l){
			res[i]='L';
		}
	}
	double r=(maxn[1]*maxn[2]*maxn[3]*0.65-1)*2;
	for(int i=1;i<=n;i++){
		printf("%c ",res[i]);
	}
	int temp=r;
	if((int)temp*1000%10>=5)
		r=r+0.005;
	printf("%0.2lf",r);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0; 
}