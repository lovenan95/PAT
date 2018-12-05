#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<algorithm>
using namespace std;

struct node{
	char id[10];
	int de;
	int cai;
	int sum;
}temp;
int N,L,H;

//vector<node> stu;
vector<node> sage;
vector<node> nobel;
vector<node> fool;
vector<node> small;

bool cmp1(node a,node b){
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else if(a.de!=b.de)
		return a.de>b.de;
	else 
		return strcmp(a.id,b.id)<0;
}

int main(){
	scanf("%d %d %d",&N,&L,&H);
	int cnt=0;
	for(int i=0;i<N;i++){
		scanf("%s %d %d",temp.id,&temp.de,&temp.cai);
		temp.sum=temp.de+temp.cai;
		if(temp.de>=H&&temp.cai>=H){
			sage.push_back(temp);
//			printf("**%s %d %d\n",sage[n].id,sage[n].de,sage[n].cai);
			cnt++;
		}
		else if(temp.de>=H&&temp.cai<H&&temp.cai>=L){
			nobel.push_back(temp);
//			printf("**%s %d %d\n",sage[n].id,sage[n].de,sage[n].cai);
			cnt++;
		}
		else if(temp.de<H&&temp.de>=temp.cai&&temp.de>=L&&temp.cai>=L){
			fool.push_back(temp);
//			printf("**%s %d %d\n",sage[n].id,sage[n].de,sage[n].cai);
			cnt++;
		}
		else if(temp.de>=L&&temp.cai>=L){
			small.push_back(temp);
			cnt++;
		}
		
	}
	printf("%d\n",cnt);
	sort(small.begin(),small.end(),cmp1);
	sort(fool.begin(),fool.end(),cmp1);
	sort(nobel.begin(),nobel.end(),cmp1);
	sort(sage.begin(),sage.end(),cmp1);
	for(int i=0;i<sage.size();i++){
		printf("%s %d %d\n",sage[i].id,sage[i].de,sage[i].cai);
	}
	for(int i=0;i<nobel.size();i++){
		printf("%s %d %d\n",nobel[i].id,nobel[i].de,nobel[i].cai);
	}	
	for(int i=0;i<fool.size();i++){
		printf("%s %d %d\n",fool[i].id,fool[i].de,fool[i].cai);
	}
	for(int i=0;i<small.size();i++){
		printf("%s %d %d\n",small[i].id,small[i].de,small[i].cai);
	}	
	
	
	
	
	
	
	
	
	return 0;
} 