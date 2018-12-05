#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<set>
#include<map>
using namespace std;

int n;
int rate[24];
struct node{
	string name;
	int month,day,hour,minute;
	string rec;
	double total;
}temp;
vector<node> call;

bool cmp(node a,node b){
	if(a.name!=b.name){
		return a.name<b.name;
	}else if(a.month!=b.month){
		return a.month<b.month;
	}else if(a.day!=b.day){
		return a.day<b.day;
	}else if(a.hour!=b.hour){
		return a.hour<b.hour;
	}else{
		return a.minute<b.minute;
	}
}

int cal(int d1,int h1,int m1,int d2,int h2,int m2){
	int toll=0;
	while(d1<d2||h1<h2||m1<m2){
		toll=toll+rate[h1];
		m1++;
		if(m1==60){
			h1++;
			m1=0;
		}
		if(h1==24){
			d1++;
			h1=0;
		}
	}
	return toll;
}

map<string,int> mp;

int main(){
	for(int i=0;i<24;i++){
		scanf("%d",&rate[i]);
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>temp.name;
		mp[temp.name]=1;
		scanf("%d:%d:%d:%d",&temp.month,&temp.day,&temp.hour,&temp.minute);
		cin>>temp.rec;
		call.push_back(temp);
	}
	sort(call.begin(),call.end(),cmp);	
//	for(int i=0;i<n;i++){
//		cout<<call[i].name;
//		printf(" %02d:%02d:%02d:%02d ",call[i].month,call[i].day,call[i].hour,call[i].minute);
//		cout<<call[i].rec<<endl;
//	}
	node end;
	end.name="lksjdf;ladsjfklasdjf;jwioeriqoeuorpu2a";
	call.push_back(end);
	int now=0,next=1;
	bool isprint=false;
	double sum=0;
	for(int i=0;i<n;i++){
		now=i;
		next=now+1;
		if(call[now].name==call[next].name&&call[now].rec=="on-line"&&call[next].rec=="off-line"){
			if(isprint==false){
				cout<<call[now].name;
				printf(" %02d\n",call[now].month);
				isprint=true;
			}
			printf("%02d:%02d:%02d ",call[now].day,call[now].hour,call[now].minute);
			printf("%02d:%02d:%02d ",call[next].day,call[next].hour,call[next].minute);
			int amt=cal(call[now].day,call[now].hour,call[now].minute,call[next].day,call[next].hour,call[next].minute);
			double ad=1.0*amt/100;
			int tt=(call[next].day-call[now].day)*24*60+(call[next].hour-call[now].hour)*60+(call[next].minute-call[now].minute);
			printf("%d $%0.2f\n",tt,ad);
			sum+=ad;
		}
		if(call[now].name!=call[next].name&&isprint==true){
			isprint=false;
			printf("Total amount: $%0.2f\n",sum);
			sum=0;
		}


	}
	return 0;
} 








