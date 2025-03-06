#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{int a=5,b=6,c=0;
pid_t pid;
pid =fork();
if(pid<0)
{
printf("error generated\n");
}
else if(pid==0)
{
c=a*b;
printf("product of two numbers is: %d",c);
printf("\nexiting child process\n");
}
else
{
wait(NULL);// if we use while command then it never runs parent process so we use wait without while
c=a+b;
printf("sum of two numbers is: %d",c);
printf("\nexiting parent process\n");
}
return 0;
}
