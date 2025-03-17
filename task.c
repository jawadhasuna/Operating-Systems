#include <pthread.h>
#include <stdio.h>
// Struct to hold arguments for the thread function
typedef struct {
    int a;
    int b;
    char *message;
} ThreadArgs;
void *print_message(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg; // Cast the argument to ThreadArgs struct
    int result;
    if (args->a == 10 && args->b == 10) {
        result = args->a + args->b;
        printf("%s: a + b = %d\n", args->message, result);
    } else {
        result = args->a - args->b;
        printf("%s: a - b = %d\n", args->message, result);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2; // Thread identifiers

    ThreadArgs args1;
    args1.a = 10;
    args1.b = 10;
    args1.message = "Hello from Thread 1";

    ThreadArgs args2;
    args2.a = 15;
    args2.b = 5;
    args2.message = "Hello from Thread 2";
    pthread_create(&thread1, NULL, print_message, (void *)&args1);
    pthread_join(thread1, NULL); // Wait for thread 1 to finish

    pthread_create(&thread2, NULL, print_message, (void *)&args2);
    pthread_join(thread2, NULL); // Wait for thread 2 to finish
    return 0;
}
