#include <pthread.h>
#include <stdio.h>
typedef struct {
    int a;
    int b;
    char *message;
}ThreadArgs;
void *print_message(void *arg) 
{
    ThreadArgs* args = (ThreadArgs *)arg; 
    int result;
    if (args->a == 10 && args->b == 10) {
        result = args->a + args->b;
        printf("%s: a + b = %d\n", args->message, result);
    } 
     else {
        result = args->a - args->b;
        printf("%s: a - b = %d\n", args->message, result);
    }
    return NULL;
}
int main() {
    pthread_t thread1, thread2;
    ThreadArgs args1,args2;
    args1.a = 10;
    args1.b = 10;
    args1.message = "Hello from Thread 1";
    args2.a = 15;
    args2.b = 5;
    args2.message = "Hello from Thread 2";
    pthread_create(&thread1, NULL, print_message, (void *)&args1);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, print_message, (void *)&args2);
    pthread_join(thread2, NULL);
    return 0;
}
