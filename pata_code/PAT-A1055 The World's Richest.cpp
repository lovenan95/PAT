#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<algorithm>
using namespace std;

int N,K,M,amin,amax;
bool flag=false;
struct node{
	char name[10];
	int age;
	int worth;
}temp;
vector<node> pep;

bool cmp(node a,node b){
	if(a.worth!=b.worth)
		return a.worth>b.worth;
	else if(a.age!=b.age)
		return a.age<b.age;
	else 
		return strcmp(a.name,b.name)<0;
}

int main(){
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%s %d %d",temp.name,&temp.age,&temp.worth);
		pep.push_back(temp);
	}
	sort(pep.begin(),pep.end(),cmp);
//	for(int k=0;k<N;k++){
//		printf("******%s %d %d******\n",pep[k].name,pep[k].age,pep[k].worth);
//	}
	for(int i=1;i<=K;i++){
		scanf("%d %d %d",&M,&amin,&amax);
		flag=false;
		printf("Case #%d:\n",i);
//		sort(pep.begin(),pep.end(),cmp);
		for(int k=0;k<N;k++){
			if(pep[k].age>=amin&&pep[k].age<=amax){
				printf("%s %d %d\n",pep[k].name,pep[k].age,pep[k].worth);
				M--;
				flag=true;
			}
			if(M==0){
				break;       
			}
		}
		if(flag==false){
			printf("None\n"); 
		}
	}	
	
	
	
	return 0; 
}