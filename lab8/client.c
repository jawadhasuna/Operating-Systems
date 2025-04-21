#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main()
{
char *myfifo="/tmp/fifo";
int fd;
char message[1024];
printf("client started\n");
fd=open(myfifo,O_WRONLY);
while(1)
{printf("enter messages:");
fgets(message,sizeof(message),stdin);
write(fd,message,strlen(message)+1);
if(strcmp(message,"exit\n")==0)
{
break;
}
}
close(fd);
return 0;
}
