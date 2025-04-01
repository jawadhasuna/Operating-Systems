#include<pthread.h>
 bool lock=false;
 int s=1;
void* p0(void* arg)
{
do{
while(s);
//cs
signal(s);
}while(1);
}
void* p1(void* arg)
{
do{
while(s)
//cs
signal(s);
}while(1);
}
int main()
{
pthread_t pa,pb;
pthread_create(&pa,NULL,p0,NULL);
pthread_create(&pb,NULL,p1,NULL);
pthread_join(pa,NULL);
pthread_join(pb,NULL);
}
