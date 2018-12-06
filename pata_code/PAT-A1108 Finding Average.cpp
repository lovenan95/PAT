#include<iostream> 
#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<string> 
#include<vector> 
#include<algorithm>
using namespace std;

int n;
bool sign=true; 
int dot=-1;
bool judge1(string str){
	if(str[0]=='-'&&str.length()==1){
			return false;
	}
	int i=0;
	if(str[0]='-'){
		i++;
	}
	for(;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9'){
			continue;
		}else if(str[i]=='.'&&dot==-1){
			dot=i;
			continue;
		}else{
			return false;
		}
	}
	return true;
}


int main(){
	scanf("%d",&n);
	int cnt=0;
	double ans=0;
	for(int i=0;i<n;i++){
		dot=-1;
		sign=true;
		string str;
		cin>>str;
		if(judge1(str)==false){
			printf("ERROR: %s is not a legal number\n",str.c_str());
		}else{
			double value=0;
			double value1=0;
			double value2=0;
			int j=0;
			bool dflag=false;
			if(str[0]=='-'){
				sign=false;
				j++;
			}else if(str[0]=='+'){
				j++;
			}			
			int len=str.length();
			for(;j<len;j++){
				if(str[j]=='.'){
					j++;
					dflag=true;
					break;
				}
				value1=value1*10+str[j]-'0';			
	
			}
//			printf("v1=%0.2f\n",value1);
			if(dflag==true){
				for(int k=len-1;k>=j;k--){
					value2=value2/10.0+str[k]-'0';
				}
			}
			value2/=10;
//			printf("v2=%0.2f\n",value2);
			value=value1+value2;
			if(sign==false){
				value=-value;
			}		
//			printf("****%0.2f\n",value);
			if(dot+3<=len-1&&dot!=-1){
				printf("ERROR: %s is not a legal number\n",str.c_str());
			}else if(value>1000||value<-1000){
				printf("ERROR: %s is not a legal number\n",str.c_str());
			}else{
				ans+=value;
				cnt++;
			}
		}
	}
	if(cnt==0){
		printf("The average of 0 numbers is Undefined");
	}else if(cnt==1){
		printf("The average of 1 number is %0.2f",ans);
	}else{
		double avg=ans/(1.0*cnt);
		printf("The average of %d numbers is %0.2f",cnt,avg);
	}
	
	
	
	
	
	return 0;
} 