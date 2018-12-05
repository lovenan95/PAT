#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

struct node{
	int galleon,sickle,knut;
}p,a,z;

int main(){
	scanf("%d.%d.%d",&p.galleon,&p.sickle,&p.knut);
	scanf("%d.%d.%d",&a.galleon,&a.sickle,&a.knut);
	int sp,sa,sz;
	sp=p.galleon*17*29+p.sickle*29+p.knut;
	sa=a.galleon*17*29+a.sickle*29+a.knut;
	sz=sa-sp;
	if(sz<0){
		printf("-");
		sz=-sz;
	}
	z.galleon=sz/(17*29);
	z.sickle=(sz%(17*29))/29;
	z.knut=(sz%29);
	printf("%d.%d.%d",z.galleon,z.sickle,z.knut);
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}