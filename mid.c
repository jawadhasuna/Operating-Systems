#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
int in1=0,out1=0;
int count1=0;
int size=5;
int buffer1[5];
int buffer2[2];
int j=0;
void* producer(void* arg)
{
int itemP;
for(int i=0;i<15;i++)
{
while(count1==size)
{//busyloop
}
itemP=rand()%100+1;
printf("produced:%d\n",itemP);
buffer1[in1]=itemP;
in1=(in1+1)%size;
count1++;
sleep(1);
}
}
void* consumer(void* arg)
{
int itemC;
for(int i=0;i<15;i++)
{
while(count1==0)
{//busyloop 
}
itemC=buffer1[out1];
out1=(out1+1)%size;
count1--;
printf("consumed:%d\n",itemC);
sleep(1);
int a=sqrt(itemC);
if(itemC%5==0)
{
//num 1 for mul of 5
printf("mul of 5:%d\n",itemC);
write(buffer2[1],&itemC,sizeof(itemC));
}
else if(a*a==itemC)
{
//num 2 for square
printf("perfect square:%d\n",itemC);
write(buffer2[1],&itemC,sizeof(itemC));
}
}
}
void* result(void*arg)
{
int ans;
read(buffer2[0],&ans,sizeof(ans));
printf("%d\n",ans);
sleep(1);
}
int main()
{
pipe(buffer2);
srand(time(NULL));
pthread_t t1,t2,t3;
pthread_create(&t1,NULL,producer,NULL);
pthread_create(&t2,NULL,consumer,NULL);
pthread_create(&t3,NULL,result,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
return 0;
}
