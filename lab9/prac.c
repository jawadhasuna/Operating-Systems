#include<stdio.h>
int main()
{
int n;
printf("enter process:");
scanf("%d",&n);
int wait[n],burst[n],turn[n];
wait[0]=0;
printf("enter burst time for each process:");
for(int i=0;i<n;i++)
{
scanf("%d",&burst[i]);
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
printf("%d\t%d\t%d\t%d\n",i+1,burst[i],wait[i],turn[i]);
}
return 0;
}
