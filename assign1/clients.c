#include<stdio.h>//for printf and fgets
#include<string.h>//for strlen
#include<unistd.h>//for write
#include<fcntl.h>//for open,close
#define PIPE "/tmp/namedpipe"//we save path in PIPE
int main()
{
char message[1240];//message array
int fd= open(PIPE,O_WRONLY);//open write path
  printf("enter client message: ");
  fgets(message,sizeof(message),stdin);//client message in terminal
  write(fd,message,strlen(message)+1);//writes to server pipe
  close(fd);//closes write path
return 0;
}
