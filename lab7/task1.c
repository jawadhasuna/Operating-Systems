#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int k=0;
void* print (void*arg)
{
printf("English: Hello World! from thread %d\n",k);
k++;
}
int main()
{
pthread_t tid[7];
for(int i=0;i<7;i++)
{
printf("creating thread %d\n",i);
pthread_create(&tid[i],NULL,print,NULL);
}
for(int i=0;i<7;i++)
{
pthread_join(tid[i],NULL);
}
return 0;
}
