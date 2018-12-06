#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<stdlib.h>
#include<vector> 
#include<map> 
#include<stack> 
#include<algorithm>
using namespace std;

int n;
stack<int> st;
vector<int> temp;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string str;
		int num;
		cin>>str;
		if(str=="Pop"){
			if(!st.empty()){
				int top=st.top();
				printf("%d\n",top);
				st.pop();
				for(int i=0;i<temp.size();i++){
					if(temp[i]==top){
						temp.erase(temp.begin()+i);
						break;
					}
				}
			}else{
				printf("Invalid\n");				
			}
		}else if(str=="Push"){
			scanf("%d",&num);
			st.push(num);
			temp.push_back(num);
		}else{
			if(temp.size()!=0){
				sort(temp.begin(),temp.end());
				int med=temp.size();
				if(med%2==0){
					printf("%d\n",temp[med/2-1]);
				}else{
					printf("%d\n",temp[(med+1)/2-1]);
				}				
			}else{
				printf("Invalid\n");			
			}

		}
		
		
		
	}	
	
	
	
	
	return 0;
} 










