#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<set>
#include<map>
using namespace std;

const int maxn=2010;
int n,m; 
int numstu=0;
int Rank[1000000][4];
struct node{
	int id;
	int grade[4];
}stu[maxn];
char sub[8]={'A','C','M','E'};
int now;
bool cmp(node a,node b){
	return a.grade[now]>b.grade[now];
}

int main(){
	fill(Rank[0],Rank[0]+1000000*4,2010);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int nid,c,ma,en,ag;
		scanf("%d%d%d%d",&nid,&c,&ma,&en);
		stu[i].id=nid;
		stu[i].grade[1]=c;
		stu[i].grade[2]=ma;
		stu[i].grade[3]=en;
		stu[i].grade[0]=c+ma+en;
	}	
	for(now=0;now<4;now++){
		sort(stu,stu+n,cmp);
		Rank[stu[0].id][now]=1;
		for(int i=1;i<n;i++){
			if(stu[i].grade[now]==stu[i-1].grade[now])
				Rank[stu[i].id][now]=Rank[stu[i-1].id][now];
			else{
				Rank[stu[i].id][now]=i+1;
			}	
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<4;j++){
//			printf("%d %c\n",Rank[stu[i].id][j],sub[j]);		
//		}
//		printf("****************\n");
//	}
	
	for(int i=0;i<m;i++){
		int ask;
		scanf("%d",&ask);
		if(Rank[ask][0]==2010){
			printf("N/A\n");
		}else{
			int best=0;
			for(int j=1;j<4;j++){
				if(Rank[ask][best]>Rank[ask][j]){
					best=j;
				}
			}
			printf("%d %c\n",Rank[ask][best],sub[best]);
			
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}









