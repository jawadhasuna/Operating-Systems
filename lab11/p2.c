#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdbool.h>
bool flag[2]={false,false};
int turn;
int counter=0;
void* process_0(void* arg)
{
for(int i=0;i<5;i++)
{flag[0]=true;
turn =1;
while(flag[1]&&turn==1)
{
//busyloop
}
//cs
counter++;
printf("process 0 enter critical sec:%d\n",counter);
sleep(5);
flag[0]=false;
}
return NULL;
}
void* process_1(void* arg)
{
for(int i=0;i<5;i++)
{flag[1]=true;
turn =0;
while(flag[0]&&turn==0)
{
//busyloop
}
//cs
counter++;
printf("process 1 enter critical sec:%d\n",counter);
sleep(1);
flag[1]=false;
}
return NULL;
}
int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,process_0,NULL);
pthread_create(&t2,NULL,process_1,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
