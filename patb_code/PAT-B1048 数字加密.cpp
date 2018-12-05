#include<stdio.h>
#include<string.h>

char str1[110],str2[110];
char res[15]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int r[110]={0};

int main(){
	scanf("%s %s",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	int i=len1-1,j=len2-1,k=1;
	for(;i>=0&&j>=0;i--,j--){
		if(k%2==1){
			r[k]=(str1[i]-'0'+str2[j]-'0')%13;
			k++;
			continue;
		}else if(k%2==0){
			r[k]=str2[j]-str1[i];
			if(r[k]<0){
				r[k]+=10;
			}
			k++;
			continue;
		}
	}
	if(i==-1){
		while(j>=0){
			r[k]=str2[j]-'0';
			j--;
			k++;
		}
	}else if(j==-1){
		while(i>=0){
			if(k%2==0){
				r[k]='0'-str1[i];
				if(r[k]<0){
					r[k]+=10;
				}	
				i--;
				k++;
			}else if(k%2==1){
				r[k]=str1[i]-'0';
				i--;
				k++;	
			}
		}
	}	
	k--;
	for(;k>=1;k--){
		printf("%c",res[r[k]]);
	}
	
	
	
	
	
	
	return 0;
}

