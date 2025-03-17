#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
{
printf("child process pid:%d, parent pid: %d \n",getpid(),getppid());
}
else
{
printf("parent process pid:%d, child pid: %d \n",getpid(),pid);
}
return 0;
}
