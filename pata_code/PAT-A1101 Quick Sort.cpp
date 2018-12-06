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
const int maxn=100010;
int n;

int main(){
	int a[maxn],left[maxn],right[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}	
	left[0]=-1;
	for(int i=1;i<n;i++){
		left[i]=max(a[i-1],left[i-1]);
	}	
	right[n-1]=1000000001;
	for(int i=n-2;i>=0;i--){
		right[i]=min(a[i+1],right[i+1]);
	}
	vector<int> ans;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]>left[i]&&a[i]<right[i]){
			cnt++;
			ans.push_back(a[i]);
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i<ans.size()-1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	if(cnt==0){
		printf("\n");
	}
	return 0;
}








