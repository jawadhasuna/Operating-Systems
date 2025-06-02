#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#define max 128
#define clientqueue "/clientqueue"
#define serverqueue "/serverqueue"
int main()
{
mqd_t mqclient;
struct mq_attr attr;
attr.mq_flags=0;
attr.mq_maxmsg=10;
attr.mq_msgsize=max;
attr.mq_curmsgs=0;
mqclient =mq_open(clientqueue,O_CREAT|O_RDWR,0644,&attr);
char buffer[max];
mq_receive(mqclient,buffer,max,NULL);
printf("message recieved from client: %s\n",buffer);
if (strcasestr(buffer, "hate") != NULL) 
{
    printf("Moderator: Inappropriate content found.not sending to server\n");
}
else
{
printf("clean.forwarding message to server\n");
mqd_t mqserver;
struct mq_attr attr;
attr.mq_flags=0;
attr.mq_maxmsg=10;
attr.mq_msgsize=max;
attr.mq_curmsgs=0;
mqserver =mq_open(serverqueue,O_CREAT|O_RDWR,0644,&attr);
mq_send(mqserver,buffer,strlen(buffer)+1,0);
}
return 0;
}
