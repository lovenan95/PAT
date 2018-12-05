#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n;
string mar1[15]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string mar2[15]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

map<string,int> stn;

int main(){
	scanf("%d%*c",&n);
	string temp;
	for(int i=1;i<13;i++){
		stn[mar1[i]]=i;
		stn[mar2[i]]=i*13;
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			stn[mar1[i]]=i;
			stn[mar2[i]]=i*13;
			string str;
			str=mar2[i]+" "+mar1[j];
			stn[str]=i*13+j;			
		}

	}
	for(int i=0;i<n;i++){
		getline(cin,temp);
		int a=0;
		int len=temp.length();
		if(temp[0]>='0'&&temp[0]<='9'){
			for(int k=0;k<len;k++){
				a=(temp[k]-'0')+a*10;
			}
			string str;
			int sw,gw;
			sw=a/13;
			gw=a%13;
			if(sw==0&&gw!=0){
				str=mar1[gw];
			}else if(gw==0&&sw!=0){
				str=mar2[sw];
			}else if(sw==0&&gw==0){
				str="tret";
			}else{
				str=mar2[sw]+" "+mar1[gw];		
			}
			cout<<str<<"\n";	
		}else{
			int value;
			cout<<stn[temp]<<"\n";
//			w1=temp;
//			w2=temp;
//			for(int i=0;i<3;i++){
//				w1[i]=temp[i];
//				w2[i]=temp[i+4];
//			}
//			w2.erase(w2.begin(),w2.begin()+4); 
//			w1.erase(w1.end()-4,w1.end());
//			cout<<"\n"<<w1<<"\n";
//			cout<<w2;
//			value=stn[w1]+stn[w2];
//			printf("%d",value);	
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}