#include<stdio.h>
int a[15];
int n;
int main(){
	scanf("%d",&n);
	int num=0;
	while(n!=0){
		a[num++]=n%10;
		n/=10;
	}
	for(int i=num-1;i>=0;i--){
		if(i==2){
			int tb=a[i];
			while(tb!=0){
				printf("B");	
				tb--;
			}
		}
		else if(i==1)
		{
			int ts=a[i];
			while(ts!=0){
				printf("S");	
				ts--;
			}
		}
		else if(i==0){
			for(int j=1;j<=a[i];j++){
				printf("%d",j);
			}
			
			
		}
		
	}
		
	
	
	
	
	
	return 0;
}