#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;
const int maxn=(1<<23)+1;
int m,n;
map<int,int> ct;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int temp;
			scanf("%d",&temp);
			if(ct.find(temp)!=ct.end())
				ct[temp]++;
			else{
				ct[temp]=1;
			}
		}
	}
	int k=0,max=0;
	map<int,int>::iterator it=ct.begin();
	for(;it!=ct.end();it++){
		if(it->second>max){
			k=it->first;
			max=it->second;
		}
	}
	printf("%d",k);
	
	
	
	
	return 0;
}










