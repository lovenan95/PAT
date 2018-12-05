#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n,k;

vector<string> course[2510];

int main(){
	scanf("%d%d",&n,&k);
	string name;
	int num,ke;
	for(int p=1;p<=n;p++){
		cin>>name;
		scanf("%d",&num);
		for(int i=1;i<=num;i++){
			scanf("%d",&ke);
			course[ke].push_back(name);
		}
	}
	for(int p=1;p<=k;p++){
		int len=course[p].size();
		sort(course[p].begin(),course[p].end());
		printf("%d %d\n",p,len);
		for(int i=0;i<len;i++){
			cout<<course[p][i]<<'\n';
		}
	}
	
	
	
	
	
	
	
	return 0;
}