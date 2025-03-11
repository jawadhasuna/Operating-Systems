#include<stdio.h>
#include<unistd.h>
int main()
{
printf("before fork creation\n");
fork();
printf("after fork creation\n");
return 0;
}
