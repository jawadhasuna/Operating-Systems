#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int fd;
char buff[1024];
char* myfifo="/tmp/fifo";
mkfifo(myfifo,0666);
printf("server on waiting for client messages:\n");
fd=open(myfifo,O_RDWR);
while(1)
{
read(fd,buff,sizeof(buff));
printf("recieved:%s",buff);
if(strcmp(buff,"exit\n")==0)
{
printf("server exiting shutdown\n");
break;
}
}
close(fd);
unlink(myfifo);
return 0;
}
