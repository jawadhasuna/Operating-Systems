include<pthread.h>
int count=0;
int flag[2];
int turn;
void* inc (void* arg)
{
do{
flag[0]=1;
turn==1;
while(flag[1]&&turn==1)
{//busyloop}
count++;
flag[0]=0;
}while(1);
}
void* dec (void* arg)
{
do{
flag[1]=1;
turn==0;
while(flag[0]&&turn==0)
{//busyloop}
count--;
flag[1]=0;
}while(1);
}
int main()
{
pthread_t p0,p1;
pthread_create(&p0,NULL,inc,NULL);
pthread_create(&p1,NULL,dec,NULL);
pthread_join();
pthread_join();


}
