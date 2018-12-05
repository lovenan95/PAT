#include<stdio.h>
int a1=0,a2=0,a3=0,a5=0;
double a4=0;
bool count[6]={false};
int main(){
	int a[1010];
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		if(a[i]%5==4){
			a5=a[i];
			count[5]=true;
			break;
		}
	}
	int cnt=0;
	int sum=0,cnt3=0;
	for(int i=0;i<N;i++){
		if(a[i]%5==0&&a[i]%2==0){
			a1+=a[i];
			count[1]=true;
		}
		
		if(a[i]%5==1){
			cnt++;
			count[2]=true;
			if(cnt%2==1){
				a2+=a[i];
			}else{
				a2-=a[i];
			}
		}
		
		if(a[i]%5==2){
			a3++;
			count[3]=true;
		}
		

		if(a[i]%5==3){
			cnt3++;
			count[4]=true;
			sum+=a[i];
			a4=1.0*sum/cnt3;
		}
	
		if(a[i]%5==4){
			if(a5<a[i]){
				a5=a[i];
			}
		}
	}
	if(count[1]==false){
		printf("N ");
	}else{
		printf("%d ",a1);
	}	
	if(count[2]==false){
		printf("N ");
	}else{
		printf("%d ",a2);
	}	
	if(count[3]==false){
		printf("N ");
	}else{
		printf("%d ",a3);
	}		
	if(count[4]==false){
		printf("N ");
	}else{
		printf("%0.1f ",a4);
	}		
	if(count[5]==false){
		printf("N");
	}else{
		printf("%d",a5);
	}		
	
	
	return 0;
}