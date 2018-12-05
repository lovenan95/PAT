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
using namespace std;

struct bign{
	int data[1010];
	int len;
	bign(){
		len=0;
	}
};

bool judge(bign a){
	int i=0,j=a.len-1;
	while(i<j){
		if(a.data[i]!=a.data[j]){
			return false;
		}
		i++;
		j--;
	}	
	return true;
}

bign change(char a[]){
	bign p;
	p.len=strlen(a);
	int j=0; 
	for(int i=p.len-1;i>=0;i--){
		p.data[j]=a[i]-'0';
		j++;
	}
	return p;
}

bign add(bign a,bign b){
	int carry=0;
	bign c;
	c.len=a.len;
	for(int i=0;i<a.len;i++){
		c.data[i]=(carry+a.data[i]+b.data[i])%10;
		carry=(carry+a.data[i]+b.data[i])/10;
	}
	if(carry!=0){
		c.data[c.len++]=carry;
	}
	return c;
}

int main(){
	char s[1010];
	gets(s);
	bign a,b,c;
	a=change(s);
	if(judge(a)==true){
		for(int i=a.len-1;i>=0;i--){
			printf("%d",a.data[i]);
		}
		printf(" is a palindromic number.\n");
		return 0;
	}
	int cnt=0;
	while(cnt<10){
		b=a;
		reverse(b.data,b.data+b.len);
		c=add(a,b);
		cnt++;
		for(int i=a.len-1;i>=0;i--){
			printf("%d",a.data[i]);
		}
		printf(" + ");		
		for(int i=b.len-1;i>=0;i--){
			printf("%d",b.data[i]);
		}		
		printf(" = ");
		for(int i=c.len-1;i>=0;i--){
			printf("%d",c.data[i]);
		}	
		printf("\n");	
		if(judge(c)==true){
			for(int i=c.len-1;i>=0;i--){
				printf("%d",c.data[i]);
			}			
			printf(" is a palindromic number.\n");
			return 0;
		}else{
			a=c;
		}		
	}
	if(cnt==10){
		printf("Not found in 10 iterations.\n");
	}
	return 0;
}









