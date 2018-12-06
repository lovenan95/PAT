#include<stdio.h> 
#include<iostream> 
#include<string> 
#include<string.h> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

int N;
map<string,int> sti;
map<int,string> its;

string mar1[15]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string mar2[15]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

void init(){
	for(int i=0;i<13;i++){
		sti[mar1[i]]=i;
		its[i]=mar1[i];
		sti[mar2[i]]=i*13;
		its[i*13]=mar2[i];
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			string str;
			str=mar2[i]+" "+mar1[j];
			sti[str]=i*13+j;
			its[i*13+j]=str;
		}
	}	
}
int main(){
	init();
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		string temp;
		getline(cin,temp);
		if(temp[0]>='0'&&temp[0]<='9'){
			int num=0;
			for(int i=0;i<temp.length();i++){
				num=num*10+temp[i]-'0';
			}
			string res=its[num];
			cout<<res<<"\n";
		}else{
			int ans=sti[temp];
			cout<<ans<<"\n";
		}
	}
	return 0;
}













