#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define size 5
int buff[5];
sem_t empty,full;
pthread_mutex_t mutex;
int in=0,out=0;
void* prod(void* arg)
{
int item;
for(int i=0;i<10;i++)
{
sem_wait(&empty);
item=i;
pthread_mutex_lock(&mutex);
buff[in]=item;
printf("poduced: %d\n",item);
in=(in+1)%size;
pthread_mutex_unlock(&mutex);
sem_post(&full);
}
}
void* consumer(void* arg)
{
int item;
for(int i=0;i<10;i++)
{
sem_wait(&full);
pthread_mutex_lock(&mutex);
item=buff[out];
printf("consumed:%d\n",item);
out=(out+1)%size;
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}
}
int main()
{
pthread_t t1,t2;
sem_init(&empty,0,5);
sem_init(&full,0,0);
pthread_mutex_init(&mutex,NULL);
pthread_create(&t1,NULL,prod,NULL);
pthread_create(&t2,NULL,consumer,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
sem_destroy(&empty);
sem_destroy(&full);
pthread_mutex_destroy(&mutex);
return 0;
}
