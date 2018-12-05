#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<set>
#include<map>
using namespace std;

int n,m,s;

map<string,bool> mp;

int main(){
	string str[1010];
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++){
		cin>>str[i];
		mp[str[i]]=false;
	}
	if(s>n){
		printf("Keep going...\n");
	}	
	for(int i=s;i<=n;){

		if(mp[str[i]]==false){
			cout<<str[i]<<endl;
			mp[str[i]]=true;
			i+=m;
		}
		if(mp[str[i]]==true){
			i++;
		}	
		
	}
	return 0;
}










