#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int sum=0;
void* total(void* arg)
{
char* arr=(char*)arg;
int limit=atoi(arr);
printf("%d",limit);
for(int i=1;i<=limit;i++)
{
sum=sum+i;
}
return  NULL;
}
int main(int argc,char* argv[])
{
pthread_t tid;
pthread_create(&tid,NULL,total,argv[1]);
pthread_join(tid,NULL);
printf("sum is: %d\n",sum);
return 0;
}
