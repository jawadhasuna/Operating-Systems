#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int in=0,out=0;
int arr[100];
int size=100;
int item;
void* producer(void* arg)
{
int x=0;
while(x<100000)
{
while((in+1)%size==out)
{
//busyloop
}
arr[in]=rand()%10;
in=(in+1)%size;
x++;
}
}
void* consumer(void* arg)
{
int x=0;
while(x++<100000)
{
while(in==out)
{
//busyloop
}
item=arr[out];
out=(out+1)%size;
}
}
int main()
{
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,producer,NULL);
pthread_create(&tid2,NULL,consumer,NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
return 0;
}
