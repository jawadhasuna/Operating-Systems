#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
 char* a="i am jawad aeiou";
char b[50];
int fd[2];
pid_t pid;
if(pipe(fd)==-1)
{
printf("error");
}
pid=fork();
if(pid==0)
{
close(fd[0]);
write(fd[1],a,strlen(a)+1);
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],b,sizeof(b));
int i=0;
int vowels=0;
while(b[i]!='\0')
{
b[i]=toupper(b[i]);
if(b[i]=='A'||b[i]=='E'||b[i]=='I'||b[i]=='O'||b[i]=='U')
{
vowels++;
}
i++;
}
printf("no of vowels::%d",vowels);
close(fd[0]);
}
return 0;
}
