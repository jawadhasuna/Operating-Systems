#include<stdio.h>
#include<pthread.h>
int a=0,b=0,c=0;
int arr[10]={1,2,3,4,5,6,7,8,9,10};
void* sum1(void* arg)
{
for(int i=0;i<=4;i++)
{
a=a+arr[i];
}
return NULL;
}
void* sum2(void* arg)
{
for(int i=5;i<=9;i++)
{
b=b+arr[i];
}
return NULL;
}
int main()
{
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,sum1,NULL);
pthread_create(&tid2,NULL,sum2,NULL); 
pthread_join(tid1,NULL);  
pthread_join(tid2,NULL);
c=a+b;
printf("sum of all elements of array is: %d",c);
return 0;
}
