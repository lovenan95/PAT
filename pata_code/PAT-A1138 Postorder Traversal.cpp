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

const int maxn=50010;
int n;
int pre[maxn],in[maxn],post[maxn];

struct node{
	int data;
	node* left;
	node* right;
};

node* create(int prel,int prer,int inl,int inr){
	if(prel>prer){
		return NULL;
	}
	node* root=new node;
	root->data=pre[prel];
	int k;
	for(k=inl;k<=inr;k++){//注意！！！！！！！k的初始值为inl 
		if(in[k]==root->data){
			break;
		}
	}
	int numleft=k-inl;
	root->left=create(prel+1,prel+numleft,inl,k-1);
	root->right=create(prel+numleft+1,prer,k+1,inr);
	return root;
}
int cunt=0;
void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	post[cunt++]=root->data; 
} 

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}	
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}	
	node* root;
	root=create(0,n-1,0,n-1);	
	postorder(root);
	printf("%d",post[0]);
	
	
	
	
	
	return 0;
} 





