#include<pthread.h>
#include<stdio.h>
#include<stdbool.h>
#include<unistd.h>
bool flag[2];
int turn;
int counter=5;
void* process_0 (void* arg)
{
for(int i=0;i<5;i++)
{flag[0]=true;
turn=1;
while(flag[1]&&turn==1)
{//busyloop
}
//cs
printf("process 0 enter critical section\n");
counter++;
sleep(2);
flag[0]=false;
}
}
void* process_1 (void* arg)
{
for(int i=0;i<5;i++)
{
flag[1]=true;
turn=0;
while(flag[0]&&turn==0)
{//busyloop
}
//cs
printf("process 1 enter critical section\n");
counter--;
sleep(2);
flag[1]=false;
}
}
int main()
{
pthread_t p1,p2;
pthread_create(&p1,NULL,process_0,NULL);
pthread_create(&p2,NULL,process_1,NULL);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
printf("final counter: %d\n",counter);
return 0;
}
