#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
int a[10];
cout<<"square:"<<endl;
for(int i=0;i<10;i++)
{
a[i]=i*i;
cout<<a[i]<<endl;
}
return 0;
}
