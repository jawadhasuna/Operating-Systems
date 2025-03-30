#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int arr[1000];//SMALL
int brr[1000];//BIG
int a[2]={0,500};
int b[2]={500,1000};
void* split(void* arg)
{
int* crr=(int*)arg;
int temp;
for(int i=crr[0];i<crr[1];i++)
{
if(arr[i]>brr[i])
{
temp=arr[i];
arr[i]=brr[i];
brr[i]=temp;
}
}

}
int main()
{
srand(time(NULL));
for(int i=0;i<1000;i++)
{
arr[i]=rand()%400;
brr[i]=rand()%200;
}
printf("before:\n");
for(int j=0;j<5;j++)
{
printf("arr:%d\n",arr[j]);
printf("brr:%d\n",brr[j]);
}
pthread_t p1,p2;
pthread_create(&p1,NULL,split,a);
pthread_create(&p2,NULL,split,b);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
printf("after:\n");
for(int j=0;j<5;j++)
{
printf("arr:%d\n",arr[j]);
printf("brr:%d\n",brr[j]);
}
return 0;
}
