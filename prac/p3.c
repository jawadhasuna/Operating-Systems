#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int fact(int n)
{
if(n==0)
{return 1;
}
return n*fact(n-1);
}
int main()
{
 char* a="4";
char b[20];
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
write(fd[1],a,strlen(a)+1);
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],b,sizeof(b));
printf("%s",b);
int n=atoi(b);
printf("parent recieved:%d",fact(n));
close(fd[0]);
}
return 0;
}
