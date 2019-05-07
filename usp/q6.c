#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char* argv[]){
  if(argc==3){
    printf("creating a hardlink for %s and %s",argv[1],argv[2]);
    if(link(argv[1],argv[2])==0){
      printf("\n Hard link created");
    }
    else{
      printf("\n Link not created");
    }
  }
  else if(argc==4){
    printf("soft linking %s and %s",argv[1],argv[2]);
    if(symlink(argv[1],argv[2])==0){
      printf("\n soft linking done");
    }else{
      printf("some error");
    }
  }

}
