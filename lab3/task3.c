#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int i;
int child=3;
pid_t pid;
for( i=0;i<child;i++)//to run 3 child process
{
pid =fork();
if(pid<0)
{
printf("error generated\n");
}
else if(pid==0)
{
printf("child process %d: %d\n",i+1,getpid());
return 0;
}
}
return 0;
}
