#include<stdio.h>

typedef struct pol
{
	int exp;
	double coe;
}pol;

int input(pol pol[],int k)
{
	int m;
	double n;
	k=k-1;
	for(;k>=0;k--)
	{
		scanf("%d %lf",&m,&n);
		pol[k].exp=m;
		pol[k].coe=n;
	}
	return 0;
}

int main()
{
	pol p[20],q[20],r[20];

	for(int l=0;l<20;l++)
	{
		p[l].coe=0;q[l].coe=0;r[l].coe=0;
		p[l].exp=0;q[l].exp=0;r[l].exp=0;
	}
	int k1,k2,k=0,i=0,j=0;
	scanf("%d",&k1);
//	int kk=k1;
	input(p,k1);
//	printf("%d\n",k1);
	k1--;
//	for(;k1>=0;k1--)
//		printf("%g %.1lf ",p[k1].exp,p[k1].coe);
	scanf("%d",&k2);
	input(q,k2);
	k2--;
	while(k1!=-1&&k2!=-1)
	{
		if(p[k1].exp==q[k2].exp)
		{
			r[k].exp=p[k1].exp;
			r[k].coe=p[k1].coe+q[k2].coe;
			k++;k1--;k2--;
		}
		else if(p[k1].exp>q[k2].exp)
		{
			r[k].exp=p[k1].exp;
			r[k].coe=p[k1].coe;
			k++;k1--;
		}
		else if(p[k1].exp<q[k2].exp)
		{
			r[k].exp=q[k2].exp;
			r[k].coe=q[k2].coe;
			k++;k2--;
		}
	}
	while(k1==-1&&k2!=-1)
	{
		r[k].exp=q[k2].exp;
		r[k].coe=q[k2].coe;
		k++;k2--;
	}
	while(k1!=-1&&k2==-1)
	{
		r[k].exp=p[k1].exp;
		r[k].coe=p[k1].coe;
		k++;k1--;
	}
	int cnt=0;
	for(int t=0;t<20;t++)
	{
		if(r[t].coe!=0)
			cnt++;
	}
	if(cnt!=0)
	{
		printf("%d ",cnt);
		int e=0;
		while(e<20)
		{
			if(r[e].coe!=0)
			{
				printf("%d %.1lf",r[e].exp,r[e].coe);
				cnt--;
				if(cnt!=0)
				printf(" ");
			}
			e++;
		}
	}
	else
		printf("0");
	return 0;
}