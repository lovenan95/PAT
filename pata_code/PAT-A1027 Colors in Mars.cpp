#include<stdio.h>
char m[14]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main(){
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
	printf("#%c%c%c%c%c%c",m[r/13],m[r%13],m[g/13],m[g%13],m[b/13],m[b%13]);
	return 0;
}

