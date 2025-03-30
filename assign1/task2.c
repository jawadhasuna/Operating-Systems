#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
int fd[2];
char buffer[60];
pid_t pid;
mkfifo("/tmp/namedpipe", 0666);
pid=fork();
if(pid==0)
{
int write_fd = open("/tmp/namedpipe", O_WRONLY);
char*message="hello world";
write(write_fd,message,strlen(message)+1);
close(write_fd);
}
else 
{
int read_fd = open("/tmp/namedpipe", O_RDONLY);
read(read_fd,buffer,sizeof(buffer));
printf("%s",buffer);
close(read_fd);
}
unlink("/tmp/namedpipe");
return 0;
}
