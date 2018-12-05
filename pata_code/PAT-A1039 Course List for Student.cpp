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

const int maxn=400010;
int n,k;
vector<int> stu[maxn];

int getid(char name[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=name[i]-'A'+id*26;
	}
	id=id*10+name[3]-'0';
	return id;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		int cid,cnum;
		scanf("%d%d",&cid,&cnum);
		for(int j=0;j<cnum;j++){
			char name[8];
			scanf("%s",name);
			int id=getid(name);
			stu[id].push_back(cid);
		}
	}
	for(int i=0;i<n;i++){
		char name[8];
		scanf("%s",name);
		printf("%s",name);
		int id=getid(name);
		sort(stu[id].begin(),stu[id].end());
		printf(" %d",stu[id].size());
		for(int j=0;j<stu[id].size();j++){
			printf(" %d",stu[id][j]);
		}
		printf("\n");
	}
	
	
	
	
	return 0;
} 











