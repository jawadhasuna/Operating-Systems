#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#define max 128
#define queuename "/myqueue"
int main()
{
pid_t pid;
mqd_t mq;
struct mq_attr attr;
attr.mq_flags=0;
attr.mq_maxmsg=10;
attr.mq_msgsize=max;
attr.mq_curmsgs=0;
char message[max]="hello from child";
char buffer[max];
pid=fork();
if(pid==0)
{
mq =mq_open(queuename,O_CREAT|O_RDWR,0644,&attr);
mq_send(mq,message,strlen(message)+1,0);
printf("message sent %s\n",message);
mq_close(mq);
mq_unlink(queuename);
}
else
{
wait(NULL);
mq =mq_open(queuename,O_CREAT|O_RDWR,0644,&attr);
mq_receive(mq,buffer,max,NULL);
printf("message recieved %s\n",buffer);
mq_close(mq);
mq_unlink(queuename);
}
return 0;
}

