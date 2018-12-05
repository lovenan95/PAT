#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node{
	int h,m,s;
	int h2,m2,s2;
	char id[20];
}stu[100010],first,last;
int M;

bool cmp2(node a,node b){
	if(a.h2!=b.h2) return a.h2>b.h2;
	else if(a.m2!=b.m2) return a.m2>b.m2;
	else if(a.s2!=b.s2) return a.s2>b.s2;
}

bool cmp(node a,node b){
	if(a.h!=b.h) return a.h<b.h;
	else if(a.m!=b.m) return a.m<b.m;
	else if(a.s!=b.s) return a.s<b.s;
}


int main(){
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%s",stu[i].id);
		scanf("%d:%d:%d",&stu[i].h,&stu[i].m,&stu[i].s);
		scanf("%d:%d:%d",&stu[i].h2,&stu[i].m2,&stu[i].s2);
	}
	sort(stu,stu+M,cmp);
	printf("%s ",stu[0].id);
	sort(stu,stu+M,cmp2);
	printf("%s",stu[0].id);
	
	
	
	
	
	
	
	return 0;
}