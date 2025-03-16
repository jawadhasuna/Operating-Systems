#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
char buffer;
int fd[2];
pid_t pid;
if(pipe(fd)==-1)
{
printf("error");
}
pid=fork();
if(pid==0)
{
char message='h';
close(fd[0]);
write(fd[1],&message,1);
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],&buffer,1);
printf("message is:%c",buffer);
close(fd[0]);
}
return 0;
}
