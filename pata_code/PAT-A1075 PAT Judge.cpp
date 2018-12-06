#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<algorithm>
using namespace std;
const int maxn=100010;
int N,K,M;
int prob[10];

struct node{
	int id;
	int score[10];
	bool perfect[10];
	bool com;
	int grade;
	int solve;
	int rank;
}stu[200010];

bool cmp(node a,node b){
	if(a.grade!=b.grade)
		return a.grade>b.grade;
	else if(a.solve!=b.solve)
		return a.solve>b.solve;
	else if(a.id!=b.id)
		return a.id<b.id;
}

int main(){
	scanf("%d%d%d",&N,&K,&M);
	for(int i=1;i<=K;i++){
		scanf("%d",&prob[i]);
	}
	for(int i=0;i<maxn;i++){
		for(int j=1;j<=K;j++){
			stu[i].score[j]=-1;			
		}
		stu[i].grade=0;
		stu[i].perfect[i]=false;
		stu[i].com=false;
		stu[i].solve=0;
		stu[i].rank=10010;
	}
	int tid,pid,tscore;
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&tid,&pid,&tscore);
		stu[tid].id=tid;
//		if(tscore!=-1){
//			stu[tid].com=true;
//		}
		if(stu[tid].score[pid]<tscore){
			stu[tid].score[pid]=tscore;
			stu[tid].com=true;
		}
		if(stu[tid].score[pid]==-1&&tscore==-1){
			stu[tid].score[pid]=0;
		}
		if(stu[tid].score[pid]==prob[pid]){
			if(stu[tid].perfect[pid]==false){
				stu[tid].perfect[pid]=true;		
				stu[tid].solve++;
			}
		}
	}
//	for(int i=0;i<N+10;i++){
//		printf("#####%05d %d %d %d#####\n",stu[i].id,stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4]);
//	}
	for(int i=0;i<maxn;i++){
		for(int j=1;j<=K;j++){
			if(stu[i].score[j]!=-1)
				stu[i].grade+=stu[i].score[j];
		}
	}
	sort(stu,stu+maxn,cmp);
//	for(int i=0;i<N+10;i++){
//		printf("******%05d %d %d %d*****\n",stu[i].id,stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4]);
//	}
	stu[0].rank=1;
	for(int i=1;i<maxn;i++){
		if(stu[i].grade==stu[i-1].grade){
			stu[i].rank=stu[i-1].rank;
		}else{
			stu[i].rank=i+1;
		}
	}
	for(int i=0;i<maxn;i++){
		if(stu[i].com==true){
			printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].grade);
			for(int k=1;k<=K;k++){
				if(stu[i].score[k]!=-1){
					printf(" %d",stu[i].score[k]);
				}else{
					printf(" -");
				}
			}
			printf("\n");
		}
	}
	
	
	
	return 0;
}
