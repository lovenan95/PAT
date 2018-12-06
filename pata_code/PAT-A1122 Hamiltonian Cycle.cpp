#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<set>
using namespace std;

const int maxn=220;

int n,m;
int G[maxn][maxn]; 
int main(){
	fill(G[0],G[0]+maxn*maxn,0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int k;
		int in[maxn]={0};
		scanf("%d",&k);
		int st,temp;
		scanf("%d",&st);
		if(k<n){
			for(int j=1;j<k;j++){
				scanf("%d",&temp);
			}
			printf("NO\n");
		}else{
			int st0=st;
			in[st]++;
			bool isp=false;
			for(int j=1;j<k;j++){
				scanf("%d",&temp);
				in[temp]++;
				if(G[st][temp]!=1&&isp==false){
					printf("NO\n");
					isp=true; 					
				}		
				st=temp;		
			}	
			for(int i=1;i<k;i++){
				if(in[i]!=2&&i==st0&&isp==false){
					printf("NO\n");
					isp=true; 					
				}
				if(i!=st0&&in[i]!=1&&isp==false){
					printf("NO\n");
					isp=true; 
				}
			
			}
			if(isp==false){
				printf("YES\n");
			}
		}
	}
	return 0;
}









