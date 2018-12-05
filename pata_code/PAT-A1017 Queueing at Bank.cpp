#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<stdlib.h>
#include<vector> 
#include<map> 
#include<stack> 
#include<algorithm>
using namespace std;

const int K=111;
const int INF=1000000000;
struct node{
	int cmt,svt;
}peo;

vector<node> custom;

int edtime[K];
int c,w,tot;

int convert(int h,int m,int s){
	return h*3600+m*60+s;
}

bool cmp(node a,node b){
	return a.cmt<b.cmt;
}

int main(){
	scanf("%d%d",&c,&w);
	int st=convert(8,0,0);
	int ed=convert(17,0,0);
	for(int i=0;i<c;i++){
		int hh,mm,ss,sv;
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&sv);
		int cometime=convert(hh,mm,ss);
		if(cometime>ed){
			continue;
		}
		peo.cmt=cometime;
		if(sv<60){
			peo.svt=sv*60;	
		}else{
			peo.svt=3600;
		}
		custom.push_back(peo);		
	}

	sort(custom.begin(),custom.end(),cmp);
	for(int i=0;i<w;i++){
		edtime[i]=st;
	}
	for(int i=0;i<custom.size();i++){
		int idx=-1,min=INF;
		for(int j=0;j<w;j++){
			if(min>edtime[j]){
				min=edtime[j];
				idx=j;
			}
		}
		if(edtime[idx]<=custom[i].cmt){
			edtime[idx]=custom[i].svt+custom[i].cmt;
		}else{
			tot=tot+edtime[idx]-custom[i].cmt;
			edtime[idx]+=custom[i].svt;
		}
	}
	double avg=tot/60.0/custom.size();
	printf("%.1f\n",avg);
	
	
	
	
	
	return 0;
}
















 