#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
#include<math.h> 
#include<algorithm>
using namespace std;

char str[10010];
int k;

struct bign{
	int num[10010];
	int len;
	bign(){
		memset(num,0,sizeof(num));
		len=0;
	}
};

bign change(char str[]){
	bign a;
	a.len=strlen(str);
	int j=0;
	for(int i=a.len-1;i>=0;i--){
		a.num[j]=str[i]-'0';
		j++;
	}
	return a;
} 

bool judge(bign a){
	int len=a.len;
	int i=0,j=len-1;
	while(i<j){
		if(a.num[i]!=a.num[j]){
			return false;
		}

		i++;
		j--;
	}
	return true;
}

bign add(bign a,bign b){
	bign s;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		int sum=a.num[i]+b.num[i]+carry;
		carry=sum/10;
		s.num[s.len++]=sum%10;
	}
	if(carry!=0){
		s.num[s.len++]=carry;
	}
	return s;
}

int main(){
	scanf("%s",str);
	scanf("%d",&k);
	bign a,b;
	a=change(str);
	int step=0;
	if(judge(a)==true){
		for(int i=a.len-1;i>=0;i--){
			printf("%d",a.num[i]);
		}
		printf("\n%d",step);
	}else{
		while(step<k){
			b=a;
			reverse(b.num,b.num+b.len);
			a=add(a,b);	
			step++;	
			if(judge(a)==true){
				break;
			}
		} 
		for(int i=a.len-1;i>=0;i--){
			printf("%d",a.num[i]);
		}
		printf("\n%d",step);		
	}
	return 0;
} 