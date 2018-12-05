#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<stack> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

struct node{
	int weight;
	int rank;
}mice[1010];

int np,ng;
queue<int> q[1010];
int fat[1010];

int main(){
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		scanf("%d",&mice[i].weight);
	}
	int order;
	for(int i=0;i<np;i++){
		scanf("%d",&order);
		q[0].push(order);
	}
	int v=0;
	while(q[v].size()>1){
		int turn;
//			cout<<v<<"***************\n";
		int tnp=q[v].size();
		if(tnp%ng==0){
			turn=tnp/ng;
		}else{
			turn=tnp/ng+1;
		}
		fat[v]=q[v].front();
//		cout<<v<<"***************\n";
//		cout<<max<<"%%%%%%%%%%%\n";
		for(int h=0;h<turn;h++){
			memset(fat,-1,sizeof(fat));
			for(int i=0;i<ng;i++){
				if(q[v].empty()){
					break;
				}
				int now=q[v].front();
				if(mice[now].weight>mice[fat[v]].weight){
					fat[v]=now;
				}
				mice[now].rank=turn+1;
//				cout<<"turn="<<turn<<endl;
//				cout<<"³ö¶Ó"<<q[v].front()<<"\n";
				q[v].pop();
			}
			q[v+1].push(fat[v]);
//			cout<<"fat="<<fat[v]<<endl;
		}
//		cout<<"++++++++++++++"<<endl;
		v++;	
	}	
	int fatest=q[v].front();
	mice[fatest].rank=1;
	for(int i=0;i<np;i++){
		printf("%d",mice[i].rank);
		if(i<np-1){
			printf(" ");
		}
	}
	return 0;
}



