#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=100;

int main(){
	int T;
	long long a,b,c,sum;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		sum=a+b;
		if(a>0&&b>0&&sum<0){
			printf("Case #%d: true\n",i);
		}else if(a<0&&b<0&&sum>=0){
			printf("Case #%d: false\n",i);
		}else if(sum>c){
			printf("Case #%d: true\n",i);
		}else if(sum<=c){
			printf("Case #%d: false\n",i);
		}
	}
	return 0;
}