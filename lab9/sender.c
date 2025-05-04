#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define my "/tmp/fifo"
int main()
{
char message[100]="hi jawad";
int fd=open(my,O_WRONLY);
write(fd,message,sizeof(message));
close(fd);
return 0;
}
