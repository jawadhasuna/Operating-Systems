#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
int main()
{
char *myfifo2="/tmp/fifo2";
char *myfifo="/tmp/fifo";
int fd,fd2;
char message[1024]="client sent this message to server";
char buff[1024];
printf("client started\n");
fd=open(myfifo,O_WRONLY);
write(fd,message,sizeof(message));
close(fd);
mkfifo(myfifo2,0666);
fd2=open(myfifo2,O_RDONLY);
read(fd2,buff,sizeof(buff));
printf("recieved:%s\n",buff);
close(fd2);
unlink(myfifo2);
return 0;
}
