#include<stdio.h>
#include<pthread.h>
int a=0,b=0;
void* sum1(void* arg)
{
int* arr=(int*)arg;
for(int i=0;i<=4;i++)
{
a=a+arr[i];
}
return NULL;
}
void* sum2(void* arg)
{
int* arr=(int*)arg;
for(int i=5;i<=9;i++)
{
b=b+arr[i];
}
return NULL;
}
int main()
{
int arr[10]={1,2,3,4,5,6,7,8,9,10};
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,sum1,(void*)arr);
pthread_create(&tid2,NULL,sum2,(void*)arr); 
pthread_join(tid1,NULL);  
pthread_join(tid2,NULL);
int c=a+b;
printf("sum of all elements of array is: %d",c);
return 0;
}
