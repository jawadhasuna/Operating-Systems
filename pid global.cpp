#include<iostream>
#include<unistd.h>
using namespace std;
int a=0;
int main()
{
int pid;
pid=fork();
if(pid==0)
{
a=5;
}
else
{
}
cout<<a<<endl;
return 0;
}
