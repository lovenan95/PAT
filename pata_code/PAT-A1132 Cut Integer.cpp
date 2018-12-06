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

int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string str,str1,str2;
		cin>>str;
		int len=str.length();
		str1=str;
		str2=str;
		str2.erase(str2.begin(),str2.begin()+len/2);
		str1.erase(str1.begin()+len/2,str1.end());
		int a=0,b=0,z=0;
		for(int i=0;i<str1.length();i++){
			a=a*10+str1[i]-'0';
			b=b*10+str2[i]-'0';
		}
		for(int i=0;i<len;i++){
			z=z*10+str[i]-'0';
		}
		if(a==0||b==0){
			printf("No\n");
		}else{
			if(z%(a*b)==0){
				printf("Yes\n");
			}else{
				printf("No\n");
			}			
		}
		
		
		
	}
	
	
	
	
	
	
	
	
	return 0;
} 