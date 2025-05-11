#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
sem_t a,b,c,d,e,f;
void* thread1 (void* arg)
{
sem_wait(&a);
printf("thread1: A\n");
sem_post(&b);
sem_wait(&c);
printf("thread1: C\n");
sem_post(&d);
sem_wait(&e);
printf("thread1: E\n");
sem_post(&f);
return NULL;
}
void* thread2 (void* arg)
{
sem_wait(&b);
printf("thread2: B\n");
sem_post(&c);
sem_wait(&d);
printf("thread2: D\n");
sem_post(&e);
sem_wait(&f);
printf("thread2: F\n");
return NULL;
}
int main()
{
sem_init(&a,0,1);
sem_init(&b,0,0);
sem_init(&c,0,0);
sem_init(&d,0,0);
sem_init(&e,0,0);
sem_init(&f,0,0);
pthread_t p1,p2;
pthread_create(&p1,NULL,thread1,NULL);
pthread_create(&p2,NULL,thread2,NULL);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
sem_destroy(&a);
sem_destroy(&b);
sem_destroy(&c);
sem_destroy(&d);
sem_destroy(&e);
sem_destroy(&f);
return 0;
}
