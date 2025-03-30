#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#define PIPE "/tmp/namedpipe"
int main()
{
mkfifo(PIPE,0666);
int fd;
char buffer[50];
pid_t pid;
pid=fork();
if(pid==0)
{
fd=open(PIPE,O_WRONLY);
char* message="hello world jawad";
write(fd,message,strlen(message)+1);
close(fd);
}
else
{
fd=open(PIPE,O_RDONLY);
read(fd,buffer,sizeof(buffer));
printf("%s",buffer);
close(fd);
}
unlink(PIPE);
return 0;
}
