#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int N;
struct node{
	char name[10];
	int year,month,day;
};
bool cmp1(node a,node b){
	if(a.year==b.year){
		if(a.month==b.month){
			return a.day>=b.day;
		}else{
			return a.month>=b.month;
		}
	}else{
		return a.year>=b.year;
	}
}
bool cmp2(node a,node b){
	if(a.year==b.year){
		if(a.month==b.month){
			return a.day<=b.day;
		}else{
			return a.month<=b.month;
		}
	}else{
		return a.year<=b.year;
	}
}

//bool cmp1(node a,node b){
//	if(a.year!=b.year){
//		return a.year>=b.year;
//	}else if(a.month!=b.month){
//		return a.month>=b.month;
//	}else return a.day>=b.day;
//}
//bool cmp2(node a,node b){
//	if(a.year!=b.year){
//		return a.year<=b.year;
//	}else if(a.month!=b.month){
//		return a.month<=b.month;
//	}else return a.day<=b.day;
//}



vector<node> p;	
int main(){
	int cnt=0;
	node max,min,left,right;
	max.year=right.year=2014,max.month=right.month=9,max.day=right.day=6;
	left.year=min.year=1814,left.month=min.month=9,left.day=min.day=6;
	node temp;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %d/%d/%d",temp.name,&temp.year,&temp.month,&temp.day);
//		p.push_back(temp);
		if(cmp1(temp,left)&&cmp2(temp,right)){
			cnt++;
			if(cmp2(temp,max)){
				max=temp;
//				printf("------%d %s %s\n",cnt,max.name,min.name);
			}
			if(cmp1(temp,min)){
				min=temp;	
//				printf("+++++++%d %s %s\n",cnt,max.name,min.name);
			}
		}
	}

//	for(int i=0;i<p.size();i++){
//		int judgey=2014-p[i].year;
//		int judgem=9-p[i].month;
//		int judged=6-p[i].day;
//		if(0<judgey<200||(judgey==200&&judgem<0)||(judgey==200&&judgem==0&&judged<=0)||(judgey==0&&judgem<0)||(judgey==0&&judgem==0&&judged<=0)){
		
//		if(cmp1(p[i],left)&&cmp2(p[i],right)){
//			cnt++;
//			if(cmp1(p[i],max)){
//				max=p[i];
//			}
//			if(cmp2(p[i],min)){
//				min=p[i];
//			}
//		}
//	}
	
	if(cnt==0){
		printf("0\n");
	}else{
		printf("%d %s %s",cnt,max.name,min.name);
	}
	
	return 0;
}