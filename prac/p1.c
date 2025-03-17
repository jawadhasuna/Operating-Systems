#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
int b;
int a=10;
int fd[2];
pid_t pid;
if(pipe(fd)==-1)
{
printf("error");
}
pid=fork();
if(pid==0)
{
close(fd[0]);
write(fd[1],&a,sizeof(a));
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],&b,sizeof(b));
printf("parent recieved:%d",b);
close(fd[0]);
}
return 0;
}
