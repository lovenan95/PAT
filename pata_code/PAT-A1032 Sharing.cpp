#include<stdio.h>
#include<stdlib.h>
struct Node{
	char data;
	int next;
	int flag;
}node[100010];
int main(){
	int addr1,addr2,N;
	scanf("%d %d %d",&addr1,&addr2,&N);
	int addr0=addr1;
	int address,next;
	char data;
	for(int i=0;i<N;i++){
		scanf("%d %c %d",&address,&data,&next);
		node[address].data=data;
		node[address].next=next;
		node[address].flag=0;
	}
	while(addr1!=-1){
		node[addr1].flag++;
		addr1=node[addr1].next;
	}
	while(addr2!=-1){
		node[addr2].flag++;
		addr2=node[addr2].next;
	}
	int i;
	for(i=addr0;i!=-1;i=node[i].next){
		if(node[i].flag==2){
			printf("%05d",i);
			break;
		}
	}
	if(i==-1){
		printf("-1");
	}
	return 0;
}