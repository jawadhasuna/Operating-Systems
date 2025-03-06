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
pid =fork();
if(pid==0)
{
pid =fork();
if(pid==0)
{
printf("child process for %s, fibonacci series is: 0 1",argv[3]);
int n=atoi(argv[3]);
int next,first=0,second=1;
    for(int i=2;i<n;i++)
      {
    next=first+second;
    printf(" %d",next);
    first=second;
    second=next;
     }
    printf("\nchild process 3 exiting...\n");
}
else
{
printf("child process for %s, fibonacci series is: 0 1",argv[2]);
int n=atoi(argv[2]);
int next,first=0,second=1;
    for(int i=2;i<n;i++)
      {
    next=first+second;
    printf(" %d",next);
    first=second;
    second=next;
     }
    printf("\nchild process 2 exiting...\n");
}
}
else
{
printf("child process for %s, fibonacci series is: 0 1",argv[1]);
int n=atoi(argv[1]);
int next,first=0,second=1;
    for(int i=2;i<n;i++)
      {
    next=first+second;
    printf(" %d",next);
    first=second;
    second=next;
     }
    printf("\nchild process 1 exiting...\n");
}
}
else
{
printf("parent process starts...\n");
}
return 0;
}
