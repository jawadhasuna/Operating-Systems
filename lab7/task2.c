#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int k=2;
int main()
{
pid_t pid;
for(int i=0;i<3;i++)
{
pid=fork();
if(pid==0)
{
printf("child process:square of %d is:%d\n",k,k*k);
break;
}
else
{
wait(NULL);
printf("parent:child process with pid:%d finished\n",pid);
if(k==6)
{
printf("all child process finished calculating squares\n");
}
}
k=k+2;
}
return 0;
}
