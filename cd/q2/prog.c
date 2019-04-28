#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){

  FILE *fp;
  char line[100];
  int commentCheck=0,lineno;
  int error=0,i;

  int open=0,close=0;
  fp=fopen("file.txt","r");
  if(fp==NULL){
    printf("error in opening");
  }else{
    while(fgets(line,sizeof(line),fp)!=NULL){
      lineno++;

        if(str(line,"/*")){
        if(open==0 && close==0){
        commentCheck=lineno;
        open=1;
        }
        else if (open==1 && close==0){
        printf("unclosed comment starting from %d",commentCheck);
        commentCheck=lineno;
      }else if (open==1 && close==1){
        commentCheck=lineno;
        close=0;
      }
    }else if(str(line,"*/")){
        close=1;
      }

      }
    }
  }
