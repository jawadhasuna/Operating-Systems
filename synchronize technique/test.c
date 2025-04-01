#include<pthread.h>
 bool lock=false;
bool testandset(bool* target)
{
bool* rv = *target;
*target=true;
return rv;
}
void* p0(void* arg)
{
do{
while(testandset(&lock))
{//busyloop}
//cs
lock=false;

}while(1);
}
void* p1(void* arg)
{
do{
while(testandset(&lock))
{//busyloop}
//cs
lock=false;
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
