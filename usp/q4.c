#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
int main(int argc,char* argv[]){
  struct dirent *dir;
  struct stat mystat;
  DIR *dp;
  dp = opendir(".");
  if(dp){
    while(dir=readdir(dp)){
      stat(dir->d_name,&mystat);
      printf("\n%ld %o %d %d %s \n",mystat.st_ino,mystat.st_mode,mystat.st_uid,mystat.st_gid,ctime(&mystat.st_atime));
    }
  }

}
