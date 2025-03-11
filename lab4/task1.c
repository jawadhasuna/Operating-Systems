#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
int main()
{
int fd[2];
int buffer;
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
int a=5;
write(fd[1],&a,sizeof(a));
close (fd[1]);
}
else
{
close(fd[1]);
read(fd[0],&buffer,sizeof(buffer));
printf("integer is: %d",buffer);
close(fd[0]);
}
return 0;
}

