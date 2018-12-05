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
#include<map>
using namespace std;

const int maxn=50010;
int n,k;
int hashtab[maxn]={0};
vector<int> rec;
set<int> st;
bool cmp(int a,int b){
	if(hashtab[a]!=hashtab[b])
		return hashtab[a]>hashtab[b];
	else 
		return a<b;
}
bool isp[maxn]={false};
int main(){
	scanf("%d%d",&n,&k);
	int fst;
	scanf("%d",&fst);
	hashtab[fst]++;
	st.insert(fst);
	for(int i=2;i<=n;i++){
		int now;
		memset(isp,false,sizeof(isp));
		int cntp=0;
		scanf("%d",&now);
		printf("%d: ",now);
		rec.clear();
		for(set<int>:: iterator it=st.begin();it!=st.end();it++){
			rec.push_back(*it);
		}
		sort(rec.begin(),rec.end(),cmp);
		for(int i=0;i<rec.size();i++){
			if(isp[rec[i]]==false){
				printf("%d",rec[i]);
				isp[rec[i]]=true;
				cntp++;
				int size=rec.size();
				if(cntp<min(size,k)){
					printf(" ");
				}else{
					break;
				}				
			}

		}
		hashtab[now]++;
		st.insert(now);
		printf("\n");
	}
	return 0;
}













