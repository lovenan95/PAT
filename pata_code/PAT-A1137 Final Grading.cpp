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

int p,m,n;

struct node{
	string name;
	int assign;
	int mid;
	int final;
	int grade;
	node(){
		assign=-1;
		mid=-1;
		final=-1;
		grade=-1;		
	}
}stu[100010];

map<string,int> idx;

bool cmp(node a,node b){
	if(a.grade!=b.grade){
		return a.grade>b.grade;
	}else{
		return a.name<b.name;
	}
}

int main(){
	scanf("%d%d%d",&p,&m,&n);
	int cnt=0;
	for(int i=0;i<p;i++){
		string tn;
		int as;
		cin>>tn>>as;
		if(idx.find(tn)==idx.end()){
			idx[tn]=cnt;
			cnt++;
		}
		stu[idx[tn]].name=tn;
		stu[idx[tn]].assign=as;
	}	
	for(int i=0;i<m;i++){
		string tn;
		int mid;
		if(idx.find(tn)==idx.end()){
			idx[tn]=cnt;
			cnt++;
		}		
		cin>>tn>>mid;
		stu[idx[tn]].name=tn;
		stu[idx[tn]].mid=mid;
	}
	for(int i=0;i<n;i++){
		string tn;
		int fi;
		cin>>tn>>fi;
		if(idx.find(tn)==idx.end()){
			idx[tn]=cnt;
			cnt++;
		}		
		stu[idx[tn]].name=tn;
		stu[idx[tn]].final=fi;
	}	
	for(int i=0;i<cnt;i++){
		if(stu[i].mid>stu[i].final){
			stu[i].grade=int (stu[i].mid*0.4+stu[i].final*0.6+0.5);
		}else{
			stu[i].grade=stu[i].final;
		}
	}
	sort(stu,stu+cnt,cmp);
	for(int i=0;i<=cnt;i++){
		if(stu[i].grade>=60&&stu[i].grade<=100&&stu[i].assign>=200){
			cout<<stu[i].name;
			printf(" %d %d %d %d",stu[i].assign,stu[i].mid,stu[i].final,stu[i].grade);
			printf("\n");
		}
	}
	return 0;
}










