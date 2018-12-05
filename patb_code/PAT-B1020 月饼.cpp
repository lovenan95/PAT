#include <stdio.h>
#include <algorithm>
using namespace std;
struct mooncake{
	double store;
	double sell;
	double price;
}cake[1010];
bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
}
int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].store);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].sell);
		cake[i].price=cake[i].sell/cake[i].store;
	}
	sort(cake,cake+n,cmp);
	double profit=0;
	for(int i=0;i<n;i++){
		if(cake[i].store>=d){
			profit=profit+d*cake[i].price;
			d=0;
		}
		else{
			d=d-cake[i].store;
			profit=profit+cake[i].sell;
		}
	}
	printf("%0.2lf",profit);
	return 0;
}