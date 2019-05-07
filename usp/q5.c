#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
int main(){
  DIR *dp;
  struct dirent *mydir;
  dp = opendir(".");
  int fd,n;
  if(dp){
    while((mydir=readdir(dp))!=NULL){
      fd=open(mydir->d_name,O_RDONLY);
      n=lseek(fd,0,SEEK_END);
      if(!n) unlink(mydir->d_name);
    }
  }
}
