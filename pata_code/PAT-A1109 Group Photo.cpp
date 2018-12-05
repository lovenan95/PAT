#include<iostream> 
#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<string> 
#include<vector> 
#include<algorithm>
using namespace std;

int n,k;
int cen;
struct node{
	int height;
	char name[15];
}stu[10010];

vector<int> gp;

bool cmp2(node a,node b){
	if(a.height!=b.height)
		return a.height>b.height;
	else if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
}

bool cmp1(node a,node b){
	if(a.height!=b.height)
		return a.height<b.height;
	else if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)>0;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d",stu[i].name,&stu[i].height);
	}
	int col=n/k;
	int last=n-col*(k-1);
	sort(stu,stu+n,cmp2);
	int i=0;
	for(;i<last;i++){
		if(i%2==0){
			gp.push_back(i);			
		}else{
			gp.insert(gp.begin(),i);
		}
	}
	for(int j=0;j<last;j++){
		printf("%s",stu[gp[j]].name);
		if(j<last-1){
			printf(" ");
		}
	}	
	gp.clear();
	printf("\n");
	for(int m=2;m<=k;m++){
		for(int p=0;p<col;p++){
			if(p%2==0){
				gp.push_back(i);
				i++;			
			}else{
				gp.insert(gp.begin(),i);
				i++;
			}			
		}
		for(int j=0;j<col;j++){
			printf("%s",stu[gp[j]].name);
			if(j<col-1){
				printf(" ");
			}
		}	
		gp.clear();
		printf("\n");		
	}
	
//	for(int i=0;i<=last/2;i++){
//		printf("%s ",stu[i].name);
//	}
//	for(int i=last-1;i>last/2;i--){
//		printf("%s",stu[i].name);
//		if(i>last/2+1){
//			printf(" ");
//		}else{
//			printf("\n");
//		}
//	}
	
	
	
	
	
	return 0;
} 