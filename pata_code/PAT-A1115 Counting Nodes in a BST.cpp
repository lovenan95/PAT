#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int N,n1,n2;

struct node{
	int data;
	int level;
	node* left;
	node* right;
};

void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->left=root->right=NULL;
		root->data=data;
		return;
	}
	if(root->data>=data)
		insert(root->left,data);
	if(root->data<data)
		insert(root->right,data);
}

int maxlev=0;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	root->level=1;
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		maxlev=max(maxlev,top->level);
		if(top->left!=NULL){
			q.push(top->left);	
			top->left->level=top->level+1;
		}
		if(top->right!=NULL){
			q.push(top->right);	
			top->right->level=top->level+1;		
		}
	}
}

void BFScount(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		if(top->level==maxlev){
			n1++;
		}else if(top->level==maxlev-1){
			n2++;
		}
		if(top->left!=NULL){
			q.push(top->left);	
		}
		if(top->right!=NULL){
			q.push(top->right);	
		}
	}
}

vector<int> origin;

int main(){
	scanf("%d",&N);
	node* root=NULL;
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		origin.push_back(temp);
		insert(root,temp);
	}	
	BFS(root);
	BFScount(root);
	printf("%d + %d = %d",n1,n2,n1+n2);
	
	
	
	
	
	
	
	
	
	return 0;
}










