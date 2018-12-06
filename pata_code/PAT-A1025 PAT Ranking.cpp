#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct student{
	char id[13];
	int score;
	int loc;
	int lrank;
	int rank;
}stu[40000];
bool cmp(student a,student b){
	if(a.score!=b.score)
		return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	int n,k,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=k;j>0;j--){
			scanf("%s %d",stu[num].id,&stu[num].score);
			stu[num].loc=i;
			num++;
		}
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].lrank=1;
		for(int j=num-k+1;j<num;j++){
			if(stu[j].score==stu[j-1].score)
				stu[j].lrank=stu[j-1].lrank;
			else{
				stu[j].lrank=j+1-(num-k);
			}
		}
	}
	sort(stu,stu+num,cmp);
	stu[0].rank=1;
	for(int i=1;i<num;i++){
		if(stu[i].score==stu[i-1].score)
			stu[i].rank=stu[i-1].rank;
		else{
			stu[i].rank=i+1;
		}
	}
	
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		printf("%s %d %d %d\n",stu[i].id,stu[i].rank,stu[i].loc,stu[i].lrank);
	}
	
	return 0;
}
