#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define size 5
int buff[5];
int in=0,out=0;
sem_t empty,full;
pthread_mutex_t mutex;
void* prod (void* arg)
{
int item;
for(int i=0;i<10;i++)
{
sem_wait(&empty);
pthread_mutex_lock(&mutex);
item=i;
buff[in]=item;
printf("produced: %d\n",item);
in=(in+1)%size;
pthread_mutex_unlock(&mutex);
sem_post(&full);
}
return NULL;
}
void* cons (void* arg)
{
int item;
for(int i=0;i<10;i++)
{
sem_wait(&full);
pthread_mutex_lock(&mutex);
item=buff[out];
printf("consumed: %d\n",item);
out=(out+1)%size;
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}
return NULL;
}
int main()
{
sem_init(&empty,0,5);
sem_init(&full,0,0);
pthread_mutex_init(&mutex,NULL);
pthread_t p,c;
pthread_create(&p,NULL,prod,NULL);
pthread_create(&c,NULL,cons,NULL);
pthread_join(p,NULL);
pthread_join(c,NULL);
sem_destroy(&empty);
sem_destroy(&full);
pthread_mutex_destroy(&mutex);
return 0;
}

