#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
int pid;
pid=fork();
if(pid==0)
{
while(1)
{cout<<1<<endl;
}
}
else
{
while(1)
{
cout<<2<<endl;
}
}
return 0;
}
