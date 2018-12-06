#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<algorithm>
using namespace std;

int N,M,K;
int quo[110];

struct node{
	int id;
	int igrade;
	int egrade;
	int sum;
	bool flag;
	int app[10];
	int rank;
}stu[40010];

struct school{
	int adm[40010];
	int schoolid;
	int quota;
	int lastid;
	bool full;
	int cnt;
}sch[110];

bool cmp(node a,node b){
	 if(a.sum!=b.sum){
	 	return a.sum>b.sum;
	 }else{
	 	return a.egrade>b.egrade;
	 }
}

bool cmp2(int a,int b){
	return a<b;
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		scanf("%d",&sch[i].quota);
		sch[i].full=false;
		sch[i].schoolid=i;
		sch[i].lastid=-1;
		sch[i].cnt=0;
	}
	for(int i=0;i<N;i++){
		stu[i].id=i;
		stu[i].flag=false;
		scanf("%d%d",&stu[i].egrade,&stu[i].igrade);
		stu[i].sum=stu[i].egrade+stu[i].igrade;
		for(int k=0;k<K;k++){
			scanf("%d",&stu[i].app[k]);
		}
	}
	sort(stu,stu+N,cmp);
	stu[0].rank=0;
	for(int i=1;i<N;i++){
		if(stu[i].sum==stu[i-1].sum&&stu[i].egrade==stu[i-1].egrade){
			stu[i].rank=stu[i-1].rank;
		}else{
			stu[i].rank=i;
		}
	}
	for(int i=0;i<N;i++){
		for(int k=0;k<K&&stu[i].flag==false;k++){
			int choice=stu[i].app[k];
			if(sch[choice].quota<=0&&sch[choice].cnt==0){
				break;
			}
			if(sch[choice].full==false)
				if(sch[choice].quota<=0){
					sch[choice].full=true;
				}
				if(sch[choice].full==false){
					sch[choice].adm[sch[choice].cnt]=stu[i].id;
					stu[i].flag=true;
					sch[choice].quota--;
					sch[choice].lastid=i;
					sch[choice].cnt++;
//					break;
				}
				if(sch[choice].full==true&&sch[choice].lastid!=-1&&stu[sch[choice].lastid].rank==stu[i].rank){
					sch[choice].adm[sch[choice].cnt]=stu[i].id;
					stu[i].flag=true;
					sch[choice].quota--;
					sch[choice].lastid=i;
					sch[choice].cnt++;
//					break;
				}
//			for(int m=0;m<M;m++){
//				if(stu[i].app[k]==sch[m].schoolid){
//					if(sch[m].quota==0){
//						sch[m].full=true;
//					}
//					if(sch[m].full==false){
//						sch[m].adm[sch[m].cnt]=stu[i].id;
//						stu[i].flag=true;
//						sch[m].quota--;
//						sch[m].lastid=stu[i].id;
//						sch[m].cnt++;
//						break;
//					}
//					if(sch[m].full==true&&stu[sch[m].lastid].rank==stu[i].rank){
//						sch[m].adm[sch[m].cnt]=stu[i].id;
//						stu[i].flag=true;
//						sch[m].cnt++;
//						break;
//					}
//				}				
//			}
		}
	}
	for(int i=0;i<M;i++){
		if(sch[i].cnt>0){
			sort(sch[i].adm,sch[i].adm+sch[i].cnt,cmp2);
			for(int j=0;j<sch[i].cnt;j++){
				printf("%d",sch[i].adm[j]);
				if(j<sch[i].cnt-1){
					printf(" ");
				}
			}
		}
		printf("\n");
	}
//	for(int i=0;i<N;i++)
//		printf("***ID=%d***rank=%d***\n",stu[i].id,stu[i].rank);
	
	
	
	
	
	return 0;
} 