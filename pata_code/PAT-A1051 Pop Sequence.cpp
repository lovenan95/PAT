#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<stack> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

int M,N,K;
int a[1010];
stack<int> st;

int main(){
	scanf("%d%d%d",&M,&N,&K);	
	for(int j=0;j<K;j++){
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
		}
		while(!st.empty()){
			st.pop();
		}

		int k=1,s=1;
		bool flag=true;
		for(s=1;s<=N;s++){
			st.push(s);
			if(st.size()>M){
				flag=false;
				break;
			}
			while(st.top()==a[k]&&st.empty()==false){
//				cout<<st.top()<<'\n';
				st.pop();
				k++;
			}			
		}
		if(flag==true&&st.empty()==true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}