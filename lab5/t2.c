#include<stdio.h>
#include<pthread.h>
void* print(void* arg)
{
char* message=(char*)arg;//cast
printf("%s\n",message);
return NULL;
}
void* printroll(void* arg)
{
int* roll=(int*)arg;//cast
printf("%d\n",*roll);
return NULL;
}
int main()
{
char* first="Jawad";
char* last="Hassan";
int roll=35;
pthread_t tid1,tid2,tid3;
pthread_create(&tid1,NULL,print,(void*)first);
pthread_create(&tid2,NULL,print,(void*)last);  
pthread_create(&tid3,NULL,printroll,(void*)&roll); 
pthread_join(tid1,NULL);  
pthread_join(tid2,NULL);
pthread_join(tid3,NULL);
printf("thread finished\n");
return 0;
}
