#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
int fact(int n)
{
if(n==0)
{
return 1;
}
return n*fact(n-1);
}
int main()
{
int fd[2];
char *message="5";
char buffer[50];
if(pipe(fd)==-1)
{
printf("error");
return 1;
}
pid_t pid;
pid=fork();
if(pid==0)
{
close(fd[0]);
write(fd[1],message,2);
close (fd[1]);
}
else
{
close(fd[1]);
read(fd[0],buffer,sizeof(buffer));
int n=atoi(buffer);
printf("factorial is: %d \n",fact(n));
close(fd[0]);
}
return 0;
}
