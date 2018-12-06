#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

const int maxn=10010;
int N,K;
struct node{
	char id[10];
	int hh,mm,ss;
	int time;
	char status[5];
}all[maxn],valid[maxn];

map<string,int> parktime;

int timetoint(int h,int m,int s){
	return h*3600+m*60+s;
}

bool cmp1(node a,node b){
	if(strcmp(a.id,b.id)!=0)
		return strcmp(a.id,b.id)<0;
	else return a.time<b.time;
}

bool cmp2(node a,node b){
	return a.time<b.time;
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%s %d:%d:%d %s",all[i].id,&all[i].hh,&all[i].mm,&all[i].ss,all[i].status);
		all[i].time=timetoint(all[i].hh,all[i].mm,all[i].ss);
	}
	sort(all,all+N,cmp1);
	int maxtime=-1;
	int num=0;
	for(int i=1;i<N;i++){
		if(strcmp(all[i].id,all[i-1].id)==0&&strcmp(all[i].status,"out")==0&&strcmp(all[i-1].status,"in")==0){
			valid[num++]=all[i-1];
			valid[num++]=all[i];
			int stop=all[i].time-all[i-1].time;
			if(parktime.count(all[i].id)==0){
				parktime[all[i].id]=0;
			}
			parktime[all[i].id]+=stop;
			maxtime=max(maxtime,parktime[all[i].id]);             
		}
	}
	sort(valid,valid+num,cmp2);
	
//	for(int i=0;i<num;i++){
//		printf("******%s %d %s****\n",valid[i].id,valid[i].time,valid[i].status);
//	}
	
	int now=0,cnt=0;
	for(int i=0;i<K;i++){
		int hour,minute,second;
		scanf("%d:%d:%d",&hour,&minute,&second);
		int time=timetoint(hour,minute,second);
//		printf("****time=%d***\n",time);
		while(now<num&&valid[now].time<=time){
			if(strcmp(valid[now].status,"in")==0){
				cnt++;
			}else{
				cnt--;
			}
			now++;
		}
		printf("%d\n",cnt);
	}
	map<string,int>::iterator it;
	for(it=parktime.begin();it!=parktime.end();it++){
		if(it->second==maxtime){
//			printf("%s ",it->first.c_str());
			cout<<it->first<<" ";
		}
	}	
	printf("%02d:%02d:%02d\n",maxtime/3600,maxtime%3600/60,maxtime%60);
	return 0;
}