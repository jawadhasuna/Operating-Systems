#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#define max 128
#define clientqueue "/clientqueue"
int main()
{
mqd_t mqclient;
struct mq_attr attr;
attr.mq_flags=0;
attr.mq_maxmsg=10;
attr.mq_msgsize=max;
attr.mq_curmsgs=0;
char message[max]="you are amazing";
mqclient =mq_open(clientqueue,O_CREAT|O_RDWR,0644,&attr);
mq_send(mqclient,message,strlen(message)+1,0);
printf("message sent from client: %s\n",message);
return 0;
}

