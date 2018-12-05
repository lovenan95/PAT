#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<stdlib.h>
#include<vector> 
#include<map> 
#include<stack> 
#include<queue> 
#include<algorithm>
using namespace std;

int n; 
vector<int> org;
vector<int> res;
vector<int> temp;

void downadjust(int low,int high){
	int i=low,j=2*i;
	while(j<=high){
		if(j+1<=high&&temp[j+1]>temp[j]){
			j=j+1;
		}
		if(temp[j]>temp[i]){
			swap(temp[j],temp[i]);
			i=j;
			j=i*2;
		}else{
			break;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		org.push_back(t);
	}	
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		res.push_back(t);
	}	
	bool flag=false;
	temp=org;
	for(int i=0;i<n;i++){
		sort(temp.begin(),temp.begin()+i);
		if(temp==res){
			if(flag==false)
				printf("Insertion Sort\n");
			flag=true;
			sort(temp.begin(),temp.begin()+i+1);
			if(org!=temp)
				for(int j=0;j<n;j++){
					printf("%d",temp[j]);
					if(j<n-1){
						printf(" ");
					}else{
						printf("\n");
					}
				}
		}
	}
	if(flag==false){
		printf("Heap Sort\n");
		temp=org;
		temp.insert(temp.begin(),-1); 
		res.insert(res.begin(),-1); 
		for(int i=n/2;i>=1;i--){
			downadjust(i,n);
		}
		for(int i=n;i>1;i--){
			swap(temp[1],temp[i]);
			downadjust(1,i-1);
			if(temp==res){
				swap(temp[1],temp[i-1]);
				downadjust(1,i-2);
				for(int j=1;j<=n;j++){
					printf("%d",temp[j]);
					if(j<n){
						printf(" ");
					}else{
						printf("\n");
					}					
				}
				break;
			}
		}
	}
	
	
	
	
	return 0;
}
 










