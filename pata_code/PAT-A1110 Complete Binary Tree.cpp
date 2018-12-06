#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<stack> 
#include<string.h> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

const int maxn=50;
int n;
struct node{
	int data;
	int left;
	int right;
}tre[maxn];
int last;
bool iscbt(int root){
	queue<int> q;
	q.push(root);
	while(n--){
		int top=q.front();
		q.pop();
		last=top;
//		cout<<"last="<<last<<endl;
		if(top==-1){
			return false;
		}
		q.push(tre[top].left);
		q.push(tre[top].right);
	}
	return true;
}

int main(){
	scanf("%d",&n);
	string str1,str2;
	int notroot[maxn]={false};
	for(int i=0;i<n;i++){
		cin>>str1>>str2;
		int lf,rt;
		if(str1=="-"){
			tre[i].left=-1;
		}else{
			sscanf(str1.c_str(),"%d",&lf);
			tre[i].left=lf;
			notroot[lf]=true;
		}
		if(str2=="-"){
			tre[i].right=-1;
		}else{
			sscanf(str2.c_str(),"%d",&rt);
			tre[i].right=rt;
			notroot[rt]=true;
		}
	}	
	int root;
	for(int i=0;i<n;i++){
		if(notroot[i]==false){
			root=i;
		}
	}
	if(iscbt(root)==true){
		printf("YES %d",last);
	}else{
		printf("NO %d",root);
	}
	
	
	
	
	
	
	return 0;
} 











