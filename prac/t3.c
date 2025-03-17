#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
int main()
{
pid_t pid;
for(int i=0;i<4;i++)
{
pid=fork();
if(pid==0)
{
printf("child process:%d",i+1);
return 0;
}
}

return 0;
}
