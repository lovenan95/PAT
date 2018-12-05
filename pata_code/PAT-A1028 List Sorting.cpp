#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<algorithm>
using namespace std;

struct node{
	char id[10];
	char name[10];
	int grade;
}temp;

int N,C;
vector<node> stu;

bool cmp1(node a,node b){
	if(strcmp(a.id,b.id)!=0)
		return strcmp(a.id,b.id)<0;
}

bool cmp2(node a,node b){
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	else if(strcmp(a.id,b.id)!=0)
		return strcmp(a.id,b.id)<0;
}

bool cmp3(node a,node b){
	if(a.grade!=b.grade)
		return a.grade<b.grade; 
	else if(strcmp(a.id,b.id)!=0)
		return strcmp(a.id,b.id)<0;
}

int main(){
	scanf("%d %d",&N,&C);
	for(int i=0;i<N;i++){
		scanf("%s %s %d",temp.id,temp.name,&temp.grade);
		stu.push_back(temp);	
	}
	if(C==1){
		sort(stu.begin(),stu.end(),cmp1);
	}
	if(C==2){
		sort(stu.begin(),stu.end(),cmp2);
	}
	if(C==3){
		sort(stu.begin(),stu.end(),cmp3);
	}	
	for(int i=0;i<N;i++){
		printf("%s %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
	
	
	
	return 0;
}
