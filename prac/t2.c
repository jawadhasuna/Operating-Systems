#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
int main(int argc,char* argv[])
{
pid_t pid;
pid=fork();
if(pid<0)
{
printf("error");
}
else if(pid==0)
{
pid=fork();
if(pid==0)
{
pid=fork();
if(pid==0)
{
int n=atoi(argv[3]);
int first=0;
int second=1;
int next=0;
printf("fib series is:%d, %d,",first,second);
for(int i=2;i<n;i++)
{
next=first+second;
printf("%d ,",next);
first=second;
second =next;
}
printf("\n");
}
else
{
int n=atoi(argv[2]);
int first=0;
int second=1;
int next=0;
printf("fib series is:%d, %d,",first,second);
for(int i=2;i<n;i++)
{
next=first+second;
printf("%d ,",next);
first=second;
second =next;
}
printf("\n");
}
}
else
{
wait(NULL);
int n=atoi(argv[1]);
int first=0;
int second=1;
int next=0;
printf("fib series is:%d, %d,",first,second);
for(int i=2;i<n;i++)
{
next=first+second;
printf("%d ,",next);
first=second;
second =next;
}
printf("\n");
}
}
else
{
printf("parent starts \n");
wait(NULL);
printf("parent end \n");
}
return 0;
}
