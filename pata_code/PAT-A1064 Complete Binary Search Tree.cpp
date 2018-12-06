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

int n,index=1;
int a[1010],cbt[1010];

void inorder(int root){
	if(root>n)
		return;
	inorder(root*2);
	cbt[root]=a[index++];
	inorder(root*2+1);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	inorder(1);
	for(int i=1;i<=n;i++){
		printf("%d",cbt[i]);
		if(i<n){
			printf(" ");
		}else
			printf("\n"); 
	}
	return 0;
}