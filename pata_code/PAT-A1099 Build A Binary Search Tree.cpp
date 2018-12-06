#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<stack> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

const int maxn=110;
int n,a[maxn],idx=0;

struct node{
	int value;
	int left;
	int right;
}tre[maxn];

void inorder(int root){
	if(root==-1)
		return;
	inorder(tre[root].left);
	tre[root].value=a[idx++];
	inorder(tre[root].right);
}
int cnt=0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		printf("%d",tre[top].value);
		cnt++;
		if(cnt<n){
			printf(" ");
		}
		if(tre[top].left!=-1)
			q.push(tre[top].left);
		if(tre[top].right!=-1)
			q.push(tre[top].right);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int lf,rt;
		scanf("%d %d",&lf,&rt);
		tre[i].left=lf;
		tre[i].right=rt;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	inorder(0);
	BFS(0);
	
	
	
	
	
	
	
	return 0;
}











