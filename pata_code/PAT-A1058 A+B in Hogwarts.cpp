#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	long long galleon;
	long long sickle;
	long long knut;
};

node a,b,sum;

int main(){
	scanf("%d.%d.%d",&a.galleon,&a.sickle,&a.knut);
	scanf("%d.%d.%d",&b.galleon,&b.sickle,&b.knut);
	long long ak=a.galleon*17*29+a.sickle*29+a.knut;
	long long bk=b.galleon*17*29+b.sickle*29+b.knut;
	long long sumk=ak+bk;
	sum.galleon=sumk/(17*29);
	sum.sickle=(sumk%(17*29))/29;
	sum.knut=(sumk%(17*29))%29;
	printf("%d.%d.%d",sum.galleon,sum.sickle,sum.knut);
	return 0;
}