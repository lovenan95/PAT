#include<stdio.h> 
#include<string.h> 
#include<algorithm>
using namespace std;
char a[15];
char read[10][8]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

void readq(char q[]){
	int lenq=strlen(q);
	if(lenq==4){
		printf("%s",read[q[0]-'0']);
		if(q[0]!='0')
			printf(" Qian");
		if(q[1]!='0'){
			printf(" %s",read[q[1]-'0']);
			printf(" Bai");
			if(q[2]!='0'){
				printf(" %s",read[q[2]-'0']);
				printf(" Shi");
				if(q[3]!='0'){
					printf(" %s",read[q[3]-'0']);
				}
			}else if(q[2]=='0'){
				if(q[3]!='0'){
					printf(" %s",read[q[2]-'0']);
					printf(" %s",read[q[3]-'0']);
				}			
			}
		}else if(q[1]=='0'){
			if(q[2]!='0'){
				printf(" %s",read[q[1]-'0']);
				printf(" %s",read[q[2]-'0']);
				printf(" Shi");
				if(q[3]!='0'){
					printf(" %s",read[q[3]-'0']);
				}
			}else if(q[2]=='0'){
					if(q[3]!='0'){
						printf(" %s",read[q[1]-'0']);
						printf(" %s",read[q[3]-'0']);
					}
				}	
		}
	}
	if(lenq==3){
		if(q[0]!='0'){
			printf("%s",read[q[0]-'0']);
			printf(" Bai");
		}
		if(q[1]!='0'){
			printf(" %s",read[q[1]-'0']);
			printf(" Shi");
			if(q[2]!='0'){
				printf(" %s",read[q[2]-'0']);
			}		
		}else if(q[1]=='0'){
			if(q[2]!='0'){
				printf(" %s",read[q[1]-'0']);
				printf(" %s",read[q[2]-'0']);
			}
		}
	}
	if(lenq==2){
		if(q[0]!='0'){
			printf("%s",read[q[0]-'0']);
			printf(" Shi");
			if(q[1]!='0'){
				printf(" %s",read[q[1]-'0']);
			}
		}
	}
	if(lenq==1){
		if(q[0]!='0'){
			printf("%s",read[q[0]-'0']);
		}
	}
}

int main(){
	scanf("%s",a);
	int len=strlen(a);
	int pos=0;
	char temp[4],temp2[4];
	for(int i=0;i<4;i++){
		temp[i]='\0';
		temp2[i]='\0';
	}
	if(a[0]=='-'){
		printf("Fu ");
		len--;
		pos++;
	}
	if(len==9){
		printf("%s ",read[a[pos]-'0']);
		printf("Yi ");
		pos++;
		for(int i=0;i<4;i++){
			temp[i]=a[pos++];
		}
		readq(temp);
		printf(" Wan ");
		for(int i=0;i<4;i++){
			temp2[i]=a[pos++];
		}
		readq(temp2);
	}
	if(len==8){
		for(int i=0;i<4;i++){
			temp[i]=a[pos++];
		}
		readq(temp);
		printf(" Wan ");
		for(int i=0;i<4;i++){
			temp2[i]=a[pos++];
		}
		readq(temp2);
	}
	if(len==7){
		for(int i=0;i<3;i++){
			temp[i]=a[pos++];
		}
		readq(temp);
		printf(" Wan ");
		for(int i=0;i<4;i++){
			temp2[i]=a[pos++];
		}
		readq(temp2);
	}
//	printf("len->6\n");
//	puts(temp);
	
	
	if(len==6){
		for(int i=0;i<2;i++){
			temp[i]=a[pos++];
		}
		readq(temp);
//		printf("len==6\n");
//		puts(temp);
		printf(" Wan ");
		for(int i=0;i<4;i++){
			temp2[i]=a[pos++];
		}
		readq(temp2);
	}
//	printf("len6->\n");	
//	puts(temp);
	
	if(len==5){
		for(int i=0;i<1;i++){
			temp[i]=a[pos++];
		}
		readq(temp);
		printf(" Wan ");
		for(int i=0;i<4;i++){
			temp2[i]=a[pos++];
		}
		readq(temp2);
	}
	if(len<=4){
		for(int i=0;i<4;i++){
			temp[i]=a[pos++];
		}
		readq(temp);
	}
	if(strcmp(a,"0")==0){
		printf("ling");
	}
	
	
	
	
	
	
	
	
	return 0;
}