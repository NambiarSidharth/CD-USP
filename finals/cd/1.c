#include<stdio.h>
#include<string.h>
#include<fcntl.h>
int main(){
  FILE *fp;
  int i,j,k,strcheck,chrcheck,lineno=0;
  char line[100];
  fp = fopen("input1.txt","r");
  while(fgets(line,sizeof(line),fp)!=NULL){
    ++lineno;
    strcheck=0;
    chrcheck=0;
    for(i=0;i<strlen(line);++i){
      if(line[i]=='"'){
        strcheck=(strcheck+1)%2;
      }else if(line[i]=='\''){
        if(strcheck==0){
          chrcheck=(chrcheck+1)%2;
        }
      }
    }
    if(strcheck==1){
      printf("\n string left opened at line no %d \n",lineno);
    }
    if(chrcheck==1){
      printf("\n character left open at line %d \n",lineno);
    }
  }
}
