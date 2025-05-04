#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define my "/tmp/fifo"
#define mine "/tmp/fifo2"
int main()
{
char buff[100];
int fd=open(my,O_RDONLY);
read(fd,buff,sizeof(buff));
printf("message recieved:%s\n",buff);
close(fd);
char message[100]="hi from server";
int fd2=open(mine,O_WRONLY);
write(fd2,message,sizeof(message));
close(fd2);
return 0;
}
