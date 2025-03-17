#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
int b[2];
int a[2]={10,20};
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
write(fd[1],a,sizeof(a));
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],b,sizeof(b));
int sum=b[0]+b[1];
printf("parent recieved:%d",sum);
close(fd[0]);
}
return 0;
}
