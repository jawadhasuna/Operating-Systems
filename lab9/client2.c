#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#define my "/tmp/fifo"
#define mine "/tmp/fifo2"
int main()
{
char message[100]="hi from client";
int fd=open(my,O_WRONLY);
write(fd,message,sizeof(message));
close(fd);
mkfifo(mine,0666);
int fd2=open(mine,O_RDONLY);
read(fd2,message,sizeof(message));
printf("message:%s",message);
close(fd2);
return 0;
}
