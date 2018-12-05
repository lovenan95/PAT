#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<string> 
#include<vector> 
#include<stack> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

struct node{
	int x,y,z;
}temp;

int M,N,L,T;
int pixel[1290][130][70];
bool inq[1290][130][70]={false};
int X[6]={1,-1,0,0,0,0};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={0,0,0,0,1,-1};
int ans=0;

bool judge(int x,int y,int z){
	if(x<0||x>=M||y<0||y>=N||z<0||z>=L)
		return false;
	if(pixel[x][y][z]==0||inq[x][y][z]==true)
		return false;
	return true;
}

int BFS(int x,int y,int z){
	int block=0;
	queue<node> q;
	temp.x=x;
	temp.y=y;
	temp.z=z;
	q.push(temp);
	inq[x][y][z]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		block++;
//		cout<<"block="<<block<<'\n'; 
//		cout<<"ans="<<ans<<'\n'; 
		for(int i=0;i<6;i++){
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			int newz=top.z+Z[i];
			if(judge(newx,newy,newz)){
				temp.x=newx;
				temp.y=newy;
				temp.z=newz;
				q.push(temp);
				inq[newx][newy][newz]=true;
			}
		}
	}
	if(block>=T){
		return block;
	}else{
		return 0;
	}
}


int main(){
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(int z=0;z<L;z++){
		for(int x=0;x<M;x++){
			for(int y=0;y<N;y++){
				scanf("%d",&pixel[x][y][z]);
			}
		}
	}
	
//	int ans=0;
	for(int z=0;z<L;z++){
		for(int x=0;x<M;x++){
			for(int y=0;y<N;y++){
				if(pixel[x][y][z]==1&&inq[x][y][z]==false){
					ans+=BFS(x,y,z);
				}
			}
		}
	}
	printf("%d",ans);



	return 0;
} 