#include<stdio.h>

int main()
{
int n=0,a=0,b=0;
float w=0,t=0;
printf("enter number of process:");
scanf("%d",&n);
int pid[n],wtime[n],ttime[n],atime[n],btime[n];
for(int i=0;i<n;i++)
{
pid[i]=i+1;
}
printf("enter each process arrival time:");
for(int i=0;i<n;i++)
{
scanf("%d",&a);
atime[i]=a;
}
printf("enter each process burst time:");
for(int i=0;i<n;i++)
{
scanf("%d",&b);
btime[i]=b;
}
printf("process\tarrival\tburst\n");
for(int i=0;i<n;i++)
{
printf("%d\t%d\t%d\n",pid[i],atime[i],btime[i]);
}
for(int i=1;i<n-1;i++)
{
for(int j=1;j<n;j++)
{
if(btime[j]>btime[j+1])
{
int temp=btime[j];
btime[j]=btime[j+1];
btime[j+1]=temp;
temp=pid[j];
pid[j]=pid[j+1];
pid[j+1]=temp;
}
}
}
wtime[0]=0;
for(int i=1;i<n;i++)
{
wtime[i]=wtime[i-1]+btime[i-1];
}

for(int i=0;i<n;i++)
{
ttime[i]=btime[i]+wtime[i];
}
printf("process\tburst\twait\tturnar\n");
for(int i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\n",pid[i],btime[i],wtime[i],ttime[i]);
}

for(int i=0;i<n;i++)
{
w=w+wtime[i];
}
w=w/3;
printf("average waiting time:%fms\n",w);
for(int i=0;i<n;i++)
{
t=t+ttime[i];
}
t=t/3;
printf("average turnaround  time:%fms\n",t);

return 0;
}
