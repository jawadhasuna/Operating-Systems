#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int fd,fd2;
char buff[1024];
char message[1024]="this server acknowledged client";
char* myfifo="/tmp/fifo";
char* myfifo2="/tmp/fifo2";
mkfifo(myfifo,0666);
printf("server on!\n");
fd=open(myfifo,O_RDONLY);
read(fd,buff,sizeof(buff));
printf("recieved:%s\n",buff);
close(fd);
fd2=open(myfifo2,O_WRONLY);
write(fd2,message,sizeof(message));
close(fd2);
unlink(myfifo);
return 0;
}
