#include <stdio.h>
int main()
{
	int n;
	char a;
	scanf("%d %c",&n,&a);
	if(n%2==1)
	{
		for(int j=0;j<n/2+1;j++)
		{
			if(j==0||j==n/2)
			{
				for(int i=0;i<n;i++)
					printf("%c",a);
				printf("\n");
			}
			else{
				printf("%c",a);
				for(int i=0;i<n-2;i++)
					printf(" ");
				printf("%c",a);
				printf("\n");
			}
		}
	}
	else{
		for(int j=0;j<n/2;j++)
		{
			if(j==0||j==n/2-1)
			{
				for(int i=0;i<n;i++)
					printf("%c",a);
				printf("\n");
			}
			else{
				printf("%c",a);
				for(int i=0;i<n-2;i++)
					printf(" ");
				printf("%c",a);
				printf("\n");
			}
		}
	}
	
	return 0;
}