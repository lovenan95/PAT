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

int n,a[30];
struct node{
	int value;
	int height; 
	node* left;
	node* right;
}tre[30];

int getheight(node* root){
	if(root==NULL)
		return 0;
	return root->height;
} 

void updateheight(node* root){
	root->height=max(getheight(root->left),getheight(root->right))+1;
}

int getbalance(node* root){
	return getheight(root->left)-getheight(root->right);
}

void R(node* &root){
	node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}

void L(node* &root){
	node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}

void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->height=1;
		root->left=NULL;
		root->right=NULL;
		root->value=data;
		return;
	}
	if(root->value>data){
		insert(root->left,data);
		updateheight(root);
		if(getbalance(root)==2){
			if(getbalance(root->left)==1){
				R(root);
			}else if(getbalance(root->left)==-1){
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,data);
		updateheight(root);
		if(getbalance(root)==-2){
			if(getbalance(root->right)==-1){
				L(root);
			}else if(getbalance(root->right)==1){
				R(root->right);
				L(root);
			}
		}
	}
}

int main(){
	node* root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	printf("%d\n",root->value);
	return 0;
}











