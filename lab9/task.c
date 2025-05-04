#include<stdio.h>
int main()
{
int n;
printf("enter no. of process:");
scanf("%d",&n);
int bursttime[n],waittime[n],turnarnd[n];
printf("enter burst time for each process :\n");
for(int i=0;i<n;i++)
{
printf("process %d \n",i+1);
scanf("%d",&bursttime[i]);
}
waittime[0]=0;
for(int i=1;i<n;i++)
{
waittime[i]=waittime[i-1]+bursttime[i-1];
}
for(int i=0;i<n;i++)
{
turnarnd[i]=waittime[i]+bursttime[i];
}
printf("process\tsub\tburst\twait\tturn around\n");
for(int i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t%d\n",i+1,i,bursttime[i],waittime[i],turnarnd[i]);
}
return 0;
}
