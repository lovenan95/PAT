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

int n;
int req[110]={0};
int main(){
	scanf("%d",&n);
	int elv=0;
	int cost=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&req[i]);
		
	}	
	for(int i=1;i<=n;i++){
		if(req[i]>req[i-1]){
			cost+=(req[i]-req[i-1])*6;
			cost+=5;
		}else if(req[i]<req[i-1]){
			cost+=(req[i-1]-req[i])*4;
			cost+=5;
		}else{
			cost+=5;
		}
	}
	printf("%d\n",cost);	
	
	
	
	
	
	return 0;
}








