#include<stdio.h>
#include<pthread.h>
int count=0;
int flag[2]={0,0};
int turn;
void* increment(void*  arg)
{
do
{
flag[0]=1;
turn=1;
while(flag[1] && turn==1)
{
//busyloop
}
count++;
flag[0]=0;
}while(1);
}
void* decrement(void*  arg)
{
do
{
flag[1]=1;
turn=0;
while(flag[0] && turn==0)
{
//busyloop
}
count--;
flag[1]=0;
}while(1);
}
int main()
{
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,increment,NULL);
pthread_create(&tid2,NULL,decrement,NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
printf("count= %d",count);
return 0;
}
