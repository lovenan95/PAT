#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#include<vector> 
#include<map> 
using namespace std;

const int maxn=100010;
int n;
int a[maxn];

//bool judge(int a[]){
//  for(int i=0;i<n;i++){
//    if(a[i]!=i){
//      return false;
//    }
//  }
//  return true;
//}

int main(){
	  scanf("%d",&n);
	  for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	  }
	  int left=0;
	  for(int i=0;i<n;i++){
	    if(a[i]!=i&&a[i]!=0){
	      left++;
	    }
	  }
	  int pos;
	  for(pos=0;pos<n;pos++){
	    if(a[pos]==0){
	      break;
	    }
	  }
	  
	  int cnt=0,idx=1;
	  while(left>0){
	    if(a[0]==0){
	      for(;idx<n;idx++){
	        if(a[idx]!=idx){
	          swap(a[0],a[idx]);
	          cnt++;
	          pos=idx;
	          break;
	        }
	      }
	    }
//	    for(int i=0;i<n&&a[0]!=0;i++){
//		    if(a[i]==pos){
//		        swap(a[i],a[pos]);
//		        cnt++;
//		        left--;
//		        pos=i;
//		        break;
//	     	}
//		}    
    	
    	while(a[0]!=0){
			swap(a[0],a[a[0]]);
			cnt++;
			left--;
		}
    	
//  for(int i=0;i<n;i++){
//    printf("%d ",a[i]);
//  }
//  printf("\n");            
 	 }
  	printf("%d\n",cnt);
//  for(int i=0;i<n;i++){
//    printf("%d ",a[i]);
//  }
  	return 0;
}