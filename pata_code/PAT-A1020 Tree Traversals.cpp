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
const int maxn=50;

int n;
int post[maxn];
int in[maxn];

struct node{
	int data;
	node* left;
	node* right;
};

node* create(int pl,int pr,int il,int ir){
	if(pl>pr)
		return NULL;
	node* root=new node;
	root->data=post[pr];
	int i;
	for(i=il;i<=ir;i++){
		if(in[i]==post[pr])
			break;
	}
	int numleft=i-il;
	root->left=create(pl,pl+numleft-1,il,i-1);
	root->right=create(pl+numleft,pr-1,i+1,ir);
	return root;
}

int num=0;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		printf("%d",top->data);
		num++;
		if(num<n){
			printf(" ");
		}
		if(top->left!=NULL)
			q.push(top->left);
		if(top->right!=NULL)
			q.push(top->right);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}	
	node* root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}
















