#include<pthread.h>
 semaphore empty=10,mutex=1,full=0;
void* producer(void* arg)
{
do{
wait(empty);
wait(mutex);
//item produced
signal(mutex);
signal(full);
}while(1);
}
void* consumer(void* arg)
{
do{
wait(full);
wait(mutex);
//item consumed
signal(mutex);
signal(empty);
}while(1);
}
int main()
{
pthread_t pa,pb;
pthread_create(&pa,NULL,producer,NULL);
pthread_create(&pb,NULL,consumer,NULL);
pthread_join(pa,NULL);
pthread_join(pb,NULL);
}
