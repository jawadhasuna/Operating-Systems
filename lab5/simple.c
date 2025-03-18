#include<stdio.h>
#include<pthread.h>
void* print(void* arg)
{
printf("helloe from thread");
return NUll;
}
int main()
{
pthread_t tid;
pthread_create(&tid,NULL,print,NULL);
pthread_join();  
return 0;
}
