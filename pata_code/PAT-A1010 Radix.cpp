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

int tag,r;

long long change10(string str,int r){
	long long ans=0;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9'){
			ans=ans*r+str[i]-'0';
		}else{
			ans=ans*r+str[i]-'a'+10;
		}
	}
	return ans;
}

long long change(char c){
	long long ans=0;
	if(c>='0'&&c<='9'){
		ans=c-'0';
	}else{
		ans=c-'a'+10;
	}
	return ans;
}

int main(){
	string str1,str2;
	cin>>str1>>str2;
	scanf("%d%d",&tag,&r);	
	if(tag==2){
		string temp=str1;
		str1=str2;
		str2=temp;
	}
	long long n1,n2;
	n1=change10(str1,r);
//	cout<<n1<<endl;
	int minr=10000;
	for(int i=0;i<str2.length();i++){
		if(change(str2[i])<minr){
			minr=change(str2[i]);
		}
	}
	long long radix;
	for(radix=minr;radix<=n1+1;radix++){
		n2=change10(str2,radix);
		if(n2==n1){
			printf("%d\n",radix);
			break;
		}
	}
	if(radix>n1){
		printf("Impossible\n");
	}
	return 0;
}









