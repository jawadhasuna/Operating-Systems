#include<iostream>
#include<unistd.h>
using namespace std;
int arr[100];
void counteven()
{
int even=0;
for(int i=0;i<100;i++)
{
if(arr[i]%2==0)
{
even++;
}
}
cout<<"even:"<<even<<endl;
}
void countodd()
{
int odd=0;
for(int i=0;i<100;i++)
{
if(arr[i]%2!=0)
{
odd++;
}
}
cout<<"odd:"<<odd<<endl;
}

int main()
{
int pid;
for(int i=0;i<100;i++)
{
arr[i]=i+1;
}
pid=fork();
if(pid== 0)
{
execlp("/home/ubuntu/Desktop/sq","sq",NULL);

counteven();
}
else
{
countodd();
}
return 0;
}

