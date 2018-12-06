#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<algorithm>
using namespace std;
const int INF=1000000000;
double cmax,D,davg;
int N;

struct node{
	double pi;
	double dis;
}sta[510];
bool cmp(node a,node b){
	if(a.dis!=b.dis)
		return a.dis<b.dis;
	else
		return a.pi<b.pi;
}
int main(){
	scanf("%lf%lf%lf%d",&cmax,&D,&davg,&N);
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&sta[i].pi,&sta[i].dis);
	}
	sta[N].pi=0;
	sta[N].dis=D;
	sort(sta,sta+N,cmp);
//	for(int i=0;i<N;i++){
//		printf("******%0.2lf %0.0lf\n",sta[i].pi,sta[i].dis);
//	}	
	int now=0,next;
	double full=cmax*davg;
	double maxd,cost=0,carry=0;
	if(sta[0].dis!=0){
		printf("The maximum travel distance = 0.00");
	}else{
		while(now<N){
//			printf("%.0lf\n",sta[now].dis);
			int k=-1;
			double price=INF;
			for(next=now+1;next<=N&&sta[next].dis-sta[now].dis<=full;next++){
				if(sta[next].pi<price){
					price=sta[next].pi;
					k=next;
					if(price<sta[now].pi){
						break;
					}
				}
			}
			if(k==-1) break;
			double need=(sta[k].dis-sta[now].dis)/davg;		
			if(price<sta[now].pi){
				if(carry<need){
					cost+=(need-carry)*sta[now].pi;
					carry=0;
				}else{
					carry=carry-need;
				}
			}else{
				cost+=(cmax-carry)*sta[now].pi;
				carry=cmax-need;
			}
			now=k;
		}
//		printf("now=%d\n",now);
		if(now==N){
			printf("%.2lf",cost);
		}else{
			printf("The maximum travel distance = %.2lf",sta[now].dis+full);
		}
					
	}
	return 0;
}