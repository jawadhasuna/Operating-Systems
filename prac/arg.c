#include<stdio.h>
int main(int argc,char* argv[])
{
if(argc==1)
{
printf("no arg passed");
}
else if(argc==2)
{
printf("arg1 %s, arg2 %s \n",argv[0],argv[1]);
}
else if(argc>2)
{
printf("too many");
}
return 0;
}
