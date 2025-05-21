#include<stdio.h>
int A=10,B=5,C=7;
int main()
{
int a=0,b=0,c=0;
int allocated[5][3]={
{0,1,0},
{2,0,0},
{3,0,2},
{2,1,1},
{0,0,2}};
int max[5][3]={
{7,5,3},
{3,2,2},
{9,0,2},
{2,2,2},
{4,3,3}};
int need[5][3];
for(int i=0;i<5;i++)
{
for(int j=0;j<3;j++)
{
need[i][j]=max[i][j]-allocated[i][j];
}
}
for(int i=0;i<5;i++)
{
for(int j=0;j<3;j++)
{
printf("%d ",need[i][j]);
}
printf("\n");
}

for(int i=0;i<5;i++)
{
a=a+allocated[i][0];
}
for(int i=0;i<5;i++)
{
b=b+allocated[i][1];
}
for(int i=0;i<5;i++)
{
c=c+allocated[i][2];
}
printf("allocated: %d, %d ,%d\n",a,b,c);
a=A-a;
b=B-b;
c=C-c;
printf("available: %d, %d ,%d\n",a,b,c);
return 0;
}
