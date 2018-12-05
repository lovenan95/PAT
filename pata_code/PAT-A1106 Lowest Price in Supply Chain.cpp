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

const int maxn=100010;
int n,cnt=0;
double p,r,pmin;

struct node{
	int data;
	double price;
	vector<int> child;
}sell[maxn];

void DFS(int index,int depth){
	if(sell[index].child.size()==0){
		double price=p*pow(1+r/100.0,depth);
//		cout<<"price="<<price<<endl;
		if(pmin>price){
			pmin=price;
			cnt=1;
		}else if(pmin==price){
			cnt++;
		}
		return;
	}
	for(int i=0;i<sell[index].child.size();i++){
		DFS(sell[index].child[i],depth+1);
	}
}

int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	pmin=1000000000;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				int temp;
				scanf("%d",&temp);
				sell[i].child.push_back(temp);
			}
		}
	}
	DFS(0,0);	
	printf("%0.4f %d",pmin,cnt);
	return 0;
}










