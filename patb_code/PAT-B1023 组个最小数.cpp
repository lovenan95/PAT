#include<stdio.h>
//0 1 2 3 4 5 6 7 8 9
//4 0 0 1 0 0 2 2 0 1
//3000066779	
//0 0 0 0 1 2 0 2 2 1
//45577889
int main(){
	int a[10],k;
	for(int i=0;i<10;i++)
		scanf("%d",&a[i]);
	if(a[0]==0){
		for(int i=0;i<10;i++){
			k=i;
			while(a[k]==0&&k<10){
				k++;
			}
			while(a[k]>0&&k<10){
				printf("%d",k);
				a[k]--;
			}
		}
	}
	else{
			int j=1;
			while(a[j]==0&&j<10){
				j++;
			}
			printf("%d",j);
			a[j]--;
			for(int i=0;i<10;i++){
				k=i;
				while(a[k]==0&&k<10){
					k++;
				}
				while(a[k]>0&&k<10){
					printf("%d",k);
					a[k]--;
				}
			}
	}
	return 0;
}