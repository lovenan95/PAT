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

const int maxn=1010;
int n;
vector<int> org,pre,mir;

struct node{
	int data;
	node* left;
	node* right;
}tre[maxn];

void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return;
	}
	if(root->data<=data){
		insert(root->right,data);
	}
	if(root->data>data){
		insert(root->left,data);
	}
}

void preorder(node* root){
	if(root==NULL)
		return;
	pre.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}

void mirpreorder(node* root){
	if(root==NULL)
		return;
	mir.push_back(root->data);
	mirpreorder(root->right);
	mirpreorder(root->left);
}

int cnt=0;
void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
	cnt++;
	if(cnt<n){
		printf(" ");
	}
}

int cntm=0;
void mirpostorder(node* root){
	if(root==NULL){
		return;
	}
	mirpostorder(root->right);
	mirpostorder(root->left);
	printf("%d",root->data);
	cntm++;
	if(cntm<n){
		printf(" ");
	}
}

int main(){
	node* root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		org.push_back(temp);
		insert(root,temp);
	}	
	preorder(root);
	mirpreorder(root);
//	for(int i=0;i<mir.size();i++){
//		printf("%d ",mir[i]);
//	}
	if(pre==org){
		printf("YES\n");
		postorder(root);
	}else if(mir==org){
		printf("YES\n");
		mirpostorder(root);
	}else{
		printf("NO\n");		
	}
	return 0;
} 
















