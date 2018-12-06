#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<set> 
#include<map> 
#include<algorithm>
using namespace std;

int n,m,k;

set<int> num[60];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			int temp;
			scanf("%d",&temp);
			num[i].insert(temp);
		}
	}
	scanf("%d",&k);
	int q1,q2;
	for(int i=1;i<=k;i++){
		scanf("%d %d",&q1,&q2);
		int nc=0,nt=num[q2].size();
		for(set<int>::iterator it=num[q1].begin();it!=num[q1].end();it++){
			if(num[q2].find(*it)!=num[q2].end()){
				nc++;
			}else{
				nt++;
			}
		}
		double sim=nc*100.0/nt;
		printf("%0.1f",sim);
		printf("%%");
		printf("\n");
		
	}	
	
	
	
	return 0;
}