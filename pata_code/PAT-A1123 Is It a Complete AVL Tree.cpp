#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<set>
using namespace std;

struct node{
	int v,height;
	node* lchild,*rchild;
}*root;

node* newnode(int v){
	node* Node=new node;
	Node->v=v;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node;
}

int geth(node* root){
	if(root==NULL){
		return 0;
	}
	return root->height;
}

void update(node* root){
	root->height=max(geth(root->lchild),geth(root->rchild))+1;
}

int getblc(node* root){
	return geth(root->lchild)-geth(root->rchild);
}

void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	update(root);
	update(temp);
	root=temp;
}

void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	update(root);
	update(temp);
	root=temp;
}

void insert(node* &root,int v){
	if(root==NULL){
		root=newnode(v);
		return;
	}
	if(v<root->v){
		insert(root->lchild,v);
		update(root);
		if(getblc(root)==2){
			if(getblc(root->lchild)==1){
				R(root);
			}else if(getblc(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,v);
		update(root);
		if(getblc(root)==-2){
			if(getblc(root->rchild)==-1){
				L(root);
			}else if(getblc(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
}
int cnt=0;
void BFS(node* root,int n){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		printf("%d",top->v);
		cnt++;
		if(cnt<n)
			printf(" ");
		else
			printf("\n");
		if(top->lchild!=NULL){
			q.push(top->lchild);
		}
		if(top->rchild!=NULL){
			q.push(top->rchild);
		}
	}
}
int cnt2=0;
bool judgecomplete(node* root,int n){
	queue<node*> q;
	q.push(root);
	while(n){//注意这里while（n），不写！q.empty() 
		node* top=q.front();
		q.pop();
		if(top==NULL)
			return false;
		n--;	
		q.push(top->lchild);//空节点也入队，如果在全部入队完前就有空节点出队说明非完全 
		q.push(top->rchild);
	}
	return true;
}

int main(){
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	BFS(root,n);
	if(judgecomplete(root,n)==true){
		printf("YES\n");
	}else{
		printf("NO\n");	
	}
	
}








