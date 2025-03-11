#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>
int main()
{
int fd[2];
char *message="I am Jawad Hassan";
char buffer[50];
if(pipe(fd)==-1)
{
printf("error");
return 1;
}
pid_t pid;
pid=fork();
if(pid==0)
{
close(fd[0]);
write(fd[1],message,strlen(message)+1);
close (fd[1]);
}
else
{
close(fd[1]);
read(fd[0],buffer,sizeof(buffer));
int i=0;
int vowel=0;
while(buffer[i]!='\0')
{
buffer[i]=toupper(buffer[i]);
if(buffer[i]=='A'||buffer[i]=='E'||buffer[i]=='I'||buffer[i]=='O'||buffer[i]=='U')
  {vowel++;}
i++;
}
printf("no. of vowels are: %d \n",vowel);
close(fd[0]);
}
return 0;
}
