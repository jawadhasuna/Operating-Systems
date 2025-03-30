#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>//for open and close
#include<sys/stat.h>//for making named pipe mkfifo
# define PIPE "/tmp/namedpipe"//to save path in PIPE
int main()
{
char buffer[1240];
mkfifo(PIPE,0666);//make named pipe
printf("server on waiting for clients\n");
int fd=open(PIPE,O_RDWR);//read and write both open
  while(1)
  {
   read(fd,buffer,sizeof(buffer));//reads from client via fd
   printf("recieved:%s\n",buffer);//display what it read from client
     if(strcmp(buffer,"exit\n")==0)
     {
     printf("server exiting, shutdown!\n");//server exits
     break;//to break while loop
     }
  }
close(fd);//close pipe
unlink(PIPE);//delete pipe from tmp folder
return 0;
}
