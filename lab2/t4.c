#include<stdio.h>
void grade()
{
int a[4],sum=0;
printf("enter marks 4 sub: \n");
for(int i=0;i<4;i++)
{
scanf("%d",&a[i]);
sum=sum+a[i];
}
sum=sum/4;
if(sum>90)
{printf("A \n");
}
else if(sum>80)
{printf("B \n");
}
else if(sum>70)
{printf("c \n");
}
else
{printf("F \n");
}
}
int main()
{

grade();


return 0;
}
