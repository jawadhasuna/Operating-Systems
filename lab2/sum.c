#include<stdio.h>
int add(int,int);
int main()
{
int  num1=10 , num2=5;
int s=add(num1,num2);
printf("sum is %d",s);
return 0;
}
int add(int a,int b)
{
int c=a+b;

return c;}
