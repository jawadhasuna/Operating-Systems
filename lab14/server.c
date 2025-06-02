#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#define max 128
#define serverqueue "/serverqueue"
int main()
{
mqd_t mqserver;
struct mq_attr attr;
attr.mq_flags=0;
attr.mq_maxmsg=10;
attr.mq_msgsize=max;
attr.mq_curmsgs=0;
char buffer[max];
mqserver=mq_open(serverqueue,O_CREAT|O_RDWR,0644,&attr);
mq_receive(mqserver,buffer,max,NULL);
printf("message recieved from moderator: %s\n",buffer);
return 0;
}
