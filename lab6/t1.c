#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int count=0;
#define size 5
int buffer[size];
int in=0,out=0;
void* producer(void* arg)
{
int itemp;
int c=0;
while(c!=8)
{
while(count==size)
{
//busyloop
}
itemp=rand()%100;
buffer[in]=itemp;
printf("produced item:%d \n",buffer[in]);
in=(in+1)%size;
count++;
sleep(1);
c++;
}
}
void* consumer(void* arg)
{
int itemc;
int c=0;
while(c!=8)
{
while(count==0)
{
//busyloop
}
itemc=buffer[out];
printf("consumed item:%d \n",itemc);
out=(out+1)%size;
count--;
sleep(1);
c++;
}
}
int main()
{
pthread_t pthread,cthread;
pthread_create(&pthread,NULL,producer,NULL);
pthread_create(&cthread,NULL,consumer,NULL);
pthread_join(pthread,NULL);
pthread_join(cthread,NULL);
return 0;
}
