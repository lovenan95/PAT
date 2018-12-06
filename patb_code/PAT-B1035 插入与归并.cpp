#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n,org[110],tp[110],gb[110];

bool issame(int a[],int b[]){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])
			return false;
	}
	return true;
}

void show(int a[]){
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
		if(i<n-1){
			printf(" ");
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&org[i]);
		gb[i]=org[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&tp[i]);
	}	
	bool flag,merge=true;
	for(int i=1;i<n;i++){
		int temp=org[i];
		int j=i;
		while(j>0&&temp<org[j-1]){
			org[j]=org[j-1];
			j--;
		}		
		org[j]=temp;
		flag=issame(org,tp);
		if(flag==true){
			merge=false;
			printf("Insertion Sort\n");
			i++;
			temp=org[i];
			j=i;
			while(j>0&&temp<org[j-1]){
				org[j]=org[j-1];
				j--;
			}		
			org[j]=temp;
			show(org);
			break;
		}
		
	}
	if(merge==true){
		for(int step=2;step/2<=n;step*=2){
			for(int i=0;i<n;i+=step){
				sort(gb+i,gb+min(i+step,n));
			}
			if(issame(gb,tp)==true){
				printf("Merge Sort\n");
				step*=2;
				for(int i=0;i<n;i+=step){
					sort(gb+i,gb+min(i+step,n));					
				}
				show(gb);
			}			
			
		}
		
		
		
		
		
	}	
	
	
	
	
	
	return 0;
}
