#include<stdio.h>
#include<algorithm>
using namespace std;
struct Node{
	int key;
	int next;
}node[100010];
struct PNode{
	int key;
	int next;
	int address;
}pnode[100010];
bool cmp(PNode a,PNode b){
	return a.key<b.key;
}
int main(){
	int N,addrh;
	scanf("%d %d",&N,&addrh);
	int address,key,next;
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&address,&key,&next);
		node[address].key=key;
		node[address].next=next;
		pnode[i].address=address;
		pnode[i].key=key;
		pnode[i].next=next;
	}
	sort(pnode,pnode+N,cmp);
	printf("%d %05d\n",N,pnode[0].address);
	for(int i=0;i<N-1;i++){
		pnode[i].next=pnode[i+1].address;
		printf("%05d %d %05d\n",pnode[i].address,pnode[i].key,pnode[i].next);
	}
	printf("%05d %d -1",pnode[N-1].address,pnode[N-1].key);
	return 0;
}