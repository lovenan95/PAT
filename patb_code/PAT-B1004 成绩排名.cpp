#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	string name;
	string id;
	int score;
};
bool cmp(node a,node b){
	return a.score>b.score;
}
vector<node> stu;
int n;
int main(){
	scanf("%d",&n);
	string str1,str2;
	int s;
	for(int i=0;i<n;i++){
		cin>>str1;
		cin>>str2;
		cin>>s;
		node temp;
		temp.id=str2;
		temp.name=str1;
		temp.score=s;
		stu.push_back(temp);
	}
	sort(stu.begin(),stu.end(),cmp);
	cout<<stu[0].name<<" "<<stu[0].id<<endl;
	cout<<stu[n-1].name<<" "<<stu[n-1].id<<endl;
	return 0;
}