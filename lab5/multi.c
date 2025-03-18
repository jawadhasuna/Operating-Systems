#include<stdio.h>
#include<pthread.h>
void* print(void* arg)
{
char* message=(char*)arg;//cast
printf("%s\n",message);
return NULL;
}
int main()
{
char* m1="hello from thread 1";
char* m2="hello from thread 2";
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,print,(void*)m1);
pthread_create(&tid2,NULL,print,(void*)m2);  
pthread_join(tid2,NULL);  
pthread_join(tid1,NULL);
printf("thread finished\n");
return 0;
}
