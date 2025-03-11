#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
pid_t pid;
pid=fork();
if(argc<2)
{
printf("no value\n");
return 1;
}
if(pid==0)
{
int n=atoi(argv[1]);
int next,first=0,second=1;
for(int i=2;i<n;i++)
{
next=first+second;
first=second;
second=next;
}
printf("fib is:%d\n",next);
}
else
{
wait(NULL);
printf("hello parent\n");
}

return 0;
}
