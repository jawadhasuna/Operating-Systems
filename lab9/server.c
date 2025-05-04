#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#define my "/tmp/fifo"
int main()
{
mkfifo(my,0666);
char buff[100];
int fd=open(my,O_RDWR);
while(1)
{
read(fd,buff,sizeof(buff));
printf("server recieved:%s\n",buff);
if(strcmp(buff,"exit\n")==0)
{
break;
}
}
close(fd);
return 0;
}
