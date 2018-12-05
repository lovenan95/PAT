#include <stdio.h>
int main(){
	int n;
	int a[100001]={0};
	scanf("%d",&n);
	int i=0;
	int id,score;
	while(i<n)
	{
		scanf("%d %d",&id,&score);
		a[id]=a[id]+score;
		i++;
	}
	int maxnum,maxscore=0;
	for(int m=0;m<=n;m++)
	{
		if(maxscore<a[m])
		{
			maxscore=a[m];
			maxnum=m;
		}
	}
	printf("%d %d",maxnum,maxscore);
	return 0;
}