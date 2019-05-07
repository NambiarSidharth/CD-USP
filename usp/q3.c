//program to show different stats of a failed
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){

  struct stat fileStat;
  if(stat(argv[1],&fileStat)<0){
    printf("not owrking");
    exit(1);
  }
  printf("info of %s",argv[1]);
  printf("file size: %d",(int)fileStat.st_size);
  printf("no of links: %d",(int)fileStat.st_nlink);
  printf("file inode: %d",(int)fileStat.st_ino);

  printf("\nfile access permision\n");

printf(fileStat.st_mode & S_IRUSR?"r":"-");
printf(fileStat.st_mode & S_IWUSR?"w":"-");
printf(fileStat.st_mode & S_IXUSR?"x":"-");
printf(fileStat.st_mode & S_IRGRP?"r":"-");
printf(fileStat.st_mode & S_IWGRP?"w":"-");
printf(fileStat.st_mode & S_IXGRP?"x":"-");
printf(fileStat.st_mode & S_IROTH?"r":"-");
printf(fileStat.st_mode & S_IWOTH?"w":"-");
printf(fileStat.st_mode & S_IXOTH?"x":"-");
}
