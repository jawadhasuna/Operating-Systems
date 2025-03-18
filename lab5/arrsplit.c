#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int brr[10]={1,2,3,4,5,6,7,8,9,10};
int crr[10];
void* add(void* arg)
{
int start = *((int*)arg); 
for(int i=start;i<10;i=i+4)
{
crr[i]=arr[i]+brr[i];
}
return NULL;
}
int main()
{
pthread_t tid[4];
for(int i=0;i<4;i++)
{
int* index = (int*)malloc(sizeof(int));
*index=i;
pthread_create(&tid[i],NULL,add,index);
}
for(int i=0;i<4;i++)
{
pthread_join(tid[i],NULL);  
}
printf("sum of all elements of array is:\n");
for(int i=0;i<10;i=i+4)
{
printf("%d \n",crr[i]);
}
return 0;
}
