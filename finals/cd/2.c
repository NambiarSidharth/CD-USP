#include<stdio.h>
#include<string.h>
#include<fcntl.h>
int main(){
  FILE *fp;
  int i,j,k,multcheck=0,singlecheck,lineno=0,openline;
  char line[100];
  fp = fopen("input2.txt","r");
  while(fgets(line,sizeof(line),fp)!=NULL){
    ++lineno;
    singlecheck=0;
    if(strstr(line,"/*")&&multcheck==0){
      multcheck=1;
      openline=lineno;
    }else if(strstr(line,"/*")&&multcheck==1){
      multcheck=1;
      printf("\n multiline comment opened at line no %d is not closed \n",openline);
      openline=lineno;
    }
    if(strstr(line,"*/")&&multcheck==1){
      multcheck=0;
    }else if(strstr(line,"*/")&&multcheck==0){
      multcheck=0;
      printf("\n extra multiline closer at line no %d \n",openline);
    }
    if(strstr(line,"//")&&multcheck==0){
      singlecheck=1;
    }
    if(singlecheck==1){
      printf("\n single line comment at line %d \n",lineno);
    }
  }
}
