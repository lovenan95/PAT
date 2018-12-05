#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n;
string str[100010];

bool cmp(string str1,string str2){
	return str1+str2<str2+str1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	sort(str,str+n,cmp);
	string res;
	for(int i=0;i<n;i++){
		res+=str[i];
	}
	string::iterator it=res.begin();
	while(*it=='0'){
		res.erase(it);
	}
	if(res.size()==0){
		cout<<'0'<<endl;
		return 0;
	}
	cout<<res;
	

	
	
}