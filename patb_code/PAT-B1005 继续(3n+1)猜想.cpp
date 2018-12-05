#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;
const int maxn=1010;
int N;
int a[maxn];
int res[maxn];
int hashtab[10000]={0};
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		int temp=a[i];
		while(temp!=1&&hashtab[temp]<=2){
			if(temp%2==0){
				temp/=2;
				hashtab[temp]++;
			}else{
				temp=(3*temp+1)/2;
				hashtab[temp]++;		
			}
		}
		hashtab[a[i]]++;
	}
	int k=0;
	for(int i=0;i<N;i++){
		if(hashtab[a[i]]==1){
			res[k]=a[i];
			k++;
		}
	}
	sort(res,res+k);
	k--;
	for(;k>=0;k--){
		printf("%d",res[k]);
		if(k>0){
			printf(" ");
		}
	}
	
	return 0;
}