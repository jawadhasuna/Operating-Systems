#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define my "/tmp/fifo"
int main()
{
char message[100];
int fd=open(my,O_WRONLY);
while(1)
{
printf("write message:");
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
