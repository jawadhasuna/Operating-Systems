#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc,char*argv[])
{
pid_t pid;

for(int i=1;i<argc;i++)
{
pid=fork();
if(pid==0)
{
execlp(argv[i],argv[i],NULL);
}
else
{
wait(NULL);
}
}
return 0;
}
