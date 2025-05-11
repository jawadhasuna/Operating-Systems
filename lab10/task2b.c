#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
sem_t semaphore;
pthread_mutex_t mutex;
void* critical(void* arg)
{
sem_wait(&semaphore);
printf("thread:%ld enter critical sec\n",pthread_self());
//cs
sleep(2);
printf("thread:%ld leave critical sec\n",pthread_self());
sem_post(&semaphore);
return NULL;
}
int main()
{
pthread_t t1,t2;
sem_init(&semaphore,0,1);
pthread_create(&t1,NULL,critical,NULL);
pthread_create(&t2,NULL,critical,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
sem_destroy(&semaphore);
return 0;
}
