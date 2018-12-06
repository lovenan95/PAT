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

int pre[maxn],in[maxn];
int N;
stack<int> st;

struct node{
	int data;
	node* left;
	node* right;
};

node* create(int prel,int prer,int inl,int inr){
	if(prel>prer)
		return NULL;
	node* root=new node;
	root->data=pre[prel];
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==pre[prel])
			break;
	}
	int numleft=k-inl;
	root->left=create(prel+1,prel+numleft,inl,k-1);
	root->right=create(prel+numleft+1,prer,k+1,inr);
	return root;
}
int cnt=0;
void postorder(node* root){
	if(root->left!=NULL)
		postorder(root->left);
	if(root->right!=NULL)
		postorder(root->right);
	printf("%d",root->data);
	cnt++;
	if(cnt<N){
		printf(" ");
	}
}

int main(){
	scanf("%d",&N);
	int numpre=0,numin=0;
	for(int i=0;i<2*N;i++){
		string op;
		cin>>op;
		if(op=="Push"){
			int temp;
			scanf("%d",&temp);
			pre[numpre++]=temp;
			st.push(temp);
		}else{
			in[numin++]=st.top();
			st.pop();
		}
	}
//	for(int i=0;i<N;i++){
//		printf("%d ",pre[i]);
//	}
//	printf("\n");
//	for(int i=0;i<N;i++){
//		printf("%d ",in[i]);
//	}	
	node* root=create(0,N-1,0,N-1);
	postorder(root);
	return 0;
} 
























