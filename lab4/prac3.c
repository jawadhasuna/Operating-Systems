#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t pid;
pid=fork();
if(pid==-1)
{
printf("error\n");
return 1;
}
else if(pid==0)
{
printf("enter child process\n");
printf("parent id:%d,child id:%d \n",getppid(),getpid());
printf("child process exit\n");
}
else
{
printf("enter parent process\n");
printf("parent id:%d,child id:%d \n",getpid(),pid);
printf("parent process exit\n");
}
return 0;
}
