#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
sem_t semaphore;
void* cs (void* arg)
{
sem_wait(&semaphore);
printf("thread: %ld enter critical sec\n",pthread_self());
sleep(2);//cs
printf("thread: %ld leave critical sec\n",pthread_self());
sem_post(&semaphore);
return NULL;
}
int main()
{
sem_init(&semaphore,0,1);
pthread_t p1,p2;
pthread_create(&p1,NULL,cs,NULL);
pthread_create(&p2,NULL,cs,NULL);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
sem_destroy(&semaphore);
return 0;
}
