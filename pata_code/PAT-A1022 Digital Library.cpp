#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<stack> 
#include<string.h> 
#include<math.h> 
#include<queue> 
#include<map> 
#include<set> 
#include<algorithm>
using namespace std;

const int maxn=100010;
int n;

struct node{
	int id;
	string title;
	string author;
	string keyword;
	string publisher;
	string year;
}bk[maxn];

map< string,set<int> > mpt,mpa,mpk,mpp,mpy;

//void show(map< string,set<int> > &mp,string &str){
//	if(mp.find(str)==mp.end()){
//		printf("Not Found\n");
//	}else{
//		for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++){
//			printf("%07d\n",*it);
//		}
//	}	
//}

int main(){
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		scanf("%d",&bk[i].id);
		getchar();/*!!!!!*/
		getline(cin,bk[i].title);
		getline(cin,bk[i].author);
		while(cin>>bk[i].keyword){/*!!!!!!²ð·Ö¶ÁÈë*/
//			cout<<"**********key="<<bk[i].keyword<<endl;
			mpk[bk[i].keyword].insert(bk[i].id);
			char c=getchar();/*!!!!!!*/
			if(c=='\n'){
				break;
			}
		}
		getline(cin,bk[i].publisher);
		getline(cin,bk[i].year);
		mpa[bk[i].author].insert(bk[i].id);		
		mpt[bk[i].title].insert(bk[i].id);
		mpp[bk[i].publisher].insert(bk[i].id);
		mpy[bk[i].year].insert(bk[i].id);
	}	
	int qk;
	scanf("%d",&qk);
	for(int i=0;i<qk;i++){
		int numq;
		scanf("%d: ",&numq);
		string str;
		getline(cin,str);
		cout<<numq<<": "<<str<<endl;
		if(numq==1){
			if(mpt.find(str)==mpt.end()){
				printf("Not Found\n");
			}else{
				for(set<int>::iterator it=mpt[str].begin();it!=mpt[str].end();it++){
					printf("%07d\n",*it);
				}
			}
		}else if(numq==2){
			if(mpa.find(str)==mpa.end()){
				printf("Not Found\n");
			}else{
				for(set<int>::iterator it=mpa[str].begin();it!=mpa[str].end();it++){
					printf("%07d\n",*it);
				}
			}
		}else if(numq==3){
			if(mpk.find(str)==mpk.end()){
				printf("Not Found\n");
			}else{
				for(set<int>::iterator it=mpk[str].begin();it!=mpk[str].end();it++){
					printf("%07d\n",*it);
				}
			}			
		}else if(numq==4){
			if(mpp.find(str)==mpp.end()){
				printf("Not Found\n");
			}else{
				for(set<int>::iterator it=mpp[str].begin();it!=mpp[str].end();it++){
					printf("%07d\n",*it);
				}
			}			
		}else if(numq==5){
			if(mpy.find(str)==mpy.end()){
				printf("Not Found\n");
			}else{
				for(set<int>::iterator it=mpy[str].begin();it!=mpy[str].end();it++){
					printf("%07d\n",*it);
				}
			}			
		}
	}
	return 0;
}









