#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
int main()
{
int fd[2];
int buffer[2];
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
int arr[2]={2,5};
write(fd[1],arr,sizeof(arr));
close (fd[1]);
}
else
{
close(fd[1]);
read(fd[0],buffer,sizeof(buffer));
int sum=buffer[0]+buffer[1];
printf("sum is: %d\n",sum);
close(fd[0]);
}
return 0;
}
