#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

int n,k=0;
int a[100010],res[100010];
int lfmax[100010]={0};
int rtmin[100010];
bool flag=true;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		lfmax[i]=max(lfmax[i-1],a[i-1]);
	}
	rtmin[n-1]=0x3fffffff;
	for(int i=n-2;i>=0;i--){
		rtmin[i]=min(rtmin[i+1],a[i+1]);
	}
	for(int i=0;i<n;i++){
		flag=true;
		int temp=a[i];
		if(temp<lfmax[i]||temp>rtmin[i]){
			flag=false;
		}
		if(flag==true){
			res[k]=a[i];
			k++;
		}		
	}
	sort(res,res+k);
	printf("%d\n",k);
	for(int i=0;i<k;i++){
		printf("%d",res[i]);
		if(i<k-1){
			printf(" ");
		}
	}
	printf("\n");
	
	
	
	
	return 0;
}