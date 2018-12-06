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

const int maxn=1010;
int K;

int main(){
	scanf("%d",&K);
	for(int k=0;k<K;k++){
		int n;
		bool judge[maxn][maxn];	
		bool isprint=false;
		fill(judge[0],judge[0]+maxn*maxn,false);
		scanf("%d",&n);
		for(int x=1;x<=n;x++){
			int y;
			scanf("%d",&y);
			if(judge[x][y]==true&&isprint==false){
				printf("NO\n");
				isprint=true;
			}else if(judge[x][y]==false&&isprint==false){
				judge[x][y]=true;
				for(int i=1;i<=n;i++){
					judge[x][i]=true;
					judge[i][y]=true;
				}
				int i=0;
				while(x+i<=n&&y+i<=n){
					judge[x+i][y+i]=true;
					i++;
				}
				i=0;
				while(x+i<=n&&y-i>0){
					judge[x+i][y-i]=true;
					i++;	
				}
				i=0;
				while(x-i>0&&y+i<=n){
					judge[x-i][y+i]=true;
					i++;	
				}
				i=0;
				while(x-i>0&&y-i>0){
					judge[x-i][y-i]=true;
					i++;	
				}					
			}
		}
		if(isprint==false){
			printf("YES\n");
		}
		
	}
	
	
	
	
	
	
	
	return 0;
}