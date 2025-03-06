#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
if(argc<=1)
{
return 1;
}
pid_t pid;
pid =fork();
if(pid<0)
{
printf("error generated\n");
}
else if(pid ==0)
{
printf("this is child process\n");
int n=atoi(argv[1]);
int next,first=0,second=1;
for(int i=2;i<n;i++)
{
next=first+second;
printf("\nnext is: %d",next);

first=second;
second=next;
}
printf("\nasked fibonacci series no is: %d",next);
}
else
{
printf("this is parent process\n");
}
return 0;
}
