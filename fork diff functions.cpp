#include<iostream>
#include<unistd.h>
using namespace std;
void funca()
{
while(1)
{cout<<1<<endl;
}
}
void funcb()
{
while(1)
{
cout<<2<<endl;
}

}
int main()
{
int pid;
pid=fork();
if(pid==0)
{
funca();
}
else
{
funcb();
}
return 0;
}
