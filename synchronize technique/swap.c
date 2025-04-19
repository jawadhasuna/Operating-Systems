#include<pthread.h>
 bool lock=false;
void swap(bool* a,bool* b)
{
bool tmp = *a;
*a=*b;
*b=tmp;
}
void* p0(void* arg)
{bool key;
do{key=true;
while(key==true)
{//busyloop
swap(&key,&lock);
}
//cs
lock=false;

}while(1);
}
void* p1(void* arg)
{bool key;
do{key=true;
while(key==true)
{//busyloop
swap(&key,&lock);
}
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
