#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<stack> 
#include<math.h> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

int N,K,P;
int ex[500];
int maxfac=-1;
vector<int> ans,temp;

void DFS(int index,int nowk,int sum,int fac){
	if(sum==N&&nowk==K){
		if(fac>maxfac){
			maxfac=fac;
			ans=temp;
		}
		return;
	}
	if(sum>N||nowk>K)
		return;
	if(index>=1){
		temp.push_back(index);
		DFS(index,nowk+1,sum+ex[index],fac+index);
		temp.pop_back();
		DFS(index-1,nowk,sum,fac);
	}
	
}

int main(){
	scanf("%d%d%d",&N,&K,&P);
	int cnt=0,temp=0;
	while(temp<=N){
		ex[cnt]=pow(cnt,P);
		temp=ex[cnt];
		cnt++;
	}
	DFS(cnt-1,0,0,0);
	if(maxfac==-1){
		printf("Impossible\n");
	}else{
		printf("%d = ",N);
		for(int i=0;i<K;i++){
			printf("%d^%d",ans[i],P);
			if(i<K-1){
				printf(" + ");
			}
		}
	}
	return 0;
}




