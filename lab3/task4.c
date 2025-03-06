#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t pid;
pid =fork();
if(pid<0)
{
printf("error generated\n");
}
else if(pid==0)
{
printf("child's own pid: %d, parent's pid: %d",getpid(),getppid());
printf("\nexiting child process\n");
}
else
{
printf("parent own pid: %d, child's pid : %d",getpid(),pid);
printf("\nexiting parent process\n");
}
return 0;
}
