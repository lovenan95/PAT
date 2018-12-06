#include<stdio.h>
#include<string.h>
#include<math.h>

char in[20010];
char sign1,sign2;
int expon=0;
int pose,pos2;


int main(){
	gets(in);
	int len=strlen(in);
	sign1=in[0];
	pose=1;
	while(in[pose]!='E'){
		pose++;
	}
//	printf("%d\n",pose);
	pos2=pose+1;
	for(int k=pos2+1;k<len;k++){
		expon=expon*10+in[k]-'0';
	}
//	printf("%d\n",expon);
	if(in[pos2]=='-'){
		if(in[0]=='-'){
			printf("-");
		}
		printf("0.");
		expon--;
		while(expon>0){
			printf("0");
			expon--;
		}
		printf("%c",in[1]);
		for(int k=3;k<pose;k++){
			printf("%c",in[k]);
		}
	}else if(in[pos2]=='+'){
		if(in[0]=='-'){
			printf("-");
		}
		printf("%c",in[1]);
		for(int k=3;k<pose;k++){
			if(expon==0){
				printf(".");
			}
			printf("%c",in[k]);
			expon--;
//			printf("---%d----",expon);
		}
//		printf("---%d----",expon);
//		if(expon==0){
//			printf(".");
//		}
		while(expon>0){
			printf("0");
			expon--;
		}				
		
		
	}
	
	
	
	
	return 0;
}