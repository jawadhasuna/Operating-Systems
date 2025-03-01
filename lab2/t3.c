#include<stdio.h>
int main()
{
int sum=0;
printf("odd: \n");
for(int i=1;i<=10;i++)
{
if (i%2!=0)
{
printf("%d",i);
sum=sum+i;
}
}
printf("sum %d",sum);
return 0;
}
