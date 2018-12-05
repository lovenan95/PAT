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

const int maxn=10010;
int n,m,k;

bool vis[maxn];
int degree[maxn]={0};
vector<int> vt[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		vt[u].push_back(v);
		vt[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int nv;
		int cnt=0;
		int tempdegree[maxn];
		for(int i=0;i<n;i++){
			tempdegree[i]=degree[i];
		}
		scanf("%d",&nv);
		memset(vis,false,sizeof(vis));
		for(int j=0;j<nv;j++){
			int temp;
			scanf("%d",&temp);
			vis[temp]=true;
			for(int p=0;p<vt[temp].size();p++){
				if(vis[vt[temp][p]]==false)
					tempdegree[vt[temp][p]]--;
			}
			cnt+=tempdegree[temp];			
		}
		if(cnt==m){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		
	}
	
	
	
	
	
	
	
	
	return 0;
}






