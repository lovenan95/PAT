#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<algorithm>
using namespace std;

int N,maxg,ming;
struct node{
	char name[20];
	char id[20];
	int grade;
}temp;
vector<node> st;
bool cmp(node a,node b){
	if(a.grade!=b.grade)
		return a.grade>b.grade;
	
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %s %d",temp.name,temp.id,&temp.grade);
		st.push_back(temp);
	}
	scanf("%d %d",&ming,&maxg);
	sort(st.begin(),st.end(),cmp);
	bool flag=false;
	for(int i=0;i<N;i++){
		if(st[i].grade<=maxg&&st[i].grade>=ming){
			flag=true;
			printf("%s %s\n",st[i].name,st[i].id);
		}
	}
	if(flag==false){
		printf("NONE");
	}
	
	
}