#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#define my "/tmp/fifo"
int main()
{
mkfifo(my,0666);
char message[100];
int fd=open(my,O_RDONLY);
read(fd,message,sizeof(message));
printf("recieved:%s\n",message);
close(fd);
return 0;
}
