#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
char buffer[50];
int fd[2];
pid_t pid;
if(pipe(fd)==-1)
{
printf("error");
}
pid=fork();
if(pid==0)
{
char* message="hello world";
close(fd[0]);
write(fd[1],message,strlen(message)+1);
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],buffer,sizeof(buffer));
printf("message is:%s",buffer);
close(fd[0]);
}
return 0;
}
