#include<pthread.h>
 int readcount=0;
 semaphore wrt=1,mutex=1;
void* reader(void* arg)
{
do{
wait(mutex);
readcount++; 
if(readcount==1)
{
wait(mutex);
}
signal(mutex);
//cs
wait(mutex);
readcount--;
if(readcount==0)
{
signal(wrt);
}
signal(mutex);
}while(1);
}
void* writer(void* arg)
{
do{
wait(wrt);
//cs
signal(wrt);
}while(1);
}
int main()
{
pthread_t pa,pb;
pthread_create(&pa,NULL,reader,NULL);
pthread_create(&pb,NULL,writer,NULL);
pthread_join(pa,NULL);
pthread_join(pb,NULL);
}
