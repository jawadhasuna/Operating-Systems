#include<stdio.h>
#include<pthread.h>
typedef struct{
int a,b;
char* message;
}add;
void* sum(void* arg)
{
add* obj=(add*)arg;
if(obj->a==2 && obj->b==3)
{
int c=obj->a + obj->b;
printf("%s ,%d",obj->message,c);
}
else
{
int c=obj->a - obj->b;
printf("%s ,%d",obj->message,c);
}
return NULL;
}
int main()
{
add a1,a2;
a1.a=2;
a1.b=3;
a1.message="hey from thread1";
a2.a=3;
a2.b=2;
a2.message="hey from thread2";
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,sum,(void*)&a1);
pthread_create(&tid2,NULL,sum,(void*)&a2); 
pthread_join(tid1,NULL);  
pthread_join(tid2,NULL);
return 0;
}
