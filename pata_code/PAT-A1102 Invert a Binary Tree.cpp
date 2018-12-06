#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<stack> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;
const int maxn=20;

int N;

struct btree{
	int data;
	int left;
	int right;
	btree(){
		left=-1;
		right=-1;
	}
}node[maxn];
int cntlevel=0;
void levelorder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		printf("%d",temp);
		cntlevel++;
		if(cntlevel<N){
			printf(" ");
		}else{
			printf("\n");
		}
		q.pop();
		if(node[temp].left!=-1)
			q.push(node[temp].left);
		if(node[temp].right!=-1)
			q.push(node[temp].right);
	}
	
	
}
int cntin=0;
void inorder(int root){
	if(root==-1)
		return;
	inorder(node[root].left);
	printf("%d",root);
	cntin++;
	if(cntin<N){
		printf(" ");
	}else{
		printf("\n");
	}
	inorder(node[root].right);
}

bool findroot[maxn]={false};

int main(){
	scanf("%d",&N);
	getchar();/*!!!!!!!!!!!!*/
	for(int i=0;i<N;i++){
		char r,l;
		node[i].data=i;
		scanf("%c %c",&r,&l);
//		cout<<"r=   "<<r<<"   "<<"l=   "<<l<<endl;
		if(r!='-'){
			node[i].right=r-'0';
			findroot[r-'0']=true;
		}else{
			node[i].right=-1;
		}
		if(l!='-'){
			node[i].left=l-'0';
			findroot[l-'0']=true;
		}else{
			node[i].left=-1;
		}
		getchar();
	}
	int root;
	for(int i=0;i<N;i++){
		if(findroot[i]==false){
			root=i;
			break;
		}
	}
	levelorder(root);
	inorder(root);
	
	
	
	
	
	
	
	
	
	
	return 0;
}



















