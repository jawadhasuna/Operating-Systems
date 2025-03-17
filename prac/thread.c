#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int br[3];
int arr[100];
void* min(void* arg)
{
int min=arr[0];
for(int i=1;i<100;i++)
{
if(min>arr[i])
{
min=arr[i];
}
}
br[0]=min;
}
void* max(void* arg)
{
int max=arr[0];
for(int i=1;i<100;i++)
{
if(max<arr[i])
{
max=arr[i];
}
}
br[1]=max;
}
void* avg(void* arg)
{
int sum=0;
for(int i=1;i<100;i++)
{
sum=sum+arr[i];
}
sum=sum/100;
br[2]=sum;
}
int main()
{
for(int i=0;i<100;i++)
{
arr[i]=rand()%20;
}
pthread_t tid1,tid2,tid3;
pthread_create(&tid1,NULL,min,NULL);
pthread_create(&tid2,NULL,max,NULL);
pthread_create(&tid3,NULL,avg,NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
pthread_join(tid3,NULL);
printf("min:%d,max:%d,avg:%d",br[0],br[1],br[2]);
return 0;
}
