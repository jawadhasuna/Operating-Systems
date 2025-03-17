#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
int main()
{
int a=5,b=6,c=0;
pid_t pid;
pid=fork();
if(pid==0)
{
c=a*b;
printf("child process product: %d \n",c);
}
else
{
c=a+b;
printf("parent process sum:%d",c );
wait(NULL);
printf("math operation completed");
}
return 0;
}
