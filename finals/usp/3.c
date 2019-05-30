#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
  struct dirent *dir;
  DIR *dp;
  int fp;
  dp = opendir(".");
  if(dp){
    while(dir=readdir(dp)){
      fp=open(dir->d_name,O_RDONLY);
      if(!lseek(fp,0,SEEK_END)){
        unlink(dir->d_name);
      }
    }
  }
}
