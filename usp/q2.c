//program to
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>

int main(){
  int file=0,n;
  char buf[25];
  file=open("testfile.txt",O_RDONLY);
  printf("%d",file);

  if(file<-1){
    printf("\nerror occured");
    exit(1);
  }
  if(read(file,buf,20)!=20){
    printf("\nerror in reading 1");
  }else{
    write(STDOUT_FILENO,buf,20);
  }
  if(lseek(file,10,SEEK_SET)<0){
    printf("\nerror 2\n");
  }
  else
  {
    read(file,buf,20);
    printf("\n%s",buf);
  }
  if(lseek(file,10,SEEK_CUR) < 0)
printf("lseek operation to beginning of file failed\n");
if(read(file,buf,20) != 20)
printf("file read operation failed\n");
else
write(STDOUT_FILENO, buf, 20);
printf("\n");
if((n = lseek(file,0,SEEK_END)) <0)
printf("lseek operation to end of file failed\n");
printf("size of file is %d bytes\n",n);
close(file);
}
