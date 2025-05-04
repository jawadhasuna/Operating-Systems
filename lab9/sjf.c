#include<stdio.h>
int main()
{
int n;
printf("enter process:");
scanf("%d",&n);
int wait[n],burst[n],turn[n],pid[n];
wait[0]=0;
printf("enter burst time for each process:");
for(int i=0;i<n;i++)
{
scanf("%d",&burst[i]);
pid[i]=i+1;
}
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-1-i;j++)
{
if(burst[j]>burst[j+1])
{
int temp=burst[j];
burst[j]=burst[j+1];
burst[j+1]=temp;
temp=pid[j];
pid[j]=pid[j+1];
pid[j+1]=temp;
}
}
}
for(int i=1;i<n;i++)
{
wait[i]=wait[i-1]+burst[i-1];
}
for(int i=0;i<n;i++)
{
turn[i]=wait[i]+burst[i];
}
printf("process\tburst\twait\tturn\n");
for(int i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\n",pid[i],burst[i],wait[i],turn[i]);
}
return 0;
}
