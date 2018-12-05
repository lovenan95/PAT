#include<stdio.h>
#include<string.h>
int N,M=0;
struct node{
	char name[20];
	char password[20];
	bool flag;
};
node stu[1010];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %s",stu[i].name,stu[i].password);
		stu[i].flag=false;
		for(int k=0;k<strlen(stu[i].password);k++){
			if(stu[i].password[k]=='l'){
				stu[i].password[k]='L';
				stu[i].flag=true;
			}else if(stu[i].password[k]=='1'){
				stu[i].password[k]='@';
				stu[i].flag=true;
			}else if(stu[i].password[k]=='0'){
				stu[i].password[k]='%';
				stu[i].flag=true;
			}else if(stu[i].password[k]=='O'){
				stu[i].password[k]='o';
				stu[i].flag=true;
			}
		}
		if(stu[i].flag==true){
			M++;
		}
	}
	if(M!=0){
		printf("%d\n",M);
		for(int j=0;j<N;j++){
		if(stu[j].flag==true)
			printf("%s %s\n",stu[j].name,stu[j].password);	
		}
	}else if(M==0&&N>1){
		printf("There are %d accounts and no account is modified",N);
	}else if(M==0&&N==1){
		printf("There is 1 account and no account is modified");
	}
	
	
	
	return 0;
}


