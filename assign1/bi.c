#include<unistd.h>
#include<string.h>
#include<stdio.h>
int main()
{
int fd1[2];
int fd2[2];
pipe(fd1);
pipe(fd2);
char buffer[60];
pid_t pid;
pid=fork();
if(pid==0)
{
close(fd1[0]);
close(fd2[1]);
char*message="hello from child";
write(fd1[1],message,strlen(message)+1);
read(fd2[0],buffer,sizeof(buffer));
printf("%s",buffer);
close(fd1[1]);
close(fd2[0]);
}
else 
{
close(fd1[1]);
close(fd2[0]);
char*message="hello from parent";
write(fd2[1],message,strlen(message)+1);
read(fd1[0],buffer,sizeof(buffer));
printf("%s",buffer);
close(fd1[0]);
close(fd2[1]);
}
return 0;
}
