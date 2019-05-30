#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<utime.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
  int fd;
  struct stat mybuf1;
  struct stat mybuf2;
  struct utimbuf times;
  if(stat(argv[1],&mybuf1)<0){
    printf("Error1\n");
  }
  if(stat(argv[2],&mybuf2)<0){
    printf("Error2\n");
  }
  printf("Before Copying ...\n");
  printf("Access Time %s \n Modification Time %s \n soo",ctime(&mybuf1.st_atime),ctime(&mybuf1.st_mtime));
  times.modtime=mybuf2.st_mtime;
  times.actime = mybuf2.st_atime;

  if(utime(argv[1],&times)<0){
    printf("error copying time \n");
  }
  if(stat(argv[1],&mybuf1)<0){
    printf("error bro! \n");
  }
  printf("access time %s and Modification time %s \n ",ctime(&mybuf1.st_atime),ctime(&mybuf1.st_mtime));

}
