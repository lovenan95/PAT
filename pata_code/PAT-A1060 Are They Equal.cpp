#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n;
string a,b;

int main(){
	scanf("%d",&n);
	cin>>a>>b;
	int k1=0;
	while(a[0]=='0'&&a.length()>0){
		a.erase(a.begin());
	}
	if(a[0]=='.'){
		a.erase(a.begin());
		while(a[0]=='0'&&a.length()>0){
			a.erase(a.begin());
			k1--;
		}
		if(a.length()==0){
			k1=0;
		}
	}else{
		for(int i=0;i<a.length();i++){
			if(a[i]=='.'){
				a.erase(a.begin()+i);
				break;
			}else{
				k1++;
			}
		}
	}
	if(a.length()>=n)	
		a.erase(a.begin()+n,a.end());
	else{
		while(a.length()<n){
			a+='0';
		}
	}
		
	
	int k2=0;
	while(b[0]=='0'&&b.length()>0){
		b.erase(b.begin());
	}
	if(b[0]=='.'){
		b.erase(b.begin());
		while(b[0]=='0'&&b.length()>0){
			b.erase(b.begin());
			k2--;
		}
		if(b.length()==0){
			k2=0;
		}		
	}else{
		for(int i=0;i<b.length();i++){
			if(b[i]=='.'){
				b.erase(b.begin()+i);
				break;
			}else{
				k2++;
			}
		}
	}	
	if(b.length()>=n)	
		b.erase(b.begin()+n,b.end());
	else{
		while(b.length()<n){
			b+='0';
		}
	}	
	
	if(a==b&&k1==k2){
		printf("YES ");
		cout<<"0."<<a<<"*10^"<<k1;
	}else{
		printf("NO ");
		cout<<"0."<<a<<"*10^"<<k1<<" ";		
		cout<<"0."<<b<<"*10^"<<k2;		
	}
	return 0;
} 