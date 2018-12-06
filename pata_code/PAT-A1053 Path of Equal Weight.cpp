#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
using namespace std;

const int maxn=1010;
int n,m,s;
struct node{
	int data;
	vector<int> child;
}tre[maxn];

vector<int> path,tempath;
void DFS(int root,int sum){
	if(sum>s){
		return;
	}
	if(sum==s){
		if(tre[root].child.size()!=0){
			return;
		}else{
//			tempath.push_back(root);
			for(int i=0;i<tempath.size();i++){
				printf("%d",tre[tempath[i]].data);
				if(i<tempath.size()-1){
					printf(" ");
				}else{
					printf("\n");
				}
			}
//			tempath.pop_back();
		}
	}
//	tempath.push_back(root);
	for(int i=0;i<tre[root].child.size();i++){
		int next=tre[root].child[i];
		tempath.push_back(next);
		DFS(next,sum+tre[next].data);
		tempath.pop_back();
	}
//	tempath.pop_back();
}

bool cmp(int a,int b){
	return tre[a].data>tre[b].data;
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&tre[i].data);
	}
	for(int i=0;i<m;i++){
		int rt,k,ch;
		scanf("%d%d",&rt,&k);
		for(int i=0;i<k;i++){
			scanf("%d",&ch);
			tre[rt].child.push_back(ch);
		}
		sort(tre[rt].child.begin(),tre[rt].child.end(),cmp);
	}
	int root=0;
	tempath.push_back(root);
	DFS(root,tre[root].data);
	tempath.pop_back();	
	return 0;
}






