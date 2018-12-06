#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

const int maxn=50;
int n;
struct node{
	string data;
	int left;
	int right;
	node(){
		left=-1;
		right=-1;
	}
}tre[maxn];
bool notroot[maxn]={false};
void inorder(int root,int depth){
	if(root==-1){
		return;
	}
	if(depth!=0&&(tre[root].left!=-1||tre[root].right!=-1))
	printf("(");
	inorder(tre[root].left,depth+1);
	cout<<tre[root].data;	
	inorder(tre[root].right,depth+1);
	if(depth!=0&&(tre[root].right!=-1||tre[root].left!=-1))	
	printf(")");		
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string temp;
		int lf,rt;
		cin>>temp;
		scanf("%d%d",&lf,&rt);
		tre[i].data=temp;
		tre[i].left=lf;
		tre[i].right=rt;
		if(lf!=-1){
			notroot[lf]=true;			
		}
		if(rt!=-1){
			notroot[rt]=true;
		}
	}
	int root;
	for(int i=1;i<maxn;i++){
		if(notroot[i]==false){
			root=i;
			break;
		}
	}
	inorder(root,0);
	return 0;
}










