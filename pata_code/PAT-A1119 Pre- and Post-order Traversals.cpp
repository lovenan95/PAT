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
const int maxn=50;
int n;
int pre[maxn],post[maxn];

struct node{
	int data;
	node* left;
	node* right;
};
bool isunique=true;
node* create(int prel,int prer,int postl,int postr){
	if(prel>prer){
		return NULL;
	}
	node* root=new node;
	root->data=pre[prel];
	int k,numleft=0;
	for(k=postl;k<=postr-1;k++){
		numleft++;
		if(pre[prel+1]==post[k]){
			break;
		}
	}
	if(k==postr-1)	isunique=false;
	root->left=create(prel+1,prel+numleft,postl,k);
	root->right=create(prel+numleft+1,prer,k+1,postr-1);
	return root;
}
int cnt=0;
void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d",root->data);
	cnt++;
	if(cnt<n){
		printf(" ");
	}else{
		printf("\n");
	}
	inorder(root->right);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}	
	node* root=create(0,n-1,0,n-1);
	if(isunique==false){
		printf("No\n");
		inorder(root);
	}else{
		printf("Yes\n");
		inorder(root);
	}
	
	
	
	return 0;
}

















