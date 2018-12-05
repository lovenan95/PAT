#include<stdio.h>
#include<string.h>
char a[110],n;
int main(){
  scanf("%d",&n);
  int k,judge,cnta,nump,numt,locp,loct;
  getchar();
  for(int i=0;i<n;i++){
    k=0;
    judge=0;
    nump=0;
    numt=0;
    cnta=0;
    gets(a);
    int len=strlen(a);
//    printf("-------------\n");
//    puts(a);
//    printf("-------------\n");
    while(a[k]!='\0'){
      if(a[k]!='P'&&a[k]!='A'&&a[k]!='T'){
        judge=-1;
      }else if(a[k]=='P'&&judge==0){
        judge++;
        nump++;
        locp=k;
      }else if(a[k]=='A'&&judge==1){
        judge=2;
        cnta++;
      }else if(a[k]=='T'&&judge==2){
        numt++;
		judge++;
		loct=k;
      }
      k++;
    }
    if(judge!=3||nump!=1||numt!=1){
      printf("NO\n");
      continue;
    }
    int x=locp,y=loct-locp-1,z=len-loct-1;
    
	if(judge==3&&z==(x+(y-1)*x)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}    
  }
  return 0;
}