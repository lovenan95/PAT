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
const int maxn=100010;
int n,m;
int hashtab[maxn];

set<int> party;
int main(){
	scanf("%d",&n);
	memset(hashtab,-1,sizeof(hashtab));
	for(int i=0;i<n;i++){
		int id1,id2;
		scanf("%d%d",&id1,&id2);
		hashtab[id1]=id2;
		hashtab[id2]=id1;
	}	
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int temp;
		scanf("%d",&temp);
		party.insert(temp);
		if(party.find(hashtab[temp])!=party.end()){
			party.erase(temp);
			party.erase(hashtab[temp]);
		}
	}
	printf("%d\n",party.size());
	int cnt=0;
	for(set<int>::iterator it=party.begin();it!=party.end();it++){
		printf("%05d",*it);
		cnt++;
		if(cnt<party.size()){
			printf(" ");
		}
	}
	return 0;
}









