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
int in[maxn],post[maxn];

struct node{
	int data;
	int layer;
	node* left;
	node* right;	
};

node* create(int postl,int postr,int inl,int inr){
	if(postl>postr){
		return NULL;
	}
	node* root=new node;
	root->data=post[postr];
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==post[postr]){
			break;
		}
	}
	int numleft=k-inl;
	root->left=create(postl,postl+numleft-1,inl,k-1);
	root->right=create(postl+numleft,postr-1,k+1,inr);
	return root;
}
vector<int> temp[maxn];
int maxlayer=0;
void BFS(node* root){
	queue<node*> q;
	root->layer=1;	
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		maxlayer=max(maxlayer,top->layer);
		temp[top->layer].push_back(top->data);
		if(top->left!=NULL){
			top->left->layer=top->layer+1;
			q.push(top->left);
		}
		if(top->right!=NULL){
			top->right->layer=top->layer+1;
			q.push(top->right);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	node* root;
	root=create(0,n-1,0,n-1);
	BFS(root);
	int cnt=0;
	for(int i=1;i<=maxlayer;i++){
		if(i%2==0){
			for(int j=0;j<temp[i].size();j++){
				printf("%d",temp[i][j]);
				cnt++;
				if(cnt<n){
					printf(" ");
				}
			}
		}else{
			for(int j=temp[i].size()-1;j>=0;j--){
				printf("%d",temp[i][j]);
				cnt++;
				if(cnt<n){
					printf(" ");
				}
			}
		}
	}
	
	
	
	
	
	
	
	return 0;
}
 









