#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<stack> 
#include<string.h> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

map<string,int> mp;

bool check(char c){
	if(c>='A'&&c<='Z')
		return true;
	else if(c>='a'&&c<='z')
		return true;
	else if(c>='0'&&c<='9')
		return true;
	else
		return false;
}

int main(){
	string str;
	getline(cin,str);
	int len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			str[i]=str[i]-'A'+'a';
		}
	}	
	string temp;
	int i=0;
	while(i<len){
		while(check(str[i])==false){
			i++;
		}
		temp=str[i];
		i++;
		while(check(str[i])==true){
			temp+=str[i];
			i++;
		}
		if(mp.find(temp)==mp.end()){
			mp[temp]=1;
		}else{
			mp[temp]++;			
		}
		temp.clear();
	}
	string sp;
	int maxsp=0;
	map<string,int>::iterator it=mp.begin();
	for(;it!=mp.end();it++){
		if(it->second>maxsp){
			maxsp=it->second;
			sp=it->first;
		}
	}
	cout<<sp<<" "<<maxsp<<endl;
	
	
	
	return 0;
}









