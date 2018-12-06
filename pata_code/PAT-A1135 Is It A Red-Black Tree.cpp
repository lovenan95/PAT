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
using namespace std;

int K,n;

struct node{
	int data;
	node* left;
	node* right;
};

void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(abs(root->data)<abs(data)){
		insert(root->right,data);
	}else{
		insert(root->left,data);
	}	
}



vector<int> path,tempath;

int cal(vector<int> v){
	int num=0;
	for(int i=0;i<v.size();i++){
		if(v[i]>0){
			num++;
		}
	}
	return num;
}
bool flag=true;
void DFS(node* root){
	if(root==NULL){
		if(path.size()!=0){
			if(cal(path)!=cal(tempath)){
				flag=false;
			}
		}
		path=tempath;
		return;
	}
	tempath.push_back(root->data);
	DFS(root->left);
	tempath.pop_back();
	tempath.push_back(root->data);
	DFS(root->right);
	tempath.pop_back();
	
}

vector<int> org,pre,in;

void preorder(node* root){
	if(root==NULL){
		return ;
	}
	pre.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	in.push_back(root->data);	
	inorder(root->right);
}

bool BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		if(top->data<0){
			if(top->left!=NULL&&top->left->data<0){
				return false;
			}
			if(top->right!=NULL&&top->right->data<0){
				return false;
			}			
		}
		flag=true;
		tempath.clear();
		path.clear();
		DFS(top);
		if(flag==false){
			return false;
		}
		if(top->left!=NULL){
			q.push(top->left);
		}
		if(top->right!=NULL){
			q.push(top->right);
		}
	}
	return true;
}


//void DFS(node* root,int count){
//	if(root->left==NULL&&root->left==NULL){
//		if(count!=cnt){
//			flag=false;
//			return;
//		}	
//	}
//	if(root->left!=NULL&&root->left->data>0)
//		DFS(root->left,count+1);
//	if(root->left!=NULL&&root->left->data<0)
//		DFS(root->left,count);
//	if(root->right!=NULL&&root->right->data>0)
//		DFS(root->right,count+1);
//	if(root->right!=NULL&&root->right->data<0)
//		DFS(root->right,count);					
//}

//int getNum(node *root) {
//    if (root == NULL) return 0;
//    int l = getNum(root->left);
//    int r = getNum(root->right);
//    return root->data > 0 ? max(l, r) + 1 : max(l, r);
//}
//bool judge2(node *root) {
//    if (root == NULL) return true;
//    int l = getNum(root->left);
//    int r = getNum(root->right);
//    if(l != r) return false;
//    return judge2(root->left) && judge2(root->right);
//}

bool cmp(int a,int b){
	return abs(a)<abs(b);
}

int main(){
	scanf("%d",&K);
	for(int k=0;k<K;k++){
		scanf("%d",&n);	
		node* root=NULL;
		bool isprint=false;	
		org.clear();
		pre.clear();
		in.clear();
		for(int i=0;i<n;i++){
			int temp;
			scanf("%d",&temp);
			org.push_back(temp);
			if(temp==0&&isprint==false){
				printf("No\n");
				isprint=true;
			}
			insert(root,temp);
		}
		preorder(root);
		inorder(root);
		if(pre!=org&&isprint==false){
			printf("No\n");
			isprint=true;
			continue;
		}
		sort(org.begin(),org.end(),cmp);
//		for(int i=0;i<org.size();i++){
//			printf("%d ",org[i]);
//		}
//		printf("pre\n");
//		for(int i=0;i<in.size();i++){
//			printf("%d ",in[i]);
//		}
//		printf("in\n");		
		if(in!=org&&isprint==false){
			printf("No\n");
			isprint=true;
			continue;
		}		
		if(root<0&&isprint==false){
			printf("No\n");
			isprint=true;
			continue;
		}
		if(BFS(root)==false&&isprint==false){
			printf("No\n");
			isprint=true;
			continue;
		}
//		cnt=1;
//		node* srch=root;
//		while(srch->left!=NULL||srch->right!=NULL){
//			if(srch->left!=NULL){
//				srch=srch->left;
//			}else{
//				if(srch->right!=NULL)
//					srch=srch->right;
//			}
//			if(srch->data>0){
//				cnt++;
//			}
//		}
//		DFS(root,1);

//		DFS(root);
//		if(flag==false&&isprint==false){
//			printf("No\n");
//			isprint=true;
//			continue;			
//		}
		if(isprint==false){
			printf("Yes\n");
		}
	}	
	return 0;
} 









