#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node{
	char name[20];
	char gender;
	char id[20];
	int grade;
}temp,high,low;
int N,cntf=0,cntm=0,hf=0,lm=100;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.id,&temp.grade);
		if(temp.gender=='F'){
			cntf++;
			if(temp.grade>hf){
				hf=temp.grade;
				high=temp;
			}
		}
		if(temp.gender=='M'){
			cntm++;
			if(temp.grade<lm){
				lm=temp.grade;
				low=temp;
			}
		}
	}
	if(cntf==0){
		printf("Absent\n");
	}else{
		printf("%s %s\n",high.name,high.id);
	}
	if(cntm==0){
		printf("Absent\n");
	}else{
		printf("%s %s\n",low.name,low.id);
	}
	if(cntf!=0&&cntm!=0){
		int dif=high.grade-low.grade;
		printf("%d",dif);
	}else{
		printf("NA");
	}
	return 0;
}

